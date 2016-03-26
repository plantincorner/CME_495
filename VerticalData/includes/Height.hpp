#ifndef __HEIGHT_H_INCLUDED__
#define __HEIGHT_H_INCLUDED__

#include "../includes/TimedData.hpp"


using namespace std;

/************************************************************/

/** Store height data and time-stamp
 *	Inherits from the TimedData class, differs in name only
 */

class Height: public TimedData
{
public:

	/**Construct an empty Height object
	 * @post an empty Height object is created
	 */
	Height();

	/**
	 * @param[in] time the height reading was taken
	 * @param[in] sensor height reading
	 * @pre Height reading availabel
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
