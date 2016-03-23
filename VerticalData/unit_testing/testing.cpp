/*
 * heightTesting.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: devon
 */
#include "../includes/Height.hpp"
#include "../includes/VerticalData.hpp"




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
	time_t lowerTime = 0;
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
	//Maxtime does not exist
	cout << "creating empty max Height object" <<endl;
	Height maxHeight(upperHeight, time(NULL));
	cout << "max Height contents" <<endl ;
	maxHeight.printAll();
}

void testWriteHeight(string testFile, float height)
{
	Height maxHeight(height, time(NULL));
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
	time_t randomTestTime;
	for(int i=0; i<10000; i++)
	{
		srand(time(NULL) + i);
		randomHeight = ((float)rand()/(float)(RAND_MAX)) * 120;
		randomTestTime = time(NULL);
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

/*
 * Test the calculation of vertical velocity
 */
void testVelocityCalc()
{

}

int main(){

//	testEmpty();

//	testRandom();
//	float maxh = 120;
//	string file = "test/testHeight.bin";
//	testWrite(file, maxh);

	Height firstHeight;
	Height secondHeight;
	return 0;

}

