/*
 * TimedDataTesting.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: devon
 */
#include "../includes/TimedData.hpp"


//instantiate empty TimedData object also tests getters and setters
void testEmpty()
{
	cout << "*\nBegin Testing Default TimedData Constructor \n*" << endl;
	cout << "creating empty TimedData object" <<endl ;
	TimedData emptyTimedData;
	cout << "empty TimedData contents" <<endl ;
	emptyTimedData.printAll();
	cout << "*\nEnd testing TimedData Constructor \n*" << endl;
}

//test construction with minimum values
void testMin()
{
	cout << "*\nBegin Testing TimedData Constructor with minimum expected values\n*" << endl;
	float lowerTimedData = 0;
	time_t lowerTime = 0;
	//test min values
	cout << "creating min TimedData object" <<endl ;
	TimedData minTimedData(lowerTimedData, lowerTime);
	cout << "min TimedData contents" <<endl ;
	minTimedData.printAll();
	cout << "*\nEnd testing TimedData Constructor \n*" << endl;
}


//test constructor with max values, use current time
void testMax()
{
	cout << "*\nBegin Testing TimedData Constructor with maximum expected values\n*" << endl;
	float upperTimedData = 120;
	//Maxtime does not exist
	cout << "creating empty max TimedData object" <<endl;
	TimedData maxTimedData(upperTimedData, time(NULL));
	cout << "max TimedData contents" <<endl ;
	maxTimedData.printAll();
	cout << "*\nEnd testing TimedData Constructor \n*" << endl;
}

//test writing a single TiemedData object to binary file then reading that object
void testWrite(string testFile, float testData)
{
	cout << "*\nBegin Testing TimedData::writeData and TimedData::readData with test data: " << testData << "\n*" << endl;
	TimedData maxTimedData(testData, time(NULL));
	TimedData emptyTimedData;
	cout << "write to file:";
	maxTimedData.printAll();
	maxTimedData.writeData(testFile,&maxTimedData);
	cout << "read from file"<< endl;
	emptyTimedData.readData(testFile, &emptyTimedData);
	emptyTimedData.printAll();
	cout << "*\nEnd testing TimedData write and read\n*" << endl;
}

//test creating objects with random data
void testRandom()
{
	cout << "*\nBegin Testing TimedData Constructor with Random data values\n*" << endl;
	bool testStatus = false;
	float randomTimedData;
	time_t randomTestTime;
	for(int i=0; i<10000; i++)
	{
		srand(time(NULL) + i);
		randomTimedData = ((float)rand()/(float)(RAND_MAX)) * 120;
		randomTestTime = time(NULL);
		TimedData randTimedData(randomTimedData, randomTestTime);

		// Check manually if data in to TimedData is the sam as data out

		//cout << "Random Input:" << randomTimedData << "," << randomTestTime << endl;
		//cout << "Retrieved Data:" << randTimedData.getTimedData() << "," << randTimedData.getTime() << endl;

		 //Check dat in == data out with i random values between 0 and 120

		if( (randomTimedData == randTimedData.getData()) && (randomTestTime == randTimedData.getTime()))
		{
			testStatus = true;
		}
		else
		{
			testStatus = false;
		}
	}
	if (testStatus == true)
	{
		cout << "test completed successfully" << endl;
	}
	else
	{
		cout << "test failed" << endl;
	}
	cout << "*\nEnd testing TimedData constructor with random values\n*" << endl;
}
/*
int main(){

	testEmpty();
	testMin();
	testMax();
	testRandom();
	float maxh = 120;
	string file = "test/testTimedData.bin";
	testWrite(file, maxh);
	//@todo Write and read multiple objects
	return 0;

}*/

