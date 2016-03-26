
/************************************************************
 VelocityData class body
 ************************************************************/

// include associated header file
//#include "CME_diagram/VelocityData.h"
#include "../includes/VelocityData.hpp"


/**
 *@todo constructor can be ommited if not overloaded
 *
 */
VelocityData::VelocityData()
{
	this->init();
}

/**
 *@todo remove overloaded constructor if not used
 */
VelocityData::VelocityData(float velocity)
{
	this->init();
	this->setPreviousVelocity(velocity);
}

void VelocityData::setCurrentVelocity(double currVelocity)
{
	this->velocity = currVelocity;
}


double VelocityData::getCurrentVelocity()
{
	return this->velocity;
}


void VelocityData::setPreviousVelocity(double prevVelocity)
	{
		this->previousVelocity = prevVelocity;
	}

double VelocityData::getPreviousVelocity()
{
	return this->previousVelocity;
}

void VelocityData::setHeight(float ht)
{
	this->height = ht;
}


float VelocityData::getHeight()
{
	return this->height;
}

void VelocityData::setVerticalVelocity(float vertVel)
{
	this->verticalVelocity = vertVel;
}


float VelocityData::getVerticalVelocity()
{
	return this->verticalVelocity;
}


void VelocityData::setPitch(float pch)
{
	this->pitch = pch;
}

float VelocityData::getPitch()
{
	return this->pitch;
}


void VelocityData::setPitchVelocity(float pitchVel)
{
	this->pitchVelocity = pitchVel;
}


float VelocityData::getPitchVelocity()
{
	return this->pitchVelocity;
}

void VelocityData::setRoll(float rl)
{
	this->roll = rl;
}

float VelocityData::getRoll()
{
	return this->roll;
}

void VelocityData::setRollVelocity(float rollVel)
{
	this->rollVelocity = rollVel;
}

float VelocityData::getRollVelocity()
{
	return this->rollVelocity;
}

void VelocityData::setFrameRate(float fps)
{
	this->frameRate = fps;
}

float VelocityData::getFrameRate()
{
	return this->frameRate;
}

void VelocityData::setImage_1(uint8_t image[])
{
	//this->image_1 = image;
}
/*
uint8_t* VelocityData::getImage_1(uint8_t* image_1)
{
	return this->image_1;
}
*/
void VelocityData::setImage_2(uint8_t image[])
{
	//this->image_2 = image;
}

void VelocityData::setConfidenceFactor(float factor)
{
	this->confidenceFactor = factor;
}

float VelocityData::getConfidenceFactor()
{
	return this->confidenceFactor;
}

void VelocityData::init()
{
	this->setConfidenceFactor(0);
	this->setCurrentVelocity(0);
	this->setFrameRate(0);
	this->setHeight(0);
	this->setImage_1(0);
	this->setImage_2(0);
	this->setPitch(0);
	this->setPitchVelocity(0);
	this->setPreviousVelocity(0);
	this->setRoll(0);
	this->setRollVelocity(0);
	this->setVerticalVelocity(0);
}

void VelocityData::printAll()
{
	cout << "Current Velocity: " << this->getCurrentVelocity() << endl;
	cout << "Height: " << this->getHeight() << endl;
	cout << "Vertical Velocity: " << this->getVerticalVelocity() << endl;
	cout << "Pitch: " << this->getPitch() << endl;
	cout << "Pitch Velocity: " << this->getPitchVelocity() << endl;
	cout << "Roll: " << this->getRoll() << endl;
	cout << "Roll Velocity: " << this->getRollVelocity() << endl;
	cout << "Frame Rate: " << this->getFrameRate() << endl;
	cout << "Confidence Factor: " << this->getConfidenceFactor() << endl;
}

/************************************************************
 End of VelocityData class body
 ************************************************************/
