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
	
	float g_x = 0;
	float g_y = 0;
	float a_x = 0;
	float a_y = 0;
	float t = 0;
	long p = 0;
	int l = 0;
	float l_c = 0;
	long b_c = 0;
	float h = 0;
	
	while(1){
	MEGA_SENSOR(&g_x,&g_y,&a_x,&a_y,&t,&p,&l,&l_c,&b_c,&h,fd);
	printf (" g_x=%7.3f \t a_x=%7.3f \t g_y=%7.3f \t a_y=%7.3f \t t=%f \t p=%lu \t l=%3.0d \t l_c=%7.3f \t b_c=%lu \t h=%7.3f \n", g_x,a_x,g_y,a_y,t,p,l,l_c,b_c,h);
	}
	
	//printf (" gyr_x %7.3f \t acc_x %7.3f \t gyr_y %7.3f \t acc_y %7.3f \n", gyr_x, acc_x, gyr_y, acc_y);
	//printf("t = %f, p = %lu \n", temp, press);
	//printf("%3.0d cm \n", res );

}
