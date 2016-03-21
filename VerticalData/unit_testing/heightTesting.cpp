/*
 * heightTesting.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: devon
 */
#include "../includes/Height.hpp"





//instantiate empty height object
void testEmpty()
{
cout << "creating empty Height object" <<endl ;
Height emptyHeight;
cout << "empty Height contents" <<endl ;
emptyHeight.printAll();
}
void testMin()
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
void testMax()
{
	float upperHeight = 120;
	//Maxtime does not exist
	cout << "creating empty max Height object" <<endl;
	Height maxHeight(upperHeight, time(NULL));
	cout << "max Height contents" <<endl ;
	maxHeight.printAll();
}

void testWrite(string testFile, float height)
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
void testRandom()
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


int main(){

	testEmpty();
	testMin();
	testMax();
	testRandom();
	float maxh = 120;
	string file = "test/testHeight.bin";
	testWrite(file, maxh);
	return 0;

}

