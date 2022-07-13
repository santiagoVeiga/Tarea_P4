#include "../include/Empleado.h"

DataEmpleado* Empleado::GetDataEmpleado(){
    if (this->HostalTrabaja == NULL){
        return new DataEmpleado(this->getNombre(), this->getEmail(), this->getContrasena(), this->cargo, "No trabaja en un Hostal");
    }
    else
        return new DataEmpleado(this->getNombre(), this->getEmail(), this->getContrasena(), this->cargo, this->HostalTrabaja->getNomHos());
}

string Empleado::getNombreHostalParaCualTrabaja(){
    return this->HostalTrabaja->getNomHos();
}

bool Empleado::EstaTrabajandoEnUnHostal(){
    return true;
}

void Empleado::Notificar(int, std::string){
    
}

Empleado::Empleado(DataEmpleado * usu) : Usuario(usu->getNomUsu(), usu->getEmailUsu(), usu->getContrasena()){ 
    this->cargo = usu->getCargo();
}

Hostal* Empleado::GetHostal(){
    return this->HostalTrabaja;
}

void Empleado::SetHostal(Hostal* hos){
    this->HostalTrabaja = hos;
}

void Empleado::setCargo(int cargo){

}

Empleado::~Empleado(){

}


Empleado::Empleado(string n , string j, string f):Usuario(n, j, f){

}