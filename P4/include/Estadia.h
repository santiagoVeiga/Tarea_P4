#ifndef ESTADIA_H
#define ESTADIA_H

#include "DtFechaHora.h"
#include "DataEstadia.h"
#include "Reserva.h"
#include "Huesped.h"
#include "Calificacion.h"

class Reserva;
class Calificacion;
class Huesped ;


class Estadia{
private:
    DtFechaHora Ingreso;
    DtFechaHora Egreso;
    int codigoPromo;
    Reserva * resEst;
    Huesped * hues;
    Calificacion * cal = NULL;

public:
    Estadia(DtFechaHora*, int, Reserva*, Huesped*);
    void FinalizarEstadia();
    DataEstadia * getDatosEstadia();
    Calificacion * getCalificacion();
    ~Estadia();
    DataEstadia* GetDataEstadia(); 
};

#endif