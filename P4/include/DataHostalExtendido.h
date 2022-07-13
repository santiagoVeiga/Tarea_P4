#ifndef DATAHOSTALEXTENDIDO_H
#define DATAHOSTALEXTENDIDO_H

#include "DataHostal.h"
#include "Calificacion.h"
#include "Habitacion.h"
#include <set>

class Habitacion;
class Calificacion;


class DataHostalExtendido: public DataHostal{
private:
    set<DataCalificacion*> califs;
    set<DataHabitacion*> habitaciones;

public:
    DataHostalExtendido(string,string,string, float,set<DataHabitacion*>, set<DataCalificacion*>);
    set<DataCalificacion*> getCalifs();
    set<DataHabitacion*> getHabs();
    ~DataHostalExtendido();

};

#endif