#include "Height.hpp"



Height::Height()
{
	this->setData(0);
	this->setTime(0);
	cout << "Creating empty Height object" << endl;
}


Height::Height(float height, time_t time) {
	this->setData(height);
	this->setTime(time);

	//cout << time << ": Creating Height object" << endl;
}


Height::~Height(void) {
	//cout << "Deleting Height object" << endl;
}

/************************************************************
 End of Height class body
 ************************************************************/
