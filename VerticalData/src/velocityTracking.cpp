/**
 * @file velocityTracking.cpp
 *
 *  @date Mar 21, 2016
 *  @author: Devon Haubold
 *  @brief The main program, stores data and calculates velocities
 */


#include "../includes/Height.hpp"
#include "../includes/VerticalData.hpp"
//#include "../includes/VelocityData.hpp"
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

#define FRAME_RATE 90 /**< The frame rate that the camera is set at*/

using namespace std;
using namespace chrono;
using namespace this_thread;
using namespace cv;


/**
 * @post camera image format set to single channel 8 bit
 * @post gain set to maximum value
 * @param[in,out] Camera the camera interface
 */
void initializeCamera(raspicam::RaspiCam_Cv &Camera)
{
		Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1);
		Camera.set( CV_CAP_PROP_GAIN, 100);
	//	Camera.set( CV_CAP_PROP_CONTRAST, 55);
	//	Camera.set( CV_CAP_PROP_BRIGHTNESS, 50);
//		Camera.set( CV_CAP_PROP_EXPOSURE, 0);
//	cout << Camera.get(CV_CAP_PROP_FRAME_WIDTH) << ", " << Camera.get(CV_CAP_PROP_FRAME_HEIGHT) <<endl;
}

/**
 *
 * @brief capture two consecutive images at 90 frames per second, loops until exit_flag is true
 * @pre a thread has been created and id assigned
 * @param[in,out] image_1 the first image to be captured
 * @param[in,out] image_2 the second image to be captured
 * @param[in] exit_flag flag to alert thread to exit
 * @param[in,out] ready_flag to alert two images have been captured
 * @param[in,out] wait_flag flag to alert images are being used
 */
void twoImageCapture( Mat &image_1, Mat &image_2, bool &exit_flag, bool &ready_flag, bool &wait_flag)
{
	//create camera interface
	raspicam::RaspiCam_Cv Camera;
	//initialize the camera
	initializeCamera(Camera);
	
	//open camera
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

/** Get height data continuosly, calculate velocity
 * @pre a thread has been created and id assigned
 * @pre the sensors have been initialized and are accessible
 * @param[in] vertDataRef holds height data and calculates vertical velocity
 * @param[in] exit_flag flag to alert thread to exit
 * @param[in] lidar equals 1 if lidar is initialized
 */

void heightReporting(VerticalData &vertDataRef, bool &exit_flag, int lidar)
{
	//declare variables to store sensor data
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

/**
 * Declares input/output variables for sensor data
 * Declares variables for calculated values
 * Spawns threads using heightReporting and twoImageCapture
 * Calls velocityCalculate with sensor data and calculated value variables
 */
int main(int argc, char *argv[])
{
	//Alert threads of exit
	bool exit_flag = false; /* flag that ends all threads when true*/

	VerticalData frequentHeight; /* Object that calculates Vertical Velocity */

	bool wait_flag = false; /* flag to prevent camera from taking images */
	bool ready_flag = false; /* flag to alert that two consecutive images are ready*/
	Mat image_1; /* hold first image captured */
	Mat image_2; /* hold second image captured */

	// initialize the imu
	signal(SIGINT, INThandler);
	enableIMU();

	//Initialize the Lidar
	int lidar = lidar_init(false); /**< equals 1 if lidar initialized */
	//Create thread for reporting height
	thread one (heightReporting,ref(frequentHeight) ,ref(exit_flag), lidar);
	one.detach();
	//create thread for capturing images
	thread two (twoImageCapture,ref(image_1), ref(image_2), ref(exit_flag), ref(ready_flag), ref(wait_flag));
	two.detach();

	while(!exit_flag)
	{
		
		//start time of loop
		system_clock::time_point start = system_clock::now();
		
		//@todo remove cout for test
		//cout << "* "<< endl <<"starting new loop at time"<< duration_cast<microseconds>(start.time_since_epoch()).count() << endl << "*" << endl;
		//cout << "Velocity Test: "<< i << endl;
		
		//Sensor variables
		float gyr_x, gyr_y, acc_x, acc_y, t, l_c, h;
		long p, b_c;
		int l;
		//calculated variables
		double vx,vz, vy, spd, direction;
		
		
		// Aquire images
		
		Mat prevImg;
		Mat currImg;
		while(!ready_flag){}
		wait_flag = true;
		prevImg = image_1.clone();
		currImg = image_2.clone();
	//	cout << "picture taken" << endl;
		wait_flag = false;

		//Accuire pitch, roll and there respective velocities and heit
		MEGA_SENSOR(&gyr_x, &gyr_y, &acc_x, &acc_y, &t, &p, &l, &l_c, &b_c, &h, lidar);
		//Aquire Vertical Velocity
		vz = frequentHeight.getVelocity();
		
		//cv::imwrite("test_img1.jpg", prevImg);
		//cv::imwrite("test_img2.jpg", currImg);
		//cout << "height: " << h << "acc_y: " << acc_y << " acc_x: "<< acc_x << " gyr_x: " << gyr_x << " gyr_y: "<< gyr_y << endl;
//		cout<<"*************Beginning Velocity Calculation**************"<<endl;
		calculateAEAO( prevImg,currImg, h, FRAME_RATE, acc_y, acc_x, gyr_x, gyr_y, vx, vy, vz, spd, direction );

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

