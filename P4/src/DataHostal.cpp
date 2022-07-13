#include "../include/DataHostal.h"

DataHostal::DataHostal(string nombre, string dir, string tel, float prom){
    this->nombre = nombre;
    this->direccion = dir;
    this->telefono = tel;
    this->promedio = prom;
}

DataHostal::DataHostal(string nombre, string dir, string tel){
    this->nombre = nombre;
    this->direccion = dir;
    this->telefono = tel;
}

string DataHostal::getNombre(){
    return this->nombre;
}

string DataHostal::getDireccion(){
    return this->direccion;
}

string DataHostal::getTelefono(){
    return this->telefono;
}

float DataHostal::getPromedio(){
    return this->promedio ; 
}


DataHostal::~DataHostal(){

}