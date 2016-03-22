/*
 * verticalDataTesting.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: devon
 */

#include "../includes/VerticalData.hpp"


/*
 * Test the VerticalData object
 * @todo Test Storage
 * @todo Test retrieval of height object
 * @todo Test calculation of vertical velocity
 */

/*
 * Test the constructor
 *
 */
int testConstructor(VerticalData *testVD)
{
	VerticalData testObject;
	*testVD = testObject;
	//return 0 on success
	return 0;
}
/*
 * Test if Height object is stored
 */
void testStorage(VerticalData *testVD, Height *testHeight)
{
	//*testVD->storeHeight(testHeight);
	return;
}

/*
 * Test if Height object is returned and is the same as that stored
 */
void testRetrieve(Height *testHeight)
{

}

/*
 * Test the calculation of vertical velocity
 */
void testVelocityCalc()
{

}
