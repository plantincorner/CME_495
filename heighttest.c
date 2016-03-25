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
	
	//math
	ACCGYR(&gyr_x,&gyr_y,&acc_x,&acc_y);	
	BAROTEMP(&temp,&press);
	LIDAR_LITE_(&res,fd);
	
	height = res*sqrt(1-(pow(sin(abs(acc_x)),2)+pow(sin(abs(acc_y)),2)));
	
	
	printf (" gyr_x %7.3f \t acc_x %7.3f \t gyr_y %7.3f \t acc_y %7.3f \n", gyr_x, acc_x, gyr_y, acc_y);
	printf("t = %f, p = %lu \n", temp, press);
	printf("%3.0d cm \n", res );

}
