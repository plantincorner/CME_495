/**
 *
 */

#ifndef CME_DIAGRAM_VELOCITYDATA_H
#define CME_DIAGRAM_VELOCITYDATA_H

/************************************************************
 VelocityData class header
 ************************************************************/
#include <cstdlib>
#include <iostream>
#include <opencv2/core/core.hpp>
#include "Height.hpp"

/************************************************************/
using namespace std;
using namespace cv;
/**
 * 
 */
class VelocityData {
public:

	/**
	 * @return data
	 */
	VelocityData();

	/**
	 * 
	 * @param height 
	 * @param velocity 
	 */
	VelocityData(float prevVelocity);

	/**
	 *
	 * @param vel
	 * @param prevOrCurrent
	 */
	void setCurrentVelocity(double currVelocity);

	/**
	 * @return vel
	 * @param prevOrCurrent
	 */
	double getCurrentVelocity();

	/**
	 *
	 */
	void setPreviousVelocity(double prevVelocity);

	/**
	 *
	 */
	double getPreviousVelocity();

	/**
	 *
	 * @param ht
	 */
	void setHeight(float ht);

	/**
	 * @return height
	 * @return height
	 */
	float getHeight();

	/**
	 *
	 */
	void setVerticalVelocity(float vertVel);
	/**
	 * @return vel
	 * @return velocity
	 */
	float getVerticalVelocity();

	/**
	 *
	 * @param pitch
	 */
	void setPitch(float pch);

	/**
	 * @return
	 * @return pitch
	 */
	float getPitch();

	/**
	 *
	 * @param pitchVel
	 */
	void setPitchVelocity(float /*in*/pitchVel);

	/**
	 *
	 * @return pitchVel
	 */
	float getPitchVelocity();

	/**
	 *
	 * @param rl
	 */
	void setRoll(float rl);

	/**
	 * @return roll
	 */
	float getRoll();

	/**
	 *
	 * @param velocity
	 */
	void setRollVelocity(float rollVel);

	/**
	 *
	 * @return velocity
	 */
	float getRollVelocity();

	/**
	 *
	 * @param fps
	 */
	void setFrameRate(float fps);

	/**
	 *
	 * @return fps
	 */
	float getFrameRate();

	/**
	 *
	 * @param imageNumber
	 * @param image
	 */
	void setImage_1(Mat image);

	/**
	 *@todo may not need this method just use references instead
	 * @param imageNumber @return image
	 * @param image
	 */
	Mat getImage_1();
	void setImage_2 (Mat image);
	Mat getImage_2();
	/**
	 *
	 * @return
	 */
	float getConfidenceFactor();

	/**
	 *
	 * @param factor
	 */
	void setConfidenceFactor(float factor);

	void printAll();


private:
	/**
	 * 
	 */
	double velocity;
	/**
	 * 
	 */
	double previousVelocity;

	/**
	 * 
	 */
	float height;
	/**
	 *
	 */
	float verticalVelocity;
	/**
	 *
	 */
	float pitch;
	/**
	 * 
	 */
	float pitchVelocity;
	/**
	 * 
	 */
	float roll;
	/**
	 * 
	 */
	float rollVelocity;
	/**
	 * 
	 */
	float frameRate;
	/**
	 * 
	 */
	Mat image_1;
	/**
	 * 
	 */
	Mat image_2;
	/**
	 * 
	 */
	float confidenceFactor;


	void init();
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

/************************************************************
 End of VelocityData class header
 ************************************************************/

#endif
