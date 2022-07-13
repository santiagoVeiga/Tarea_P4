#include "../include/DataEmpleado.h"

EnumCargo DataEmpleado::getCargo(){
    return cargo;
}

string DataEmpleado::getHostalTrabaja(){
    return NombreHostal;
} 

DataEmpleado::DataEmpleado(string nom, string email, string pass, int cargo, string hostal) : DataUsuario(nom,email,pass){
    EnumCargo Ecargo;
    switch(cargo){
        case 0:
            Ecargo = Limpieza;
            break;
        case 1: 
            Ecargo = Administracion;
            break;
        case 2: 
            Ecargo = Recepcion;
            break;
        case 3:
            Ecargo = Infraestructura;
            break;
    }
    this->cargo = Ecargo;
    this->NombreHostal = hostal;
}

DataEmpleado::~DataEmpleado(){

}



void DataEmpleado::Funcion(){
    
    
}