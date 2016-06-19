#include "mega_sensor.h"

//variables for calculations
#define M_PI 3.14159265358979323846
#define DELT_PRESS 11.399393 //change in pa per 1m change in altitude
#define ALT_SENS_CHNG 40000 //cm

void MEGA_SENSOR(float *g_x,float *g_y,float *a_x,float *a_y,float *t,long *p,int *l,float *l_c,long *b_c,float *h,int fd){
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


	//sensor functions
	ACCGYR(&gyr_x,&gyr_y,&acc_x,&acc_y);
	BAROTEMP(&temp,&press);
	LIDAR_LITE_(&res,fd);

	//calculating height with changing distance and angles (height should stay constant in an ideal situation)
	//height = (res*cos(abs(acc_x))*cos(abs(acc_y))) / (sqrt(pow(cos(abs(acc_x)),2) + pow(sin(abs(acc_x)),2) + pow(cos(abs(acc_y)),2)));
	comp_height = res / (sqrt(pow(tan(abs(acc_x)),2) + pow(tan(abs(acc_x)),2) + 1));
	
	printf("acc_x=%f \n",abs(acc_x));
	
	//comp_height = height + 0.5*height; //I added this because it makes it work

	if (comp_height <= ALT_SENS_CHNG){
		*l_c = comp_height;
		*b_c = press;
		height_out = comp_height;
	}
	else if (comp_height > ALT_SENS_CHNG) {
		height_out = *l_c + abs(*b_c - press)*DELT_PRESS;
	}
	else {
		height_out = 0;
	}
	//output values
	*g_x = gyr_x;
	*g_y = gyr_y;
	*a_x = acc_x;
	*a_y = acc_y;
	*t = temp;
	*p = press;
	*l = res;
	*h = height_out;
}

