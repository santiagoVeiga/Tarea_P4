#ifndef DATAESTADIA_H
#define DATAESTADIA_H

#include "DtFechaHora.h"
#include "DataHostal.h"
#include "DataHabitacion.h"
#include "DataHuesped.h"




class DataEstadia{
private:
	DtFechaHora Ingreso;
	DtFechaHora Egreso;
	int codigoPromo;
	DataHostal* hos ; 
	DataHabitacion* hab ; 
	DataHuesped* hues ; 

public:
	DataEstadia(DtFechaHora*, DtFechaHora*, int, DataHostal*, DataHabitacion*, DataHuesped*);
};

#endif