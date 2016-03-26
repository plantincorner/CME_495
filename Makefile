all:
	gcc -o height -l rt heighttest.c lidar_lite/lidarLite.c bmp180/bmp180.c gyro_accelerometer/sensor.c gyro_accelerometer/output.c -lm -lwiringPi
