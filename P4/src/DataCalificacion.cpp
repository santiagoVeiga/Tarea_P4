#include "../include/DataCalificacion.h"

DataCalificacion::DataCalificacion(){
    cal = 0;
    com = "";
}
DataCalificacion::~DataCalificacion(){

}

string DataCalificacion::getComentario(){
    return com;
}
int DataCalificacion::getCalificacion(){
    return cal;
}


DataCalificacion::DataCalificacion(string com, int cal){
    this->cal = cal;
    this->com = com;
}