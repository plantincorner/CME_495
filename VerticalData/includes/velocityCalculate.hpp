/*
 * velocityCalculate.hpp
 *
 *  Created on: Mar 26, 2016
 *      Author: devon
 */

#ifndef INCLUDES_VELOCITYCALCULATE_HPP_
#define INCLUDES_VELOCITYCALCULATE_HPP_

#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <random>

using namespace std;
using namespace cv;

void fourPixelAverage(InputArray imgFull, OutputArray imgReduced);

float entropy(Mat seq, Size size, int index);

Mat myEntropy(Mat seq, int histSize);

void calculateAEAO(Mat prevGray, Mat nextGray, double cameraElevation,int frameRate, double pitch, double roll, double wPitch, double wRoll, double &Vx, double &Vy, double &Vz, double &speed, double &direction  );


#endif /* INCLUDES_VELOCITYCALCULATE_HPP_ */
