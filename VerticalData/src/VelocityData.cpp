// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

//#define CME_diagram_VelocityData_BODY

/************************************************************
 VelocityData class body
 ************************************************************/

// include associated header file
//#include "CME_diagram/VelocityData.h"
#include "../includes/VelocityData.hpp"
// Derived includes directives

// static attributes (if any)

/**
 *@todo constructor can be ommited if not overloaded
 *
VelocityData::VelocityData() {
	cout << "VelocityData object is being created" << endl;
}
*/
/**
 * 
 * @param height 
 * @param velocity 
 *@todo remove overloaded constructor if not used
VelocityData::VelocityData(float height, float velocity) {
	this.setHeight(height);
	this->setPreviousVelocity(velocity);
}
*/
/**
 * @return height
 * @return height 
 */
//float VelocityData::getHeight() {
//	return this->
//}

/**
 * 
 * @param ht 
 */
//void VelocityData::setHeight(float /*in*/ht) {
//}

/**
 * @return vvel
 * @return velocity 
 */
//float VelocityData::getVerticalVelocity() {
//}

/**
 * 
 * @param pitch 
 */
void VelocityData::setPitch(float /*in*/pitch) {
}

/**
 * @return
 * @return pitch 
 */
//float VelocityData::getPitch() {
//}

/**
 * 
 * @param pitchVel 
 */
void VelocityData::setPitchVelocity(float /*in*/pitchVel) {
}

/**
 * 
 * @return pitchVel 
 */
//float VelocityData::getPitchVelocity() {
//}

/**
 * @return rl
 * @return roll 
 */
//float VelocityData::getRoll() {
//}

/**
 * 
 * @param roll 
 */
void VelocityData::setRoll(float /*in*/roll) {
}

/**
 * 
 * @param velocity 
 */
void VelocityData::setRollVelocity(float /*in*/velocity) {
}

/**
 * 
 * @return velocity 
 */
//float VelocityData::getRollVelocity() {
//}

/**
 * 
 * @param fps 
 */
void VelocityData::setFrameRate(float /*in*/fps) {
}

/**
 * 
 * @return fps 
 */
//float VelocityData::getFrameRate() {
//}

/**
 * 
 * @param imageNumber @return image
 * @param image 
 */
void VelocityData::getImage(int /*in*/imageNumber, uint8_t* /*out*/image) {
}

/**
 * 
 * @param imageNumber 
 * @param image 
 */
void VelocityData::setImage(int /*in*/imageNumber, uint8_t /*in*/image[]) {
}

/**
 * @return vel
 * @param prevOrCurrent 
 */
void VelocityData::getVelocity(float /*in*/prevOrCurrent) {
}

/**
 * 
 * @param vel 
 * @param prevOrCurrent 
 */
//void VelocityData::setCurrentVelocity(float /*in*/vel) {
//}

/**
 *
 * @param vel
 * @param prevOrCurrent
 */
//void VelocityData::setPreviousVelocity(float /*in*/vel) {
//}

/**
 * 
 * @return  
 */
float VelocityData::getConfidenceFactor() {
}

/**
 * 
 * @param factor 
 */
void VelocityData::setConfidenceFactor(float /*in*/factor) {
}

/************************************************************
 End of VelocityData class body
 ************************************************************/
