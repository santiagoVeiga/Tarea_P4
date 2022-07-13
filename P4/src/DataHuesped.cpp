#include "../include/DataHuesped.h"

bool DataHuesped::getEsFinger(){
    return esFinger;
}


DataHuesped::DataHuesped(string nom,string email,string pass,bool esF) : DataUsuario(nom, email, pass){
    this->esFinger = esF;
}

DataHuesped::~DataHuesped(){

}


void DataHuesped::Funcion(){
    

}
