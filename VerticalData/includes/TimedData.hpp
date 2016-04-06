// include guard to prevent double inclusion
/*
 * @author Devon Haubold
 * @brief Store data with a timestamp
 */
#ifndef __TIMEDDATA_H_INCLUDED__
#define __TIMEDDATA_H_INCLUDED__

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

/************************************************************/

/** Store TimedData data and time-stamp
 *
 */
class TimedData {
public:

	/**Construct an empty TimedData object
	 * @post an empty TimedData object is created
	 */
	TimedData();

	/**Construct a TimedData object with provided parameters
	 * @param[in] time the data was taken
	 * @param[in] data any data
	 * @post A TimedData object containing a TimedData reading and the corresponding time-stamp
	 */
	TimedData(float data, microseconds time);


	/**
	 * @return Data held in TimedData
	 */
	float getData();

	/**
	 * @return time of Data
	 */
	microseconds getTime();

	/**
	 *  @brief print contents of TimedData to console
	 */
	void printAll();

	/**Save TimedData object to file
	 * @param[in] filename name of file to be written
	 * @param[in] h pointer to the TimedData object being written
	 * @pre An existing TimedData object
	 * @post Object is saved to a binary file on disk
	 */
	void writeData(string filename, TimedData *h);

	/**read TimedData object from file
	 * @param[in] filename name of file to be read
	 * @param[in] h pointer to the TimedData object being read
	 * @pre A file containing at least one TimedData object stored in binary
	 * @pre A TimedData object to store the data from file
	 * @post A TimedData object containing data from the file being read
	 */
	void readData(string filename, TimedData *h);



	/**
	 * Destructor for TimedData object
	 */
	~TimedData(void);

protected:
	/**set time member
	*@param[in] t the timestamp of the data
	*@post time member is set to t
	*/
	void setTime(microseconds t);

	/**set Data member
	*@param[in] d the data
	*@post the Data member is set
	*/
	void setData(float d);

private:

	float data; /**< holds the data */

	microseconds time; /**< the timestamp of the data*/


};
/************************************************************
 End of TimedData class header
 ************************************************************/

#endif // __TIMEDDATA_H_INCLUDED__
