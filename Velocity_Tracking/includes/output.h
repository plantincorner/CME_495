/**
*@file output.h
*@author Luke Protz
*@date March 25, 2016
*@brief Interface with lidar manufacturer API
*/
#ifndef OUTPUT_H
#define OUTPUT_H

#include "sensor.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <wiringPi.h> //added

/**
*@brief Initializes Lidar
*@param[in] sig wake signal
*@post lidar is operational
*/
void  INThandler(int sig);

/**
*@brief gathers information from IMU (accelerometer and gyroscope)
*@param[out] gyr_x gyroscope pitch value
*@param[out] gyr_y gyroscope roll value
*@param[out] acc_x accelerometer pitch value
*@param[out] acc_y accelerometer roll value
*@post parameters contain most recent attitude measurements
*/
void ACCGYR(float *gyr_x, float *gyr_y, float *acc_x, float *acc_y);

#endif
