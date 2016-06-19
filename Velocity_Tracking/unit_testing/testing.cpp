/*
 * heightTesting.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: devon
 */
#include "../includes/Height.hpp"
#include "../includes/VerticalData.hpp"
#include <chrono>

using namespace std;
using namespace chrono;

//instantiate empty height object
void testEmptyHeight()
{
cout << "creating empty Height object" <<endl ;
Height emptyHeight;
cout << "empty Height contents" <<endl ;
emptyHeight.printAll();
}
void testMinHeight()
{
	float lowerHeight = 0;
	 microseconds lowerTime = microseconds(0);
	//test min values
	cout << "creating min Height object" <<endl ;
	Height minHeight(lowerHeight, lowerTime);
	cout << "min Height contents" <<endl ;
	minHeight.printAll();
}


//test max height, use current time
void testMaxHeight()
{
	float upperHeight = 120;
	microseconds maxTime = duration_cast<microseconds>(system_clock::now().time_since_epoch());
	cout << "creating empty max Height object" <<endl;
	Height maxHeight(upperHeight, maxTime);
	cout << "max Height contents" <<endl ;
	maxHeight.printAll();
}

void testWriteHeight(string testFile, float height)
{
	Height maxHeight(height, duration_cast<microseconds>(system_clock::now().time_since_epoch()));
	Height emptyHeight;
	cout << "write to file:";
	maxHeight.printAll();
	maxHeight.writeData(testFile,&maxHeight);
	cout << "read from file"<< endl;
	emptyHeight.readData(testFile, &emptyHeight);
	emptyHeight.printAll();
}
void testRandomHeight()
{
	bool testStatus = false;
	float randomHeight;
	microseconds randomTestTime;
	for(int i=0; i<10000; i++)
	{
		srand(time(NULL) + i);
		randomHeight = ((float)rand()/(float)(RAND_MAX)) * 120;
		randomTestTime = microseconds((int)rand());
		Height randHeight(randomHeight, randomTestTime);

		// Check manually if data in to Height is the sam as data out

		//cout << "Random Input:" << randomHeight << "," << randomTestTime << endl;
		//cout << "Retrieved Data:" << randHeight.getHeight() << "," << randHeight.getTime() << endl;

		 //Check dat in == data out with i random values between 0 and 120

		if( (randomHeight == randHeight.getData()) && (randomTestTime == randHeight.getTime()))
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
}
/*
 * Test the VerticalData object
 * @todo Test Storage
 * @todo Test retrieval of height object
 * @todo Test calculation of vertical velocity
 */


/*
 * Test if Height object is stored
 */
void testStorage(VerticalData &testVD, Height &testHeight)
{
	testVD.storeHeight(testHeight);
	testVD.printAll();
}
void testPlace(VerticalData &testVD, float height, microseconds time)
{
	testVD.placeHeight(height, time);
	testVD.printAll();
}

/*
 * Test the calculation of vertical velocity
 */
void testVelocityCalc(VerticalData &testVD, Height &testPrevious, Height &testCurrent)
{
	//testStorage(testVD, testPrevious);
	//testStorage(testVD, testCurrent);
	testPlace(testVD, testPrevious.getData(), testPrevious.getTime());

	testPlace(testVD, testCurrent.getData(), testCurrent.getTime());


}


void testRandomVelocity(int numberOfTests)
{
	VerticalData testVD;
	srand(time(NULL));
	for(int i = 0; i < numberOfTests; i++)
	{
		float randomHeight = ((float)rand()/(float)(RAND_MAX)) * 120;

		Height firstHeight(randomHeight, microseconds(i * 25));
		testStorage(testVD, firstHeight);
	}
}

void timeTest()
{
	for(int i = 0; i<10; i++)
	{
		microseconds us = duration_cast<microseconds>(system_clock::now().time_since_epoch());
		time_t tt;
		time(&tt);
		//time_point <system_clock,microseconds> tt2 = system_clock::from_time_t(tt).time_since_epoch();
		//microseconds ustime = duration_cast<microseconds>(system_clock::from_time_t(tt).);

		//microseconds ustime = chrono::duration_cast<microseconds>(system_clock::from_time_t(tt));
		cout << "time: " << tt << " now: " << us.count() << endl;
	}
}
/*
int main(){

	//testEmptyHeight();
	//testMinHeight();
	//testMaxHeight();
	//testRandomHeight();
	/*
	float maxh = 120;
	string file = "test/testHeight.bin";
	testWriteHeight(file, maxh);
	*/
/*
	Height firstHeight(120, microseconds(0));
	Height secondHeight(110, microseconds(25));
	VerticalData testVertData;
	//testStorage(testVertData, firstHeight);
	//testStorage(testVertData, secondHeight);
	//testVelocityCalc(testVertData, firstHeight, secondHeight);
	testRandomVelocity(10);

	return 0;

}
*/
