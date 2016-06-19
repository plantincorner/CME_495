CXX = g++
CC = gcc
CFLAGS = -Wall -c
CXXFLAGS = -Wall -std=++11 

OUTPUTDIR = ./build/
MKDIR = mkdir -p $(OUTPUTDIR)
OBJECTC = redis.o

CSOURCES = \output.c \sensor.c 

CXXSOURCES = velocityTracking.cpp Height.cpp TimedData.cpp VerticalData.cpp VelocityData.cpp

all: server

server: 
	$(MKDIR)
	$(CC) $(CSOURCES) $(CFLAGS) -o $(OUTPUTDIR)$(OBJECTC)
	$(CXX) $(OUTPUTDIR) $(CXXSOURCES) -o $(OUTPUTDIR)server

.PHONY: clean
clean:
	$(RM) -rf $(OUTPUTDIR)
	$(RM) ./*.gc??
	$(RM) ./*.o
