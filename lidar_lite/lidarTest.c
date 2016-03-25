#include "lidarLite.h"
#include <time.h>
#include <wiringPi.h> //added

int main()
{

int res;
int fd = lidar_init(false); //initialize

while (1){
	LIDAR_LITE_(&res,fd);
	printf("%3.0d cm \n", res );
	}
}

