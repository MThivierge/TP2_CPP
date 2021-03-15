#ifndef __DATAPOINT_H__
#define __DATAPOINT_H__

#include <iostream>

class Datapoint{
	private:
		std::string timestamp;
		double latitude;
		double longitude;
		int temperature;
	
	public:
		Datapoint(std::string timestamp, double latitude, double longitude, int temparature);
		
		double getLatitude() const;

		double getLongitude() const;

		bool operator<(const Datapoint& right_datapoint) const;

		
};

#endif //__DATAPOINT_H__