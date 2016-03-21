// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef CME_DIAGRAM_VELOCITYDATA_H
#define CME_DIAGRAM_VELOCITYDATA_H

/************************************************************
 VelocityData class header
 ************************************************************/
//@todo remove unused includes
//#include "CME_diagram/Pkg_CME_diagram.h"

//#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include <cstdlib>
#include <iostream>
#include <../includes/Height.hpp>
//#include "CME_diagram/VerticalData.h"

/************************************************************/
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
	//VelocityData(float /*in*/height, float /*in*/velocity);

	/**
	 * @return height
	 * @return height
	 */
//	float getHeight();

	/**
	 *
	 * @param ht
	 */
//	void setHeight(float /*in*/ht);

	/**
	 * @return vel
	 * @return velocity
	 */
	float getVerticalVelocity();

	/**
	 *
	 * @param pitch
	 */
	void setPitch(float /*in*/pitch);

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
	 * @return rl
	 * @return roll
	 */
	float getRoll();

	/**
	 *
	 * @param roll
	 */
	void setRoll(float /*in*/roll);

	/**
	 *
	 * @param velocity
	 */
	void setRollVelocity(float /*in*/velocity);

	/**
	 *
	 * @return velocity
	 */
	float getRollVelocity();

	/**
	 *
	 * @param fps
	 */
	void setFrameRate(float /*in*/fps);

	/**
	 *
	 * @return fps
	 */
	float getFrameRate();

	/**
	 *
	 * @param imageNumber @return image
	 * @param image
	 */
	void getImage(int /*in*/imageNumber, uint8_t* /*out*/image);

	/**
	 *
	 * @param imageNumber
	 * @param image
	 */
	void setImage(int /*in*/imageNumber, uint8_t /*in*/image[]);

	/**
	 * @return vel
	 * @param prevOrCurrent
	 */
	void getVelocity(float /*in*/prevOrCurrent);

	/**
	 *
	 * @param vel
	 * @param prevOrCurrent
	 */
	void setVelocity(float /*in*/vel, int /*in*/prevOrCurrent);

	/**
	 *
	 * @return
	 */
	float getConfidenceFactor();

	/**
	 *
	 * @param factor
	 */
	void setConfidenceFactor(float /*in*/factor);

	/**
	 * @return
	 */
	void delete();

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
	VerticalData vertical;
	/**
	 * 
	 */
	float frameRate;
	/**
	 * 
	 */
	uint8_t image_1[];
	/**
	 * 
	 */
	uint8_t image_2[];
	/**
	 * 
	 */
	float confidenceFactor;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

/************************************************************
 End of VelocityData class header
 ************************************************************/

#endif
