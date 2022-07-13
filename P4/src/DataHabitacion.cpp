#include "../include/DataHabitacion.h"

int DataHabitacion::getCapacidad(){
    return capacidad;
}

int DataHabitacion::getNumero(){
    return numero;
}

float DataHabitacion::getPrecio(){
    return precio;
}

DataHabitacion::DataHabitacion(int numero,float precio,int capacidad){
    this->numero = numero ; 
    this->precio = precio ; 
    this->capacidad = capacidad ; 
}


DataHabitacion::~DataHabitacion(){


}