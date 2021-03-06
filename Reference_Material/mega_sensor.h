#ifndef MEGA_SENSOR_H
#define MEGA_SENSOR_H

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

//function
void MEGA_SENSOR(float *g_x,float *g_y,float *a_x,float *a_y,float *t,long *p,int *l,float *l_c,long *b_c,float *h,int fd);

#endif
