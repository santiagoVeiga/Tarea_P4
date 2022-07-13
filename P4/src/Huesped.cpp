#include "../include/Huesped.h"

DataHuesped* Huesped::getDataHuesped(){
    return new DataHuesped(this->getNombre(), this->getEmail(), this->getContrasena(), this->esFinger);
}

bool Huesped::getEsFinger(){
    return this->esFinger;
}


Huesped::~Huesped(){

}


void Huesped::setEsFinger(bool finger){
    this->esFinger = finger;
}

Huesped::Huesped(DataHuesped* usu) : Usuario(usu->getNomUsu(), usu->getEmailUsu(), usu->getContrasena()){
    this->esFinger = usu->getEsFinger();
}

void Huesped::agregarAlSetEstadias(Estadia* est){
    SetEstadiasHuesped.insert(est);
}
