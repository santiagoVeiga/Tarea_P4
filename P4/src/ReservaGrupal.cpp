#include "../include/ReservaGrupal.h" 

ReservaGrupal::~ReservaGrupal(){
    delete checkIn;
    delete checkOut;
}

ReservaGrupal::ReservaGrupal(int cod, DtFechaHora* ing, DtFechaHora* eg, EstadoReserva est, Huesped* hues , map<string, Huesped*> conjHues, Habitacion* hab) : Reserva(cod, ing, eg, est, hues, hab){
    this->huespedes = conjHues;
}

float ReservaGrupal::getCosto(){
    return 0; 
}

DataReservaGrupal* ReservaGrupal::GetDataReserva(){
    
    //conjunto de data huespedes a partir de un conjunto de huespedes 
    set<DataHuesped*> huespedesReserva ; 
    map<string, Huesped*>::iterator iter ; 
    for (iter = huespedes.begin() ; iter != huespedes.end(); iter++){
        huespedesReserva.insert(iter->second->getDataHuesped()) ; 
    }

//DataReservaGrupal(int, DtFechaHora*,DtFechaHora*,EstadoReserva,float, int, set<DataHuesped*>,DataHuesped*)

    return new DataReservaGrupal(this->getCodigo(), this->getCheckIn(), this->getCheckOut(), this->getEstado(), this->getCosto(), this->getHabitacion()->getNumHab(), huespedesReserva, huesHReserva->getDataHuesped());
}
