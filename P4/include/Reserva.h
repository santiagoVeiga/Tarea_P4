#ifndef RESERVA_H  
#define RESERVA_H

#include "DtFechaHora.h"
#include <string>
#include "EstadoReserva.h"
#include <set>
#include <map>
#include "DataReserva.h"
#include "Habitacion.h"
#include "Huesped.h"
#include "Estadia.h"

using namespace std;

class Habitacion;
class Estadia;
class Huesped;

class Reserva{
protected:
    int codigoReserva;
    DtFechaHora *checkIn;
    DtFechaHora* checkOut;
    EstadoReserva Estado = Abierta; 
    //float costoReserva;
    Habitacion * habReserva;
    Huesped * huesHReserva;
    Estadia * est = NULL;

public:
    Reserva();
    Reserva(int, DtFechaHora*, DtFechaHora*, EstadoReserva, Huesped*, Habitacion*);
    void cerrarReserva();
    bool reservaDejaHabDisponible(DtFechaHora*,DtFechaHora*);
    string getNombreRegistra();
    virtual DataReserva* getDataReserva();
    Estadia * getEstadia();
    Habitacion* getHabitacion();

    int getCodigo();
    DtFechaHora * getCheckIn();
    DtFechaHora * getCheckOut();
    EstadoReserva getEstado();
    virtual float getCosto();

    //void setEstado(EstadoReserva); 

    virtual ~Reserva(){};
};

#endif