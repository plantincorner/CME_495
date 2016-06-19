//universal
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <wiringPi.h>

//gyro acc
#include "gyro_accelerometer/sensor.h"
#include "gyro_accelerometer/output.h"
#define M_PI 3.14159265358979323846
#define DELT_PRESS 11.399393 //change in pa per 1m chang in alt
#define ALT_SENS_CHNG 100 //cm

//baro
#include "bmp180/bmp180.h"

//lidar
#include "lidar_lite/lidarLite.h"

//variables for calculations
#define M_PI 3.14159265358979323846
#define DELT_PRESS 11.399393 //change in pa per 1m change in altitude
#define ALT_SENS_CHNG 100 //cm

int main()
{
	//initialize gyro-acc
	signal(SIGINT, INThandler);
	enableIMU();
	
	//initialize for lidar
	int fd = lidar_init(false);
	
	//var for gyro-acc
	float gyr_x = 0; //change in roll
	float gyr_y = 0; //change in pitch
	float acc_x = 0; //position in roll
	float acc_y = 0; //position in pitch
	
	//var for baro
	float temp = 0;
	long press = 0;
	
	//var for lidar
	int res = 0;
	
	//var for calculations
	float height = 0;
	float comp_height = 0;
	float height_out = 0;
	float lidar_calib_height;
	float baro_calib;

	
	//sensor functions
	ACCGYR(&gyr_x,&gyr_y,&acc_x,&acc_y);	
	BAROTEMP(&temp,&press);
	LIDAR_LITE_(&res,fd);

	//calculating height with changing distance and angles (height should stay constant in an ideal situation)
	height = (res*cos(abs(acc_x))*cos(abs(acc_y))) / (sqrt(pow(cos(abs(acc_x)),2) + pow(sin(abs(acc_x)),2) + pow(cos(abs(acc_y)),2)));
	comp_height = height + 0.5*height; //I added this because it makes it work

	if (comp_height <= ALT_SENS_CHNG){
		lidar_calib_height = comp_height;
		baro_calib = press;
		height_out = comp_height;
	}
	else if (comp_height > ALT_SENS_CHNG) {
		height_out = lidar_calib_height + abs(baro_calib - press)*DELT_PRESS;
	}
	else {
		height_out = 0;
	}
	printf (" height_out = %f \t comp_height = %f \t p = %lu \t lidar_calib_height = %f \n", height_out, comp_height, press, lidar_calib_height);

	//printf (" gyr_x %7.3f \t acc_x %7.3f \t gyr_y %7.3f \t acc_y %7.3f \n", gyr_x, acc_x, gyr_y, acc_y);
	//printf("t = %f, p = %lu \n", temp, press);
	//printf("%3.0d cm \n", res );

}
