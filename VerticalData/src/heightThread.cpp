/*
 * heightThread.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: devon
 */
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ctime>

#include "../includes/Height.hpp"


using namespace std;
using namespace chrono;
using namespace this_thread;


/** Get height data every 0.1 seconds
 * @pre a thread has been created and id assigned
 * @pre the sensors have been initialized and are accessible
 * @param[in] threadid The id number of the thread being used
 * @post the thread has reported the height
 * @post a Height object has been saved to disk
 */

void heightReporting(bool *exit_flag)
{
	int count = 0;

	while(!(*exit_flag))
	{
		//set the start time of the funcion
		system_clock::time_point start = system_clock::now();

		//Create Height object with sensor data
		Height fastHeight(count,duration_cast<microseconds>(start.time_since_epoch()));
		//print fastHeights contents to console
		fastHeight.printAll();

		//fastHeight.writeHeight(to_string(count), &fastHeight);
		count++;
		//stop reporting for start time + 0.1 seconds
		this_thread::sleep_until(start + milliseconds(100));
	}
	cout<< "exit height reporting" << endl;
}

//Test timing of thread running aevery 0.1 seconds
void testHeightThread()
{
	bool exit_flag = false;
	//create thread for reporting height every 0.1 seconds
	thread one (heightReporting, &exit_flag);
	one.detach();
	for(int i = 0; i < 10; i++)
	{
		/**@todo interface with real sensor data
	 	 * @brief initialize Lidar and Barometer sensor
	 	 * @param I2C address
	 	 */

		//start time of loop

		system_clock::time_point start = system_clock::now();
		cout << "* "<< endl <<"starting new loop at time"<< duration_cast<microseconds>(start.time_since_epoch()).count() << endl << "*" << endl;
		cout << "slowHeight: "<< i << endl;
		Height slowHeight(i,duration_cast<microseconds>(start.time_since_epoch()));
		slowHeight.printAll();
		//wait until 1s has passed
		this_thread::sleep_until(start + milliseconds(1000));

	}

	exit_flag = true;

}


/*
int main()
{
	testHeightThread();
	//timeTest();
	return 0;
}
*/


