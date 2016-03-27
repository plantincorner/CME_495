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


extern "C" {
#include "../includes/output.h"
#include "../includes/sensor.h"
#include "../includes/bmp180.h"
#include "../includes/lidarLite.h"
}

#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ctime>

#include <raspicam/raspicam_cv.h>


using namespace std;
using namespace chrono;
using namespace this_thread;
using namespace cv;


void twoImageCapture(Mat &image_1, Mat &image_2)
{
	
		raspicam::RaspiCam_Cv Camera;	
		Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1);
		Camera.set( CV_CAP_PROP_EXPOSURE, 8.3);
		Camera.set(CV_CAP_PROP_FRAME_WIDTH, 320);
		Camera.set(CV_CAP_PROP_FRAME_HEIGHT, 240);	
	cout << Camera.get(CV_CAP_PROP_FRAME_WIDTH) << ", " << Camera.get(CV_CAP_PROP_FRAME_HEIGHT) <<endl;
		if(!Camera.open())
			{
				cerr<<"Error" << endl;
			}
		else
			{
		
				system_clock::time_point start = system_clock::now();
				Camera.grab();
				Camera.retrieve(image_1);
		
				const auto loop_timer = duration_cast<milliseconds>(system_clock::now() - start).count();
				cout << "frame time: " << loop_timer << endl;
				Camera.grab();
				Camera.retrieve(image_2);
				
				const auto loop_timer_2 = duration_cast<milliseconds>(system_clock::now() - start).count() - loop_timer;
				cout << "frame time 2: " << loop_timer_2<< endl;
			}
		Camera.release();

	//	cv::imwrite("test_img.jpg", image);
}

/** Get height data every 0.1 seconds
 * @pre a thread has been created and id assigned
 * @pre the sensors have been initialized and are accessible
 * @param[in] threadid The id number of the thread being used
 * @post the thread has reported the height
 * @post a Height object has been saved to disk
 */

void heightReporting(VerticalData &vertDataRef, bool &exit_flag)
{
	int count = 0;
	cout << "Begin height reporting" << endl;
	while(!(exit_flag))
	{
		//set the start time of the funcion
		system_clock::time_point start = system_clock::now();

		//Create Height object with sensor data and store in a VerticalData object
		vertDataRef.placeHeight(count,duration_cast<microseconds>(start.time_since_epoch()));
		cout << "fast Height";
		vertDataRef.printAll();
		count++;

		const auto loop_timer = duration_cast<milliseconds>(system_clock::now() - start).count();
		cout << "height loop duration: " << loop_timer << endl;
		
		//stop reporting for start time + 0.1 seconds
		this_thread::sleep_until(start + milliseconds(100));
	}
	cout<< "exit height reporting" << endl;
}

//Test timing of thread running a every 0.1 seconds
void testMain()
{
	//Alert threads of exit
	bool exit_flag = false;

	//Object that stores Height objects and calculates velocity
	VerticalData frequentHeight;
	
	//hold the calculated velocity for use in the next iteration
	double previousVelocity = 0;

	/**
	 * @todo initialize Sensors
	 */

	Mat image;
	Mat image2;

	/*** initialize the imu***/
	signal(SIGINT, INThandler);
	enableIMU();

	/***Create thread for reporting height 10X per sec ***/
	thread one (heightReporting,ref(frequentHeight) ,ref(exit_flag));
	one.detach();

	for(int i = 0; i < 10; i++)
	{
		
		//start time of loop
		system_clock::time_point start = system_clock::now();


		/**temp storage variables for pitch and roll
		*gyr_x roll velocity
		*gyr_y pitch velocity
		*acc_x roll position
		*acc_y pitch position
		* @todo modify code so we don't have to use these ACCGYR to accept reference instead of pointers
		*/
		float gyr_x, gyr_y, acc_x, acc_y = 0;


		//@todo remove cout for test
		cout << "* "<< endl <<"starting new loop at time"<< duration_cast<microseconds>(start.time_since_epoch()).count() << endl << "*" << endl;
		cout << "Velocity Test: "<< i << " Previous Velocity: " << previousVelocity << endl;
		
		
		VelocityData vD;
		vD.setPreviousVelocity(previousVelocity);
		
		/**Accuire pitch, roll and there respective velocities**/
		ACCGYR( &gyr_x, &gyr_y, &acc_x, &acc_y);
		vD.setRollVelocity(gyr_x);
		vD.setPitchVelocity(gyr_y);
		vD.setRoll(acc_x);
		vD.setPitch(acc_y);

		/**Print results to console **/
		vD.printAll();
		
		/**@todo remove loop timer**/
		const auto loop_timer = duration_cast<milliseconds>(system_clock::now() - start).count();
		cout << "loop duration: " << loop_timer << endl;

		/**wait until 1s has passed to get velocity every second**/
		this_thread::sleep_until(start + milliseconds(1000));

	}

	exit_flag = true;

}



int main()
{
	Mat image_1;
	Mat image_2;
	twoImageCapture(image_1, image_2);
	return 0;
}






