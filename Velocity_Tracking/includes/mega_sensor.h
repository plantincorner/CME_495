/**
 * @file mega_sensor.h
 * @author Luke Protz
 * @date March 27, 2016
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
 * @brief extracts data from sensors
 * @brief detemines most accurate data based sensors being used
 *
 * @pre The Lidar is initialized
 * @pre The IMU is initialized
 * @param[out] g_x pitch velocity in rad/s
 * @param[out] g_y roll  velocity in rad/s
 * @param[out] a_x pitch in radians
 * @param[out] a_y roll in radians
 * @param[out] t   temperature in degrees Celcius
 * @param[out] p   pressure in pascales
 * @param[out] l   distance from lidar in cm
 * @param[out] l_c height calculation held when uav reaches 40 m
 * @param[out] b_c pressure measurement held uav reaches 40 m
 * @param[out] h   calculated height, corrected for attitude
 * @param[out] fd  confirmation of lidar functionality, equals 1 when lidar operational
 */
void MEGA_SENSOR(float *g_x,float *g_y,float *a_x,float *a_y,float *t,long *p,int *l,float *l_c,long *b_c,float *h,int fd);

#endif
