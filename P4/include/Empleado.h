#ifndef EMPLEADO_H  
#define EMPLEADO_H


using namespace std;

#include "Usuario.h"
#include "DataEmpleado.h"
#include "Hostal.h"

class Hostal ; 

class Empleado: public Usuario{
private:
    EnumCargo cargo;
    bool suscrito;
    Hostal* HostalTrabaja = NULL;

public:
    Empleado(string ,string, string); 
    Empleado(DataEmpleado*);
    DataEmpleado* GetDataEmpleado();
    string getNombreHostalParaCualTrabaja();
    bool EstaTrabajandoEnUnHostal();
    void Notificar(int, string);
    Hostal* GetHostal();
    void SetHostal(Hostal*);
    void setCargo(int);
    ~Empleado();
    //void Funcion(); 
};


#endif