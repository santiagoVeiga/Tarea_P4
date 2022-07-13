#ifndef CALIFICACION_H
#define CALIFICACION_H


#include "DtFechaHora.h"
#include "DataCalificacion.h"
#include "Respuesta.h"
#include <string>

using namespace std;

class Respuesta;

class Calificacion{
private:
    int cal;
    //DtFechaHora Fcom;
    string comentario;
    Respuesta * res = NULL;

public:
    DataCalificacion* getDataCalificacion();
    int getCalif();

};

#endif