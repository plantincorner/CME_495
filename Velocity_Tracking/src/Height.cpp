#include "../includes/Height.hpp"


Height::Height()
{
	this->setData(0);
	this->setTime(microseconds(0));
	//cout << "Creating empty Height object" << endl;
}


Height::Height(float height, microseconds time) {
	this->setData(height);
	this->setTime(microseconds(time));

	//cout << time << ": Creating Height object" << endl;
}


Height::~Height(void) {
	//cout << "Deleting Height object" << endl;
}

/************************************************************
 End of Height class body
 ************************************************************/
