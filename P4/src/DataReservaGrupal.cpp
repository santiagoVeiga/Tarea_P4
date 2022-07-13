#include "../include/DataReservaGrupal.h" 

DataReservaGrupal::DataReservaGrupal(){} 


DataReservaGrupal::DataReservaGrupal(int codigo, DtFechaHora* CheckIn ,DtFechaHora* CheckOut, EstadoReserva estado ,float costo, int numHab, set<DataHuesped*> setDTHues,DataHuesped * huesped):DataReserva(codigo,  CheckIn ,CheckOut,  estado , costo, numHab, huesped){
    conjDTHues = setDTHues ;

}


set<DataHuesped*> DataReservaGrupal::getSetDTH(){
    return this->conjDTHues ;
}

DataReservaGrupal::~DataReservaGrupal(){
    set<DataHuesped*>::iterator itr;
    for(itr =conjDTHues.begin(); itr!=conjDTHues.end(); itr++)
        delete *itr;
} 