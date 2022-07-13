#include "../include/Reserva.h"

Reserva::Reserva(){}

Reserva::Reserva(int cod, DtFechaHora* ingreso, DtFechaHora* egreso, EstadoReserva est, Huesped * hues, Habitacion * hab){
    this->codigoReserva = cod;
    this->checkIn = ingreso;
    this->checkOut = egreso;
    this->Estado = est;
    this->habReserva = hab;
    this->huesHReserva = hues;
}

void Reserva::cerrarReserva(){ 
    Estado = EstadoReserva(1); 
}

bool Reserva::reservaDejaHabDisponible(DtFechaHora* ing,DtFechaHora* eg){
    return ((this->checkIn > eg ) || (ing > this->checkOut));
    
}

DataReserva * Reserva::getDataReserva(){
    return new DataReserva(codigoReserva, checkIn, checkOut, Estado, 0.0, habReserva->getNumHab(), huesHReserva->getDataHuesped());
}

Estadia * Reserva::getEstadia(){
    return est;
}

Habitacion* Reserva::getHabitacion(){ return habReserva;}


int Reserva::getCodigo(){return codigoReserva;}

DtFechaHora *Reserva::getCheckIn(){return checkIn;}

DtFechaHora *Reserva::getCheckOut(){return checkOut;}

EstadoReserva Reserva::getEstado(){return Estado;}

float Reserva::getCosto(){return 0.0;}

string Reserva::getNombreRegistra(){
    return huesHReserva->getNombre();
}

// void Reserva::setEstado(EstadoReserva state){
//     this->Estado = state ; 
// } 
