

#ifndef CME_DIAGRAM_VERTICALDATA_H
#define CME_DIAGRAM_VERTICALDATA_H

/************************************************************
 VerticalData class header
 ************************************************************/

#include <cstdlib>
#include <queue>
#include <ctime>
#include <iostream>
#include "Height.hpp"

using namespace std;
/************************************************************/
/**
 * 
 */
class VerticalData {
public:

	/*
	 * Store height object
	 * @param[in] currentHeight
	 */
	void storeHeight(Height &ht);

	/*
	 *
	 */
	void placeHeight(float height, microseconds time);
	/*
	 * @return vertical velocity
	 */
	float getVelocity();

	void setVelocity(float vel);

	/*For testing purposes
	 * Print contents of VerticalData object
	 */
	void printAll();

protected:

	void calculateVelocity();

private:
	queue <Height> heights;

	double velocity;
};

/************************************************************
 End of VerticalData class header
 ************************************************************/

#endif
