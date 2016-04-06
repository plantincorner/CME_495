/**
 * @file mega_sensor.h
 * @author Luke Protz
 * @brief get sensor data
 */
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

#include "../include/lidarLite.h"
//gyro acc
#include "../includes/sensor.h"
#include "../includes/output.h"

//baro
#include "../includes/bmp180.h"

//lidar

/**
 * @brief
 *
 * @pre The Lidar is initialized
 * @pre The IMU is initialized
 * @param[out] g_x acceleration in the x direction in
 * @param[out] g_y acceleration in the y direction
 * @param[out] a_x
 * @param[out] a_y
 * @param[out] t
 * @param[out] p
 * @param[out] l
 * @param[out] l
 * @param[out] l_c
 * @param[out] b_c
 * @param[out] fd
 * @param[out]
 * @post
 */
void MEGA_SENSOR(float *g_x,float *g_y,float *a_x,float *a_y,float *t,long *p,int *l,float *l_c,long *b_c,float *h,int fd);

#endif
