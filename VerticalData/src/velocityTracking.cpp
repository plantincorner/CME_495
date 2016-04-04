/*
 * velocityTracking.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: devon
 */
/*
 * @todo implement time checking
 */
/*
 * heightThread.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: devon
 */
#include "../includes/Height.hpp"
#include "../includes/VerticalData.hpp"
#include "../includes/VelocityData.hpp"
#include "../includes/velocityCalculate.hpp"


extern "C" {
#include "../includes/output.h"
#include "../includes/sensor.h"
#include "../includes/bmp180.h"
#include "../includes/lidarLite.h"
#include "../includes/mega_sensor.h"
}

#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ctime>

#include <opencv2/highgui/highgui.hpp>
#include <raspicam/raspicam_cv.h>

#define FRAME_RATE 90

using namespace std;
using namespace chrono;
using namespace this_thread;
using namespace cv;

void initializeCamera(raspicam::RaspiCam_Cv &Camera)
{
		Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1);
		Camera.set( CV_CAP_PROP_GAIN, 100);
	//	Camera.set( CV_CAP_PROP_CONTRAST, 55);
	//	Camera.set( CV_CAP_PROP_BRIGHTNESS, 50);
//		Camera.set( CV_CAP_PROP_EXPOSURE, 0);
//	cout << Camera.get(CV_CAP_PROP_FRAME_WIDTH) << ", " << Camera.get(CV_CAP_PROP_FRAME_HEIGHT) <<endl;
}
void twoImageCapture( Mat &image_1, Mat &image_2, bool &exit_flag, bool &ready_flag, bool &wait_flag)
{
	
	raspicam::RaspiCam_Cv Camera;
	initializeCamera(Camera);
	
	if(!Camera.open())
	{
		cerr<<"Error: Camera not open" << endl;
	}

	while (!exit_flag)
	{	
//		system_clock::time_point start = system_clock::now();
		while(wait_flag){}	
		ready_flag = false;
		Camera.retrieve(image_1);
					
			//const auto loop_timer = duration_cast<milliseconds>(system_clock::now() - start).count();
//			cout << "frame time: " << loop_timer << endl;
		Camera.grab();
		Camera.retrieve(image_2);
		ready_flag = true;		
//		const auto loop_timer_2 = duration_cast<milliseconds>(system_clock::now() - start).count() ;
//				cout << "two frame time: " << loop_timer_2<< endl;
			
	}

	Camera.release();

}

/** Get height data every 0.1 seconds
 * @pre a thread has been created and id assigned
 * @pre the sensors have been initialized and are accessible
 * @param[in] threadid The id number of the thread being used
 * @post the thread has reported the height
 * @post a Height object has been saved to disk
 */

void heightReporting(VerticalData &vertDataRef, bool &exit_flag, int lidar)
{
		float gyr_x, gyr_y, acc_x, acc_y, t, l_c, h;
		long p, b_c;
		int l;
	
	while(!(exit_flag))
	{
	//	cout << "Begin height reporting" << "exit flag: " << exit_flag << endl;
		//set the start time of the funcion
		system_clock::time_point start = system_clock::now();

		//Create Height object with sensor data and store in a VerticalData object
		MEGA_SENSOR(&gyr_x, &gyr_y, &acc_x, &acc_y, &t, &p, &l, &l_c, &b_c, &h, lidar);
		
		vertDataRef.placeHeight(h,duration_cast<microseconds>(start.time_since_epoch()));
		
	//	if (heightOut_flag)
	//	{
//			cout << "Height: " << h << endl;

			const auto loop_timer = duration_cast<milliseconds>(system_clock::now() - start).count();
//		cout << "height loop duration: " << loop_timer << endl;
	//	}
		
		//stop reporting for start time + 0.1 seconds
		this_thread::sleep_until(start + milliseconds(100));
	}
	cout<< "exit height reporting" << endl;
}

//Test timing of thread running a every 0.1 seconds
int main(int argc, char *argv[])
{
	//Alert threads of exit
	bool exit_flag = false;

	//Object that stores Height objects and calculates velocity
	VerticalData frequentHeight;
//	bool heightOut_flag = true;
//	string heightOut = "noHeightOut";
//	if (argc > 1)
//	{
//	if(heightOut.compare(argv[1]) == 0)
//		{
//			cout << "Not reporting Height 10X per sec" << endl;
//			heightOut_flag = false;
//		}	

//	}
	//hold the calculated velocity for use in the next iteration
	//double previousVelocity = 0;// needed for calculating framerate

	/**
	 * @todo initialize Sensors
	 */
	
	// stop camera from taking images
	bool wait_flag = false;
	bool ready_flag = false;
	Mat image_1;
	Mat image_2;

	/*** initialize the imu***/
	signal(SIGINT, INThandler);
	enableIMU();

	/**Initialize the Lidar**/
	int lidar = lidar_init(false);
	/***Create thread for reporting height 10X per sec ***/
	thread one (heightReporting,ref(frequentHeight) ,ref(exit_flag), lidar);
	one.detach();

	thread two (twoImageCapture,ref(image_1), ref(image_2), ref(exit_flag), ref(ready_flag), ref(wait_flag));
	two.detach();
	for(int i = 0; i < 1000; i++)
	{
		
		//start time of loop
		system_clock::time_point start = system_clock::now();
		
		//@todo remove cout for test
		//cout << "* "<< endl <<"starting new loop at time"<< duration_cast<microseconds>(start.time_since_epoch()).count() << endl << "*" << endl;
		//cout << "Velocity Test: "<< i << endl;
		
		/**temp storage variables for pitch and roll
		*gyr_x roll velocity
		*gyr_y pitch velocity
		*acc_x roll position
		*acc_y pitch position
		* @todo modify code so we don't have to use these ACCGYR to accept reference instead of pointers
		*/
		float gyr_x, gyr_y, acc_x, acc_y, t, l_c, h;
		long p, b_c;
		int l;
		double vx,vz, vy, spd, direction;

		//VelocityData vD;
		//vD.setPreviousVelocity(previousVelocity);// needed for setting framerate
		
		
		/** Aquire images **/
		
		Mat prevImg;
		Mat currImg;
		while(!ready_flag){}
		wait_flag = true;
		prevImg = image_1.clone();
		currImg = image_2.clone();
	//	cout << "picture taken" << endl;
		wait_flag = false;

		/**Accuire pitch, roll and there respective velocities and heit**/
		MEGA_SENSOR(&gyr_x, &gyr_y, &acc_x, &acc_y, &t, &p, &l, &l_c, &b_c, &h, lidar);
		/**Aquire Vertical Velocity*/
		vz = frequentHeight.getVelocity();
		
	/**	Functions for setting data structure
		vD.setRollVelocity(gyr_x);
		vD.setPitchVelocity(gyr_y);
		vD.setRoll(acc_x);
		vD.setPitch(acc_y);
		
		vD.setVerticalVelocity(frequentHeight.getVelocity())
	*/
	//	vD.setImage_1(image_1);
	//	vD.setImage_2(image_2);
		/**Print results to console **/
//		vD.printAll();
		
		//cv::imwrite("test_img1.jpg", prevImg);
		//cv::imwrite("test_img2.jpg", currImg);
		//cout << "height: " << h << "acc_y: " << acc_y << " acc_x: "<< acc_x << " gyr_x: " << gyr_x << " gyr_y: "<< gyr_y << endl;
//		cout<<"*************Beginning Velocity Calculation**************"<<endl;
	//	calculateAEAO( prevImg,currImg, h, FRAME_RATE, acc_y, acc_x, gyr_x, gyr_y, vx, vy, vz, spd, direction );

		calculateAEAO( prevImg,currImg, 1, FRAME_RATE, acc_y, acc_x, gyr_x, gyr_y, vx, vy, 0, spd, direction );
//		cout<<"++++++++++++++End Hight Calculation+++++++++++++++++++"<<endl;
		/**@todo remove loop timer**/
		const auto loop_timer = duration_cast<milliseconds>(system_clock::now() - start).count();
//		cout << "main loop duration: " << loop_timer << endl;

		/**wait until 1s has passed to get velocity every second**/
//		sleep_until(start + milliseconds(1000));

	}

	exit_flag = true;
	return 0;
}

