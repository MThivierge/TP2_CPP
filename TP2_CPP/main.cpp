#include "datapoint.h"

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <stdexcept>

int main(){
    //Création du conteneur pour les objets Datapoint
    std::set<Datapoint> datas;
    
    //Ouverture du fichier rawdata.txt pour la lecture des données
    std::ifstream rawdata_file("rawdata.txt");
    
    //Extraction des données du fichier rawdata.txt
    while(!rawdata_file.eof()){

        std::string latitude;
        std::string longitude;
        std::string station_id;
        std::string temperature;
        std::string timestamp;
            
        /* Extraction de chaque données sur une ligne
         * *************************************************************************************
         * À modifier si le fichier rawdata.txt change l'ordre des informations sur une ligne
         * Ordre actuel:
         * latitude, longitude, identifiant de station météo, température, timestamp
         * *************************************************************************************
        */
        
        rawdata_file>> latitude;
        rawdata_file>> longitude;
        rawdata_file>> station_id; //Pour que le curseur puisse se rendre ensuite à temperature
        if( (char) rawdata_file.peek() == '\n'){
            std::cout<<"Ligne incomplète"<<std::endl;
        }
        else{
            rawdata_file>> temperature; 
            rawdata_file>> timestamp;
            
            if(!rawdata_file.eof()){
                //Création et ajout d'un objet Datapoint dans le conteneur datas
                datas.insert(Datapoint(timestamp, std::stod(latitude), std::stod(longitude), std::stod(temperature)));
            }
        }
    }
    
    rawdata_file.close();
    
    //Ouverture du fichier candata.txt
    std::ofstream candata_file("candata.txt");
    
    //Écriture des données de chaque datapoint dans le fichier candata.txt
    std::set<Datapoint>::iterator it;
    for(it = datas.begin() ; it!= datas.end() ; it++){
        candata_file <<it->getTimestamp()<<" "<<it->getLatitude()<<" "<<it->getLongitude()<<" "<<it->getTemperature()<<std::endl;
    }
    
    candata_file.close();
}
