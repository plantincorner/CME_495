//#ifndef OUTPUT_H
//#define OUTPUT_H

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <wiringPi.h> //added

void  INThandler(int sig);

void ACCGYR(float *gyr_x, float *gyr_y, float *acc_x, float *acc_y);

//#endif
