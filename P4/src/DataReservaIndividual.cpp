#include "../include/DataReservaIndividual.h"


DataReservaIndividual::DataReservaIndividual(int codigo, DtFechaHora* CheckIn ,DtFechaHora* CheckOut, EstadoReserva estado ,float costo, int numHab, DataHuesped* huesped):DataReserva(codigo, CheckIn ,CheckOut,  estado , costo, numHab, huesped){
    this->DTH = huesped ;

}



DataHuesped* DataReservaIndividual::getHuesped(){
    return this->DTH ; 

}


DataReservaIndividual::~DataReservaIndividual(){

    
}
