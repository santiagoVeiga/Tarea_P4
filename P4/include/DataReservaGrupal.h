#ifndef DATARESERVAGRUPAL_H
#define DATARESERVAGRUPAL_H

#include "DataReserva.h"

class DataReservaGrupal:public DataReserva{
private:
    // int fmsd ; 
    // DtFechaHora* CheckIn ; 
    // DtFechaHora* CheckOut;
    // EstadoReserva estado ; 
    // float costo; 
    // int numHab; 
    set<DataHuesped*> conjDTHues;

public:
    DataReservaGrupal();
    DataReservaGrupal(int, DtFechaHora*,DtFechaHora*,EstadoReserva,float, int, set<DataHuesped*>,DataHuesped*);
    set<DataHuesped*> getSetDTH();
    ~DataReservaGrupal(); 
};

#endif