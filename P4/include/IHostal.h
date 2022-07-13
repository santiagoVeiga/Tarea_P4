#ifndef IHostal_H
#define IHostal_H


#include "Hostal.h"
#include "DataHostalExtendido.h"
#include "DataHabitacion.h"
#include "DataReserva.h"
#include "DtFechaHora.h"
#include <set>

class IHostal //interfaz
{

public:

	virtual void RegistrarHostal(DataHostal*) = 0;
	//virtual void ConsultarHostal() = 0;
	virtual void ConsultarTop3Hostales() = 0;
	virtual void NuevaHabitacion(DataHabitacion*)=0;
	//virtual void AltaDeHabitacion(DataHabitacion*) = 0;
	virtual set<DataHostal*> ListarHostales() = 0;
	virtual void SeleccionarHostal(string) = 0;
	virtual void ConfirmarAltaHabitacion() = 0;
	virtual void CancelarAltaHabitacion() = 0;
	virtual void SetNombreHostalSeleccionado(string) = 0;
	virtual void ConfirmarAltaEmpleadoAHostal() = 0;
	virtual void SeleccionarHabitacion(int) = 0;
	virtual Hostal * getHostalSeleccionado() = 0;
	virtual Habitacion * getHabitacionSeleccionada() = 0;
	virtual DataHostalExtendido* MostrarHostal()=0;

	virtual ~IHostal(){};
	virtual set<DataHostalExtendido*> ListarHostalesDetallado() = 0;
	virtual set<DataHabitacion*> ListarHabitacionesDisponibles(DtFechaHora*, DtFechaHora*) = 0;
	virtual set<DataReserva*> ListarReservas() = 0 ;
	virtual set<DataReserva*> ListarReservasNoCanceladas() =0;
	virtual void CerrarReserva(int) = 0 ;
	virtual Reserva * GetReservaAuxRegistrarEstadia() = 0 ;
};

#endif

//las operaciones de las interfaces son virtual