#ifndef HUESPED_H
#define HUESPED_H

#include "Usuario.h"
#include "DataHuesped.h"
#include "Estadia.h"

class Estadia ; 

class Huesped:public Usuario{
private:
    bool esFinger;
    set<Estadia*> SetEstadiasHuesped ; 

public:
    DataHuesped* getDataHuesped();
    bool getEsFinger();
    Huesped(DataHuesped*);
    ~Huesped();
    //void Funcion(); 
    void setEsFinger(bool) ; 
    void agregarAlSetEstadias(Estadia*); 
};

#endif