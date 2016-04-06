/**
 *
 * @author Devon Haubold
 * @brief Object containing Height data and timestamp
 */

#ifndef __HEIGHT_H_INCLUDED__
#define __HEIGHT_H_INCLUDED__

#include "../includes/TimedData.hpp"


using namespace std;

/************************************************************/

/** Store height data and time-stamp
 * @note Inherits from the TimedData class
 * @see TimedData.hpp
 */
class Height: public TimedData
{
public:

	/**Construct an empty Height object
	 * @post an empty Height object is created
	 */
	Height();

	/**Construct a Height object containing a height and time
	 * @param[in] height the height of the object
	 * @param[in] time the height reading was taken
	 * @post A Height object containing a height reading and the corresponding time-stamp
	 */
	Height(float height, microseconds time);


	/**
	 * Destructor for Height object
	 */
	~Height(void);

};

/************************************************************
 End of Height class header
 ************************************************************/
#endif
