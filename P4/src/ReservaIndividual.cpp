#include "../include/ReservaIndividual.h"

ReservaIndividual::~ReservaIndividual(){
    delete checkIn;
    delete checkOut;
}

float ReservaIndividual::getCosto(){
    return  0 ; 
}

ReservaIndividual::ReservaIndividual(int cod, DtFechaHora* ingreso, DtFechaHora* egreso, EstadoReserva est, Huesped * hues, Habitacion * hab):Reserva(cod,ingreso, egreso, est, hues, hab){
}

DataReservaIndividual * ReservaIndividual::GetDataReserva(){
    return new DataReservaIndividual(this->codigoReserva,checkIn,checkOut,Estado,getCosto(),habReserva->getNumHab(),huesHReserva->getDataHuesped());
}