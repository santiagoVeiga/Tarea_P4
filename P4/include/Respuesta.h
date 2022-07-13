#ifndef RESPUESTA_H
#define RESPUESTA_H

#include "Calificacion.h"


class Calificacion;

class Respuesta{
private:
    string com;
    Calificacion * cal;

public:
    Respuesta(string, Calificacion*);
};

#endif