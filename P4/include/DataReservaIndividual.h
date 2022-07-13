#ifndef DATARESERVAINDIVIDUAL_H
#define DATARESERVAINDIVIDUAL_H

#include "DataReserva.h"

class DataReservaIndividual : public DataReserva{
private:
    DataHuesped* DTH ; 

public:
    DataHuesped* getHuesped();
    DataReservaIndividual(int,DtFechaHora*,DtFechaHora*,EstadoReserva,float,int,DataHuesped*);
    ~DataReservaIndividual();
};

#endif