
/************************************************************
 VerticalData class body
 ************************************************************/

// include associated header file
#include "../includes/VerticalData.hpp"

using namespace std;

void VerticalData::storeHeight(Height &ht)
{
	if(this->heights.empty())
	{
		this->heights.push(ht);
		this->setVelocity(0);
	}
	else
	{
		this->heights.push(ht);
		this->calculateVelocity();
		this->heights.pop();
	}
}
void VerticalData::placeHeight(float height, microseconds time)
{
	if (this->heights.empty())
	{
		this->heights.emplace(height, time);
		this->setVelocity(0);
	}
	else
	{
		this->heights.emplace(height, time);
		this->calculateVelocity();
		this->heights.pop();
	}
}
void VerticalData::setVelocity(float vel)
{
	this->velocity = vel;
}

float VerticalData::getVelocity()
{
	return this->velocity;
}

void VerticalData::printAll()
{
	if (this->heights.empty())
	{
		cout << "no data to print" << endl;
	}
	else
	{
		cout << "current height: " << endl;
		this->heights.back().printAll();
		cout << "Vertical Velocity: "<< this->getVelocity() << endl;
	}

}


void VerticalData::calculateVelocity()
{
		double  deltaT = 0;
		double deltaH = 0;
		microseconds currentTime = this->heights.back().getTime();
		microseconds previousTime = this->heights.front().getTime();
		double currentHeight = this->heights.back().getData();
		double previousHeight = this->heights.front().getData();

		deltaT = (double)((currentTime - previousTime).count())/1000000 ;// us / 1000000 = s
		deltaH = (currentHeight - previousHeight); 
		this->velocity = (deltaH/deltaT);
}

/************************************************************
 End of VerticalData class body
 ************************************************************/

