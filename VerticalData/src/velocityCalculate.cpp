#include "../includes/velocityCalculate.hpp"

using namespace cv;
using namespace std;

#define PIXEL_SIZE 0.0016

//camera settings
//double cameraElevation;	//meters above ground
double cameraAngleWidth = 65;	//degrees of field of view
//double pixelHeight; //pixel_height = 2*h*tan(camera_angle_width*pi/180/2)/number_pixels;
int linearPixelAverage = 2; //take a 2x2 pixel average of original image
int rowsToCalc = 140;
int colsToCalc = 140;

//int frameRate, frameCount;

//attitude
//double pitch;
//double roll;
//angular velocitys
//double wPitch;
//double wRoll;
//double Vx,Vy,Vz;	//velocities
//double speed, actualSpeed;


//scaling factor to correct velocity
double scaleFactor = 1.2645;	//found by trial and error
double attitudeScaleFactor = 1.14;

/*TESTING
//sensor noise
double elevationNoise, VzNoise, rollNoise, pitchNoise, wRollNoise, wPitchNoise;
*/

bool below1m = true;	//used for switching confidence factor algorithm, with 1m being the cutoff

int videoNum =1;
string videos[30] =
{
		"otherSims/test3_sand_slow_60.mp4",					//0
		"otherSims/pitch_roll_0to30tominus30to0_60.mp4",	//1
		"6_2_1/sim_6_2_1_2_120fps.mp4",		//2
		"6_2_1/sim_6_2_1_3_60fps.mp4",		//3
		"6_2_2/sim_6_2_2_1_60fps.mp4",		//4
		"6_2_2/sim_6_2_2_2_60fps.mp4",		//5
		"6_2_2/sim_6_2_2_3_60fps.mp4",		//6
		"6_2_2/sim_6_2_2_4_60fps.mp4",		//7
		"6_2_2/sim_6_2_2_5_60fps.mp4",		//8
		"6_2_2/sim_6_2_2_6_60fps.mp4",		//9
		"6_2_2/sim_6_2_2_7_60fps.mp4",		//10
		"6_2_2/sim_6_2_2_8_60fps.mp4",		//11
		"6_2_4/sim_6_2_4_1_60fps.mp4",		//12
		"6_2_4/sim_6_2_4_2_60fps.mp4",		//13
		"6_2_5/sim_6_2_5_3_60fps.mp4",		//14
		"6_2_5/sim_6_2_5_4_60fps.mp4",		//15
		"6_2_6/sim_6_2_6_1_60fps.mp4",		//16
		"6_2_6/sim_6_2_6_2_60fps.mp4",		//17
		"6_2_7/sim_6_2_7_1_60fps.mp4",		//18
		"6_2_7/sim_6_2_7_2_60fps.mp4",		//19
		"6_2_7/sim_6_2_7_3_60fps.mp4",		//20
		"6_2_7/sim_6_2_7_4_60fps.mp4",		//21
		"6_2_7/sim_6_2_7_5_60fps.mp4",		//22
		"6_2_7/sim_6_2_7_6_60fps.mp4",		//23
		"6_2_7/sim_6_2_7_7_60fps.mp4",		//24
		"6_2_7/sim_6_2_7_8_60fps.mp4"		//25
};

/*
 * test_3_sand_slow_60
 * 0 to 120 rising to height = 5
 * 120 to 360 moving Vy = 1 Vx = 0
 * 360 to 480 rotating
 * 480 tl 600 moving Vy = 2 Vx = 0
 * 600 to 720 lowering
 */
/*
 * pitch_roll_0to30tominus30to0_60
 * 4 seconds, 60fps
 * 0 to 59, pitch 0 to 30 degrees
 */

void fourPixelAverage(InputArray imgFull, OutputArray imgReduced){
	Size inputSize = imgFull.size();
	int rows = inputSize.height;
	int cols = inputSize.width;

	Mat input = imgFull.getMat();
	Mat_<uchar> output(rows/2,cols/2);

	int i,j;
	for(i=0;i<rows;i=i+2){
		for(j=0;j<cols;j=j+2){
			output(i/2,j/2) = (input.at<uchar>(i,j) + input.at<uchar>(i,j+1) + input.at<uchar>(i+1,j) + input.at<uchar>(i+1,j+1))/4;
		}
	}

	output.copyTo(imgReduced);
}

/* TESTING ******************************
void setSimulationParameters(int currentFrame){
	switch (videoNum)
	{
	case 0:
		//test3_sand_slow_60.mp4
		cameraElevation = 5 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		pitch = 0;
		wPitch = 0;
		wRoll = 0;
		Vz = 0;
		actualSpeed = 0;
		break;
	case 1:
		//pitch_roll_0to30tominus30to0_60.mp4
		if (currentFrame < frameRate){
			wPitch = 30*M_PI/180;
			pitch = 30*currentFrame/frameRate*M_PI/180;
		}else if(currentFrame < 3*frameRate){
			wPitch = -30*M_PI/180;
			pitch = (30-30*(currentFrame-60)/frameRate)*M_PI/180;
		}else{
			wPitch = 30*M_PI/180;
			pitch = (-30+30*(currentFrame-180)/frameRate)*M_PI/180;
		}
		cameraElevation = 3 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		Vz = 0;
		actualSpeed = 0;
		break;
	case 2:
		cameraElevation = 5 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 6;
		break;
	case 3:
		cameraElevation = 1 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 1;
		break;
	case 4:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 5:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 6:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 7:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 8:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 9:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 10:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 11:
		cameraElevation = 10 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 12;
		break;
	case 12:
		cameraElevation = 1 + 9*(double)currentFrame/180  + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 3;
		actualSpeed = 6.708;
		break;
	case 13:
		cameraElevation = 10 - 9*(double)currentFrame/180 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = -3;
		actualSpeed = 6.708;
		break;
	case 14:
		cameraElevation = 5 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 6;
		break;
	case 15:
		cameraElevation = 5 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 6;
		break;
	case 16:
		cameraElevation = 1 + 9*(double)currentFrame/180 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 3;
		actualSpeed = 5;
		break;
	case 17:
		cameraElevation = 10 - 9*(double)currentFrame/180 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = -3;
		actualSpeed = 5;
		break;
	case 18:
		cameraElevation = 3 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 19:
		cameraElevation = 3 + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		roll = 0;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 20:
		roll = 10*M_PI/180;
		cameraElevation = 3/cos(roll) + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 21:
		roll = -10*M_PI/180;
		cameraElevation = 3/cos(roll) + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		wRoll = 0;
		pitch = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 22:
		roll = 0;
		pitch = 10*M_PI/180;
		cameraElevation = 3/cos(pitch) + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		wRoll = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 23:
		roll = 0;
		pitch = -10*M_PI/180;
		cameraElevation = 3/cos(pitch) + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		wRoll = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 24:
		roll = 10*M_PI/180;
		pitch = 0;
		cameraElevation = 3/cos(roll) + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		wRoll = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	case 25:
		roll = -10*M_PI/180;
		pitch = 0;
		cameraElevation = 3/cos(roll) + elevationNoise;
		pixelHeight = cameraElevation*0.002;
		wRoll = 0;
		wPitch = 0;
		Vz = 0;
		actualSpeed = 4;
		break;
	}



}
*/

//////////////////////////////////////////////////////////
//ENTROPY CALCULATIONS
/*******************************************************/
float entropy(Mat seq, Size size, int index)
{
	int cnt = 0;
	float entr = 0;
	float total_size = size.height * size.width; //total size of all symbols in an image

	for(int i=0;i<index;i++)
	{
		float sym_occur = seq.at<float>(0, i); //the number of times a sybmol has occured
		if(sym_occur>0) //log of zero goes to infinity
		{
			cnt++;
			entr += (sym_occur/total_size)*(log2(total_size/sym_occur));
		}
	}
	//cout<<"cnt: "<<cnt<<endl;
	return entr;

}

// myEntropy calculates relative occurrence of different symbols within given input sequence using histogram
Mat myEntropy(Mat seq, int histSize)
{

	float range[] = { 0, 256 } ;
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat hist;

	/// Compute the histograms:
	calcHist( &seq, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate );

	return hist;
}
//////// END ENTROPY CALCULATIONS ///////////////////////////

void calculateAEAO(Mat prevGray, Mat nextGray, double cameraElevation,int frameRate, double pitch, double roll, double wPitch, double wRoll, double &Vx, double &Vy, double &Vz, double &speed, double &direction  )
{
	double groundSensorDistance = cameraElevation*sqrt(pow(tan(abs(pitch)),2)+pow(tan(abs(roll)),2)+1);
	double pixelHeight =groundSensorDistance * PIXEL_SIZE;
	//Get video from file
//	VideoCapture capture(videos[videoNum]);

	//We need to know the frame rate. Maybe just set to 120 for now?

	/***** TESTING ************
	frameRate = capture.get(CV_CAP_PROP_FPS);	//get frame rate
	frameCount = capture.get(CV_CAP_PROP_FRAME_COUNT);	//number of frames
	*************************/

	//This is to play the video
//	namedWindow("Video",1);
	//resizeWindow("Video",512*2,384*2);


	//video frames
	//Mat prevFrame, nextFrame, 
	//Mat prevGray, nextGray;
	Mat reducedPrevGray, reducedNextGray;	//2x2 pixel average of original images

	/*
	 * Devon, use prevFrame and nextFrame as inputs for video frames if they are colour
	 * If they are grayscale already, use prevGray and nextGray and comment out the lines below
	 * that convert the images to grayscale
	 */

	//capture.set(1,400);		//set video to frame 200

	/* TESTING ****************
	//read two consecutive frames
	capture >> nextFrame;
	imshow("Video",nextFrame);
	***********************/

	/* TESTING***************
	//sensor noise
	default_random_engine generator;
	normal_distribution<double> elevation_distribution(0,0.015);
	normal_distribution<double> attitude_distribution(0,0.5);
	normal_distribution<double> gyro_distribution(0,3);
	**************************/

	//////////////////////////////////////////////////////////
	//LOOP THROUGH VIDEO FRAMES
	/*******************************************************/
//	double allErrors[frameCount-1];
//	double allConfidence[frameCount-1];



	int i,j;//,k;
//	for(k=0;k<frameCount-1;k++){

		/* TESTING **********************************
		//sensor noise
		double elevationNoise = elevation_distribution(generator);
		double VzNoise = elevation_distribution(generator);
		double rollNoise = attitude_distribution(generator)*M_PI/180;
		double pitchNoise = attitude_distribution(generator)*M_PI/180;
		double wRollNoise = gyro_distribution(generator)*M_PI/180;
		double wPitchNoise= gyro_distribution(generator)*M_PI/180;
		*******************************************/

		// wRollNoise = 0;
		//wPitchNoise = 0;

		//get sensor simulated values
//		setSimulationParameters(k);

/* TESTING
		//incriment video frame
		nextFrame.copyTo(prevFrame);
		capture >> nextFrame;
*/
		//COMMENT THIS OUT IF THE FRAMES YOU SEND ARE ALREADY GRAYSCALE
		//convert frames to grayscale
		//cvtColor(prevFrame, prevGray, COLOR_BGR2GRAY);
		//cvtColor(nextFrame, nextGray, COLOR_BGR2GRAY);

		//take a 4 pixel average of each frame
		fourPixelAverage(prevGray, reducedPrevGray);
		fourPixelAverage(nextGray, reducedNextGray);

		////////////////////////////////////////////////////////////////
		//fill what points to calculate optical flow on
		//will be a box in center of image with dimensions rowsToCalc BY colsToCalc
		/***************************************************************/
		vector<Point2f> prevPts;
		vector<Point2f> nextPts;
		Point2f tempPoint;
		int imRows = reducedPrevGray.rows;	//should be the same as reducedNectGray
		int imCols = reducedPrevGray.cols;
		int rowStart = (imRows-rowsToCalc)/2;
		int rowEnd = rowStart + rowsToCalc;
		int colStart = (imCols-colsToCalc)/2;
		int colEnd = colStart + colsToCalc;


		for (i=(rowStart-1);i<(rowEnd);i++){
			for (j=(colStart-1);j<(colEnd);j++){
				tempPoint = Point2f((float)(j),(float)(i));
				prevPts.push_back(tempPoint);
			}
		}


		////////////////////////////////////////////////////////////////
		// OPTICAL FLOW AND VELOCITY CALCULATIONS
		/**************************************************************/

		vector<Mat> prevPyr, nextPyr;
		Size winSize(5,5);
		vector<uchar> status;
		vector<float> err;
		TermCriteria termcrit(TermCriteria::COUNT|TermCriteria::EPS,20,0.03);
		//int prevLevels = buildOpticalFlowPyramid(reducedPrevGray,prevPyr,winSize,2);//,true,1,1,true);
		buildOpticalFlowPyramid(reducedPrevGray,prevPyr,winSize,2);

		//int nextLevels = buildOpticalFlowPyramid(reducedNextGray,nextPyr,winSize,2);//,true,1,1,true);
		buildOpticalFlowPyramid(reducedNextGray,nextPyr,winSize,2);
		calcOpticalFlowPyrLK(prevPyr, nextPyr, prevPts, nextPts, status, err, winSize, 3, termcrit, 0, 0.001);

		Scalar vels;
		vector<Point2f> distance;

		//find distance moved between frames
		subtract(nextPts,prevPts,distance);

		//average of x and y displacment
		vels = mean(distance);

		//velocity correction for attitude changes
		double correction[2];
//		correction[1] = (Vz+VzNoise)*tan(pitch + pitchNoise) + (cameraElevation+elevationNoise)*(wPitch+wPitchNoise)*2/(cos(2*(pitch+pitchNoise))+1);	//Vx correction
//		correction[0] = (Vz+VzNoise)*tan(roll + rollNoise) + (cameraElevation+elevationNoise)*(wRoll+wRollNoise)*2/(cos(2*(roll+rollNoise))+1);		//Vy correction

		correction[1] = (Vz)*tan(pitch) + (cameraElevation)*(wPitch)*2/(cos(2*(pitch))+1);	//Vx correction
		correction[0] = (Vz)*tan(roll) + (cameraElevation)*(wRoll)*2/(cos(2*(roll))+1);		//Vy correction


		//calculate final velocities
		Vx = -(vels[0]+correction[0]*attitudeScaleFactor)*pixelHeight*scaleFactor*linearPixelAverage*frameRate;
		Vy = (vels[1]+correction[1]*attitudeScaleFactor)*pixelHeight*scaleFactor*linearPixelAverage*frameRate;
//		speed = sqrt(Vx*Vx+Vy*Vy+(Vz+VzNoise)*(Vz+VzNoise));
		speed = sqrt(Vx*Vx+Vy*Vy+(Vz)*(Vz));

		//////////////////////////////////////////////////////////////////
		// CONFIDENCE FACTOR
		/**************************************************************/
		double entCon, heightCon, attCon, angAttCon;//individual confidence factors
		double confidenceFactor;

		//ENTROPY CALCULATION
		Mat src, hist;
		src = reducedNextGray;
		int histSize = 256;

		hist = myEntropy(src, histSize);
		double ent = entropy(hist,src.size(), histSize);

		//ENTROPY CONFIDENCE
		entCon = exp(pow(ent,3.5/2)/20)-1;
		if (entCon>1) entCon = 1;

		//HEIGHT CONFIDENCE
		//switch equation based on height
//		if (cameraElevation + elevationNoise<1) below1m = true;
//		else if (cameraElevation + elevationNoise>1.2) below1m = false;
		if (cameraElevation<1) below1m = true;
		else below1m = false;

//		if (below1m) heightCon = exp(pow(cameraElevation + elevationNoise,2)-1)/(speed+0.1)*3;
//		else heightCon = exp(-pow(cameraElevation + elevationNoise -1,3)/100);
//		if (heightCon>1) heightCon = 1;

		if (below1m) heightCon = exp(pow(cameraElevation,2)-1)/(speed+0.1)*3;
		else heightCon = exp(-pow(cameraElevation -1,3)/100);
		if (heightCon>1) heightCon = 1;

		//PITCH AND ROLL CONFIDENCE
//		attCon = exp(-pow((abs(pitch+pitchNoise)+abs(roll+rollNoise))*1.5,3));	//pitch and roll in radians
		attCon = exp(-pow((abs(pitch)+abs(roll))*1.5,3));	//pitch and roll in radians

		//ANGULAR VELOCITY CONFIDENCE
//		angAttCon = exp(-pow((abs(wPitch+wPitchNoise)+abs(wRoll+wRollNoise))/5,3));
		angAttCon = exp(-pow((abs(wPitch)+abs(wRoll))/5,3));

		//confidence for huge vertical acceleration will be added in higher lever module

		//CONFIDENCE FACTOR
		confidenceFactor = entCon*heightCon*attCon*angAttCon;

		// END CONFIDENCE FACTOR ////////////////////////////////////////

		/* TESTING ******************************
		//error in speed;
		double speedError;
		if (actualSpeed < 0.001) speedError = 100;
		else speedError = abs(speed-actualSpeed)/actualSpeed*100;
		**************************************/
		
		// Direction Calculation
		direction = atan2(Vx,Vy);	//radians with straight y being 0 and -y being pi. Straight x is pi/2 and -x is -pi/2

		////////////////////////////////////////////////////////
		//Display results
		/*****************************************************/
	//	cout << "Frame " << right << setw(4) << k << " to " << right << setw(4) << k+1 << "\t";

		cout << "Vx =  ";
		if (Vx < 0) cout << "-" 		<< fixed << setw(6) << setprecision(3) << -Vx;
		else cout << " " 				<< fixed << setw(6) << setprecision(3) << Vx;

		cout << "   Vy =  ";
		if (Vy < 0) cout << "-" 		<< fixed << setw(6) << setprecision(3) << -Vy;
		else cout << " " 				<< fixed << setw(6) << setprecision(3) << Vy;

		cout << "   speed =  "			<< fixed << setw(6) << setprecision(3) << speed;
//		cout << "   SpeedError = " 		<< right << setw(6) << setprecision(2) << speedError << "%";
		cout << "   height =  " 		<< fixed << setw(6) << setprecision(3) << cameraElevation;// + elevationNoise;
		cout << "   entropy =  " 		<< fixed << setw(6) << setprecision(3) << ent;

		//confidence
		cout << "   Confidence = " 		<< fixed << setw(6) << setprecision(3) << confidenceFactor;

		//direction
		cout << "  Direction = " << direction << endl;

		////////////////////////////////////////////////////////////////
		//PLAY VIDEO
		/***************************************************************/
/*
		imshow("Video",nextFrame);
		if(waitKey(15) == 27) //wait for 'esc' key press for 15 ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
		imshow("Video",nextFrame);
*/

//		allErrors[k] = speedError;
//		allConfidence[k] = confidenceFactor;

//	}//end of for loop going through whole video

	/* TESTING ************************8
	//Spit out error and confidence that I want
	cout << endl << endl;
	double sumError = 0; double sumConfidence = 0;

	cout << "Error:" << endl;
	for (i=0;i<frameCount-1;i++){
		//cout << allErrors[i] << endl;
		sumError = sumError + allErrors[i];
	}
	cout << endl << sumError/(frameCount-1) << endl;
	cout << endl << "Confidence:" << endl;
	for (i=0;i<frameCount-1;i++){
			cout << allConfidence[i] << endl;
		sumConfidence = sumConfidence + allConfidence[i];
		}
	cout << endl << sumConfidence/(frameCount-1) << endl;
**************************************/


	//waitKey(0); // key press to close window
	// releases and window destroy are automatic in C++ interface
}
