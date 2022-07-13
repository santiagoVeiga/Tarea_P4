#include "../include/Calificacion.h"


DataCalificacion* Calificacion::getDataCalificacion(){
    return new DataCalificacion(this->comentario, this->cal);
}

int Calificacion::getCalif(){
    return cal;
}
