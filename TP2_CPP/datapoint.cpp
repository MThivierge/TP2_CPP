#include "datapoint.h"

Datapoint::Datapoint(std::string timestamp, double latitude, double longitude, double temperature){
	this->timestamp = timestamp;
	this->latitude = latitude;
	this->longitude = longitude;
	this->temperature = (temperature - 32)/1.8; //Calcul de conversion de fahrenheit en celsius selon wikipédia
}

std::string Datapoint::getTimestamp() const{
	return this->timestamp;
}
        
double Datapoint::getLatitude() const{
	return this->latitude;
}

double Datapoint::getLongitude() const{
	return this->longitude;
}
        
double Datapoint::getTemperature() const{
	return this->temperature;
}

		
bool Datapoint::operator<(const Datapoint& right_datapoint) const{

	//L'arbre doit aller du nord vers le sud (donc 40.71 doit être à gauche de -40.71)
	//Si la lattitude est identique, l'arbre doit aller de l'ouest vers l'est (donc -110.55 doit être à gauche de 110.55)

	if(this->latitude > right_datapoint.getLatitude()){
		return true;
	}
	else if( this->latitude == right_datapoint.getLatitude() && this->longitude < right_datapoint.getLongitude()){
		return true;
	}
	
	return false;

}