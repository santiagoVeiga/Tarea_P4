#include "../include/DataEstadia.h"


DataEstadia::DataEstadia(DtFechaHora* ing , DtFechaHora* eg, int cod , DataHostal* hos, DataHabitacion* hab , DataHuesped* hues ){
    this->Ingreso = ing;   
     this->Egreso = eg;
    this->codigoPromo = cod;
    this->hos = hos ; 
    this->hab = hab ; 
    this->hues = hues ; 
}


