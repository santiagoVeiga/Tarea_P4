#include "Reserva.h"
#include "DataReservaGrupal.h"


class ReservaGrupal: public Reserva{
private:
    map<string, Huesped*> huespedes ; 
public:
    float getCosto();
    ReservaGrupal(int, DtFechaHora*,DtFechaHora*,EstadoReserva,Huesped*, map<string, Huesped*>, Habitacion*);
    ~ReservaGrupal();
    DataReservaGrupal* GetDataReserva();


};
