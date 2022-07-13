#include "../include/Estadia.h"

Calificacion * Estadia::getCalificacion(){
    return cal;
}

Estadia::Estadia(DtFechaHora* eg, int codPr, Reserva* res, Huesped* hues){
    this->Egreso = eg;
    this->codigoPromo = codPr;
    this->resEst = res;
    this->hues = hues;
}

void Estadia::FinalizarEstadia(){

}

DataEstadia* Estadia::getDatosEstadia(){
    return new DataEstadia(this->Ingreso, this->Egreso, this->codigoPromo);
}

Estadia::~Estadia(){

}

DataEstadia* Estadia::GetDataEstadia(){

    
    DataEstadia* coso = new DataEstadia(Ingreso, Egreso, codigoPromo, hos->getDataHostal(), hab->getDataHabitacion(), hues->getDataHuesped());
    return coso ; 


}
