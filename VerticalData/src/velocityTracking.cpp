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
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ctime>

#include "../includes/Height.hpp"
#include "../includes/VerticalData.hpp"
#include "../includes/VelocityData.hpp"

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
		//stop reporting for start time + 0.1 seconds
		this_thread::sleep_until(start + milliseconds(100));
	}
	cout<< "exit height reporting" << endl;
}

//Test timing of thread running a every 0.1 seconds
void testMain()
{
	bool exit_flag = false;
	//Object that stores Height objects and calculates velocity
	VerticalData frequentHeight;
	//hold the calculated velocity for use in the next iteration

	double previousVelocity = 0;
	//create thread for reporting height every 0.1 seconds

	/**
	 * @todo initialize Sensors
	 */

	thread one (heightReporting,ref(frequentHeight) ,ref(exit_flag));
	one.detach();

	for(int i = 0; i < 10; i++)
	{

		//start time of loop

		system_clock::time_point start = system_clock::now();
		cout << "* "<< endl <<"starting new loop at time"<< duration_cast<microseconds>(start.time_since_epoch()).count() << endl << "*" << endl;
		cout << "Velocity Test: "<< i << " Previous Velocity: " << previousVelocity << endl;
		VelocityData vD;
		vD.setPreviousVelocity(previousVelocity);
		vD.printAll();
		//wait until 1s has passed
		this_thread::sleep_until(start + milliseconds(1000));

	}

	exit_flag = true;

}



int main()
{
	testMain();
	return 0;
}






