#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H


using namespace std;

#include "Reserva.h"
#include "DataReservaIndividual.h"


class ReservaIndividual: public Reserva{
private:
public:
    float getCosto();
    ReservaIndividual(int, DtFechaHora*, DtFechaHora*, EstadoReserva, Huesped *, Habitacion *);
    ~ReservaIndividual();
    DataReservaIndividual* GetDataReserva();

};


#endif