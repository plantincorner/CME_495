// include guard to prevent double inclusion
#ifndef __TIMEDDATA_H_INCLUDED__
#define __TIMEDDATA_H_INCLUDED__

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

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

	/**
	 * @param[in] time the TimedData reading was taken
	 * @param[in] sensor TimedData reading
	 * @pre TimedData reading availabel
	 * @post A TimedData object containing a TimedData reading and the corresponding time-stamp
	 */
	TimedData(float /*in*/data, time_t /*in*/ time);


	/**
	 * 
	 */
	float getData();

	/**
	 * 
	 * @return time 
	 */
	time_t getTime();

	/**
	 *  print contents to console
	 */
	void printAll();

	/**Save TimedData object to file
	 * @param[in] filename name of file to be written
	 * @param[in] h pointer to the TimedData object being written
	 * @pre An existing TimedData object
	 * @post Object is saved to a binary file on disk
	 * @todo find a way to extract object location in memory from within itself
	 * @todo Test writing multiple objects to same file
	 */
	void writeData(string filename, TimedData *h);

	/**read TimedData object from file
	 * @param[in] filename name of file to be read
	 * @param[in] h pointer to the TimedData object being read
	 * @pre A file containing at least one TimedData object stored in binary
	 * @pre A TimedData object to store the data from file
	 * @post A TimedData object containing data from the file being read
	 * @todo find a way to extract object location in memory from within itself
	 * @todo Test reading multiple objects from the same file
	 */
	void readData(string filename, TimedData *h);

	/**
	 * Destructor for TimedData object
	 */
	~TimedData(void);

protected:
	/**
	*
	*/
	void setTime(time_t t);

	/**
	*
	*/
	void setData(float d);

private:
	/**
	 * 
	 */
	float data;
	/**
	 * 
	 */
	double time;


};
/************************************************************
 End of TimedData class header
 ************************************************************/

#endif // __TIMEDDATA_H_INCLUDED__
