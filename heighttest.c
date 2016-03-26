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

//baro
#include "bmp180/bmp180.h"

//lidar
#include "lidar_lite/lidarLite.h"

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
	
	//var for math
	float height = 0;
	float comp_height = 0;
	
	//math
	while(1){
	ACCGYR(&gyr_x,&gyr_y,&acc_x,&acc_y);	
	BAROTEMP(&temp,&press);
	LIDAR_LITE_(&res,fd);
	
	
	//height = (res*abs(cos(abs(acc_x)*(M_PI/180))*cos(abs(acc_y)*(M_PI/180)))) / (sqrt(pow(cos(abs(acc_x)*(M_PI/180)),2) + pow(sin(abs(acc_x)*(M_PI/180)),2) + pow(cos(abs(acc_y)*(M_PI/180)),2)));
	
	height = (res*cos(abs(acc_x)*(M_PI/180))*cos(abs(acc_y)*(M_PI/180))) / (sqrt(pow(cos(abs(acc_x)*(M_PI/180)),2) + pow(sin(abs(acc_x)*(M_PI/180)),2) + pow(cos(abs(acc_y)*(M_PI/180)),2)));
	
	comp_height = height + 0.5*height;
	
	printf("height = %3.0f cm comp_height = %3.0f cm length = %3.0d cm \n", height, comp_height, res);
	//printf (" gyr_x %7.3f \t acc_x %7.3f \t gyr_y %7.3f \t acc_y %7.3f \n", gyr_x, acc_x, gyr_y, acc_y);
	
	}
	//printf (" gyr_x %7.3f \t acc_x %7.3f \t gyr_y %7.3f \t acc_y %7.3f \n", gyr_x, acc_x, gyr_y, acc_y);
	//printf("t = %f, p = %lu \n", temp, press);
	//printf("%3.0d cm \n", res );

}
