#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include "DataHabitacion.h"
#include "DataCalificacion.h"
#include "Hostal.h"
#include "Reserva.h"
#include <map>

class Hostal; //forward declaration de Hostal
class Reserva;


using namespace std;

class Habitacion{
private:
    int numeroHabitacion;
    float precioHabitacion;
    int capacidadHabitacion;
    Hostal* hostal = NULL; 
    map<int, Reserva*> ConjRes; 

public:
    DataHabitacion* getDataHabitacion();
    Habitacion(int, float, int);
    Habitacion(int, float, int, Hostal*); //constructor utilizado en ConfirmarAlta

    int getNumHab();
    int getPrHab();
    int getCapHab();
    map<int,Reserva*> getConjRes();


    void setNumHab(int);
    void setPrHab(float);
    void setCapHab(int);
    void SetHostal(Hostal*);
    void AnadirReserva(Reserva*);

    set<DataCalificacion*> getCalificacionesHabitacion();
    Habitacion(DataHabitacion*);

    ~Habitacion();
};


#endif