#include "bmp180.h"
#include <unistd.h>
#include <stdio.h>
#include <wiringPi.h> //added


int main(){
	
	float temp = 0;
	long press = 0;
	
	while (1){
	//delay(100);
	BAROTEMP(&temp,&press);
	printf("t = %f, p = %lu \n", temp, press);
	}

}
