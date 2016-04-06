/**
 * @file velocityCalculate.hpp
 * @date Mar 26, 2016
 * @author Lance Pitka
 * @author Devon Haubold
 * @brief Calculate the Horizontal Velocity of a UAV
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


/**
 * @brief average four pixels
 * @param[in] imgFull the image to be averaged
 * @param[out] imgReduced an averaged image
 */
void fourPixelAverage(InputArray imgFull, OutputArray imgReduced);

/**
 * @brief calculate the entropy of an image
 * @param[in] seq a single channel 8 bit image
 * @param[in] size dimensions of image
 * @param[in] index pixel location in image
 * @return the entropy of the image at index
 */
float entropy(Mat seq, Size size, int index);

/**
 * @brief calculates relative occurrence of different symbols within given input sequence using histogram
 * @param[in] seq a single channel 8 bit image
 * @param[in] histSize size of the histogram
 * @return histogram showing occurence of symbols in a sequence
 */
Mat myEntropy(Mat seq, int histSize);

/**
 * @brief Calculates velocity in the x and y directions,speed and direction of an unmanned aerial vehicle(UAV).
 * @brief Calculates confidence in calculations
 * @pre Two images, prevGray and nextGray, taken successively at a specified frame rate
 * @pre Pitch, Height, Vz,  Roll, change in pitch, change in Roll, at the time the images are captured
 * @pre Vx, Vy, speed and Direction are declared
 * @param[in] prevGray the first single channel 8bit image
 * @param[in] nextGray the second single channel 8bit image
 * @param[in] cameraElevation the distance of the UAV from the ground
 * @param[in] frameRate rate at which the images are being captured in fps
 * @param[in] pitch the pitch of the UAV in radians
 * @param[in] roll the roll of the UAV in radians
 * @param[in] wPitch the UAV angular pitch velocity in radians/sec
 * @param[in] wRoll the UAV angular roll velocity in radians/sec
 * @param[out] Vx UAV velocity in the x direction
 * @param[out] Vy UAV velocity in the y direction
 * @param[in,out] Vz UAV Velocity in the z direction (vertical velocity) in m/s
 * @param[out] speed the speed of UAV in m/s
 * @param[out] direction direction of the UAV in radians relative to itself.
 * @post Vx contains the most recent velocity in the x direction
 * @post Vy contains the most recent Velocity in the y direction
 * @post speed contains the most recent speed
 * @post direction contains the most recent direction
 */
void calculateAEAO(Mat prevGray, Mat nextGray, double cameraElevation,int frameRate, double pitch, double roll, double wPitch, double wRoll, double &Vx, double &Vy, double Vz, double &speed, double &direction  );


#endif /* INCLUDES_VELOCITYCALCULATE_HPP_ */
