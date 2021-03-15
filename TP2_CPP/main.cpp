#include "datapoint.h"

#include <iostream>
#include <string>
#include <fstream>
#include <set>

int main(){
    //Création du conteneur pour les objets Datapoint
    std::set<Datapoint> datas;
    
    //Ouverture du fichier rawdata.txt pour la lecture des données
    std::ifstream rawdata_file("rawdata.txt");
    
    std::cout<<"Informations contenues dans rawdata.txt:"<<std::endl;
    while(!rawdata_file.eof()){
        
        double latitude;
        double longitude;
        std::string station_id;
        double temperature;
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
        rawdata_file>> temperature;
        rawdata_file>> timestamp;
            
        if(!rawdata_file.eof()){
            //Création et ajout d'un objet Datapoint dans le conteneur datas
            datas.insert(Datapoint(timestamp, latitude, longitude, temperature));
            std::cout<<latitude<<" "<<longitude<<" "<<station_id<<" "<<temperature<<" "<<timestamp<<std::endl;
        }
    }
    rawdata_file.close();
    
    std::cout<<"Informations qui seront dans candata.txt:"<<std::endl;
    std::set<Datapoint>::iterator it;
    for(it = datas.begin() ; it!= datas.end() ; it++){
        std::cout<<it->printData()<<std::endl;
    }
    
    
}
