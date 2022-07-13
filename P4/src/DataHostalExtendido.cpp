#include "../include/DataHostalExtendido.h"

DataHostalExtendido::DataHostalExtendido(string nom,string dir,string tel , float prom ,set<DataHabitacion*> colHab, set<DataCalificacion*> colCal ):DataHostal(nom,dir,tel,prom){
    this->califs = colCal;
    this->habitaciones = colHab;
}


set<DataCalificacion*> DataHostalExtendido::getCalifs(){
    return califs;
}


set<DataHabitacion*> DataHostalExtendido::getHabs(){
    return habitaciones;
}

DataHostalExtendido::~DataHostalExtendido(){
    //borrar set de data habitacion y data calificacion
    set<DataCalificacion*>::iterator itr;
    for(itr = califs.begin(); itr != califs.end(); itr++)
        delete *itr;
    set<DataHabitacion*>::iterator iter;
    for(iter = habitaciones.begin(); iter != habitaciones.end(); iter++)
        delete *iter;
}