#ifndef _DATARESERVA_H
#define _DATARESERVA_H

#include "DtFechaHora.h"
#include "EstadoReserva.h"
#include "DataHuesped.h"
#include <set>


class DataReserva {
	protected:
		int codigo;
		DtFechaHora *checkIN;
		DtFechaHora *checkOUT;
		EstadoReserva estado;
		float costo;
		int numeroDeHabitacion ;
		DataHuesped * huesHReserva;

	public:
		DataReserva(){};
		DataReserva(int, DtFechaHora*, DtFechaHora*, EstadoReserva, float, int, DataHuesped*);
		int getCodigo();
		DtFechaHora* getCheckIn(); 
		DtFechaHora* getCheckOut(); 
		EstadoReserva getEstado(); 
		float getCosto();
		int getNumeroHabitacion(); 
		string getNombreReserva();

		virtual ~DataReserva(){} ;
		

};

#endif