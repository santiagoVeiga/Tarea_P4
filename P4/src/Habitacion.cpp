#include "../include/Habitacion.h"

int Habitacion::getNumHab(){
    return numeroHabitacion;
}

int Habitacion::getPrHab(){
    return precioHabitacion;
}

int Habitacion::getCapHab(){
    return capacidadHabitacion;
}

map<int, Reserva*> Habitacion::getConjRes(){
    return ConjRes;
}

void Habitacion::setNumHab(int nom){
    this->numeroHabitacion = nom;
}

void Habitacion::setPrHab(float pr){
    this->precioHabitacion = pr;
}

void Habitacion::setCapHab(int cap){
    this->capacidadHabitacion = cap;
}

void Habitacion::SetHostal(Hostal * hos){
    this->hostal = hos;
}

DataHabitacion* Habitacion::getDataHabitacion(){
    return new DataHabitacion(this->numeroHabitacion, this->precioHabitacion, this->capacidadHabitacion);
}

set<DataCalificacion*> Habitacion::getCalificacionesHabitacion(){
    map<int, Reserva*>::iterator itr;
    set<DataCalificacion*> nuevo;
    if(!(ConjRes.empty())){ // Si hay alguna reserva en habitacion
        for(itr = ConjRes.begin(); itr != ConjRes.end(); itr++){//para cada reserva
            if(itr->second->getEstadia() != NULL)//si tiene estadia
                if(itr->second->getEstadia()->getCalificacion()!= NULL) //si tiene calificacion
                    nuevo.insert(itr->second->getEstadia()->getCalificacion()->getDataCalificacion()); // get DTCal
        }
    }
    return nuevo;
}

Habitacion::Habitacion(int num, float precio, int capa){
    this->numeroHabitacion = num;
    this->precioHabitacion = precio;
    this->capacidadHabitacion = capa;
}

Habitacion::Habitacion(int num, float precio, int capa, Hostal* hos){
    this->numeroHabitacion = num;
    this->precioHabitacion = precio;
    this->capacidadHabitacion = capa;
    this->hostal = hos ; 
}

void Habitacion::AnadirReserva(Reserva* res){
    ConjRes.insert({res->getCodigo(), res});
}

Habitacion::Habitacion(DataHabitacion* hab){
    this->numeroHabitacion = hab->getNumero();
    this->precioHabitacion = hab->getPrecio();
    this->capacidadHabitacion = hab->getCapacidad();
}

Habitacion::~Habitacion(){
    map<int, Reserva*>::iterator itr;
    for(itr = ConjRes.begin(); itr !=ConjRes.end(); itr++){
        delete itr->second;
    }
}