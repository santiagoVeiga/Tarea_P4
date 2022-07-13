#ifndef HOSTAL_H
#define HOSTAL_H

#include "DataHostalExtendido.h"
#include "DtFechaHora.h"
#include "Habitacion.h"
#include "Empleado.h"
#include "Huesped.h"

#include <string>
#include <map>
#include <set>

class Empleado ; 
class Habitacion; // forward declaration de Habitacion
class DataHostalExtendido;


using namespace std;

class Hostal {
private:
    string nombreHostal;
    string direccion;
    string telefono;
    map<int, Habitacion*> HabitacionesParaUnHostal;
    map<string, Empleado*> EmpleadosParaUnHostal;
    set<Estadia*> EstadiasParaUnHostal ; 


public:
    DataHostal* getDataHostal();
    DataHostalExtendido * getDataHostalExtendido();
    Hostal(string, string, string);
    Hostal(DataHostal*);
    bool ExisteHabitacion(int); // confirma que existe ese numero de habitacion en el hostal
    void AnadirHabitacion(Habitacion*); //aniade la habitacion al hostal, usada por ConfirmarAlta
    ~Hostal();
    //getters
    string getNomHos();
    string getDirHos();
    string getTelHos();
    map<int, Habitacion*> GetHabitaciones();
    set<DataHabitacion*> getHabsDisp(DtFechaHora*,DtFechaHora*);

    //setters
    void setNomHos(string);
    void setDirHos(string);
    void setTelHos(string);
    void SetEmpleado(Empleado*); //agrega el empleado a la coleccion EmpleadosParaUnHostal
    float CalcularPromedioCal();
    void AgregarEstadia(Estadia*);
    set<DataEstadia*> getSetDataEstadias(); 
            


};

#endif