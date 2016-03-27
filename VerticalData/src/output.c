#include "../includes/output.h"

#define DT 0.02         // [s/loop] loop period. 20ms
#define AA 0.97         // complementary filter constant

#define A_GAIN 0.0573      // [deg/LSB]
#define G_GAIN 0.070     // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846


void  INThandler(int sig)
{
        signal(sig, SIG_IGN);
        exit(0);
}

void ACCGYR(float *gyr_x, float *gyr_y, float *acc_x, float *acc_y)
{
	float rate_gyr_y = 0.0;   // [deg/s]
	float rate_gyr_x = 0.0;    // [deg/s]
//	float rate_gyr_z = 0.0;     // [deg/s]

	int  accRaw[3];
//	int  magRaw[3];
	int  gyrRaw[3];

//	float gyroXangle = 0.0;
//	float gyroYangle = 0.0;
//	float gyroZangle = 0.0;
	float AccYangle = 0.0;
	float AccXangle = 0.0;
//	float CFangleX = 0.0;
//	float CFangleY = 0.0;

	//read ACC and GYR data
	readACC(accRaw);
	readGYR(gyrRaw);

	//Convert Gyro raw to degrees per second
	rate_gyr_x = (float) gyrRaw[0] * G_GAIN;
	rate_gyr_y = (float) gyrRaw[1]  * G_GAIN;
//	rate_gyr_z = (float) gyrRaw[2]  * G_GAIN;

	//Convert Accelerometer values to degrees
	AccXangle = (float) (atan2(accRaw[1],accRaw[2])+M_PI)*RAD_TO_DEG;
	AccYangle = (float) (atan2(accRaw[2],accRaw[0])+M_PI)*RAD_TO_DEG;

        //Change the rotation value of the accelerometer to -/+ 180 and move the Y axis '0' point to up.
        //Two different pieces of code are used depending on how your IMU is mounted.
        //If IMU is upside down
	/*
        if (AccXangle >180)
                AccXangle -= (float)360.0;

        AccYangle-=90;
        if (AccYangle >180)
                AccYangle -= (float)360.0;
	*/

        //If IMU is up the correct way, use these lines
        AccXangle -= (float)180.0;
	if (AccYangle > 90)
	        AccYangle -= (float)270;
	else
		AccYangle += (float)90;

	//return values (radians);
	*gyr_x = rate_gyr_x*(M_PI/180);
	*gyr_y = rate_gyr_y*(M_PI/180);
	*acc_x = AccXangle*(M_PI/180);
	*acc_y = AccYangle*(M_PI/180);

}
