SENSOR=bmp180

all:
	gcc -Wall -c $(SENSOR).c -o $(SENSOR).o -lm
	gcc -Wall $(SENSOR).o barometer.c -o barometer.o -lm

clean:
	rm *.o > /dev/null 2>&1 &
