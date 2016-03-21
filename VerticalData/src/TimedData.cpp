#include "TimedData.hpp"


TimedData::TimedData() {
	this->setData(0);
	this->setTime(0);
	//cout << "Creating empty TimedData object" << endl;
}


TimedData::TimedData(float /*in*/data, time_t /*in*/time) {
	this->setData(data);
	this->setTime(time);

	//cout << time << ": Creating TimedData object" << endl;
}

void TimedData::setData(float /*in*/d) {
	this->data = d;
}

float TimedData::getData() {
	return this->data;
}


void TimedData::setTime(time_t /*in*/t) {
	this->time = t;
}

time_t TimedData::getTime() {
	return this->time;
}

void TimedData::printAll(){
	cout << "data: " << this->getData() << endl;
	cout << "time:" << this->getTime() << endl;
}
void TimedData::writeData(string filename, TimedData *h){

	fstream outfile (filename,ios::out | ios::binary | ios::app);
	 if(!outfile.is_open())
	{
		cout << "error while opening file" <<endl;
	}
	else
	{
	cout << "writing file: " << filename << endl;
	outfile.write((char *)(h),sizeof(TimedData));
	outfile.close();
	}
}
void TimedData::readData(string filename, TimedData *h)
{
	fstream infile (filename, ios::in | ios::binary);
	if(!infile.is_open())
	{
		cout << "error while opening file" <<endl;
	}
	else
	{
	cout << "reading: "<< filename << endl;
	infile.seekg(0);
	infile.read((char *)(h), sizeof(TimedData));
	infile.close();
	}
}

TimedData::~TimedData(void) {
	//cout << "Deleting TimedData object" << endl;
}

/************************************************************
 End of TimedData class body
 ************************************************************/
