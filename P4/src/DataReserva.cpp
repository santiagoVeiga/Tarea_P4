#include "../include/DataReserva.h"

DataReserva::DataReserva(int codigo, DtFechaHora *CheckIn, DtFechaHora *CheckOut, EstadoReserva estado, float costo, int hab, DataHuesped* huesped){
    this->codigo = codigo;
    this->checkIN = CheckIn;
    this->checkOUT = CheckOut;
    this->estado = estado;
    this->costo = costo;
    this->numeroDeHabitacion = hab;
    this->huesHReserva=huesped;
}


int DataReserva::getNumeroHabitacion(){
    return this->numeroDeHabitacion ; 
}

EstadoReserva DataReserva::getEstado(){
    return estado;
}

int DataReserva::getCodigo(){
    return codigo;
}

float DataReserva::getCosto(){
    return costo;
}

string DataReserva::getNombreReserva(){
    return huesHReserva->getNomUsu(); }

DtFechaHora *DataReserva::getCheckIn(){
    return checkIN;
}

DtFechaHora* DataReserva::getCheckOut(){
    return checkOUT;
}

