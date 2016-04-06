/**
 * @author Devon Haubold
 * @brief Calculates vertical velocity
 */

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
 * @brief Store two Height objects and calculate vertical velocity
 */
class VerticalData {
public:

	/**
	 * @brief Store height object
	 * @param[in] ht the height of the UAV in meters
	 */
	void storeHeight(Height &ht);

	/**
	 *@brief create Height object and place in queue
	 *@param[in] height height of UAV in meters
	 *@param[in] time timestamp of height in microseconds
	 */
	void placeHeight(float height, microseconds time);
	/**
	 * @return vertical velocity
	 */
	float getVelocity();

	/**
	 *@param vel the velocity of the UAV in m/s
	 */
	void setVelocity(float vel);

	/**
	 * @brief Print contents of VerticalData object
	 */
	void printAll();

protected:
	/**
	 * @brief Calculate the vertical velocity
	 */
	void calculateVelocity();

private:
	queue <Height> heights;

	double velocity;
};

/************************************************************
 End of VerticalData class header
 ************************************************************/

#endif
