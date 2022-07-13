#ifndef IREGISTROS
#define IREGISTROS


#include "DtFechaHora.h"
#include "DataEstadia.h"
#include "DataReserva.h"
#include "DataCalificacionNotificada.h"
#include "DataEmpleado.h"
#include "DataCalificacion.h"
#include "DataRespuesta.h"
#include "Empleado.h"






class IRegistro
{

public:
	//virtual void RealizarReserva() = 0;
	//virtual void ConsultaDeReserva() = 0;
	//virtual void BajaDeReserva() = 0;

	virtual void RegistrarEstadia(int) = 0;
	
	virtual void MostrarEstadia() = 0;
	virtual void FinalizarEstadia() = 0;
	virtual void CambiarFechaDeSistema(DtFechaHora*) = 0;
	virtual void CargarDatosPrueba() = 0;
	virtual void SeleccionarEstadia(DataEstadia*) = 0;
	virtual DataCalificacion* MostrarCalificacion() = 0;
	virtual DataRespuesta* MostrarRespuesta() = 0;
	virtual DataReserva* MostrarReserva() = 0;
	virtual set<DataReserva*> ListarReservas() = 0; 
	virtual void ElegirReserva(DataReserva*) = 0;
	virtual void ConfirmarBaja() = 0;
	virtual void CancelarBaja() = 0;
	virtual set<DataEmpleado*> ListarEmpleados() = 0;
	virtual set<DataCalificacionNotificada*> ListarCalificaciones(Empleado*) = 0; 
	virtual void TipoDeReserva(int)=0;
	virtual void ingresarPeriodoFecha(DtFechaHora*,DtFechaHora*) = 0;
	virtual void ConfirmarAltaReserva()=0;
	virtual void CancelarAltaReserva() = 0;
	virtual DtFechaHora FechaDeSistema()=0;
	virtual DataReserva* SeleccionarReserva(int) = 0;
	virtual ~IRegistro(){} ; 

};
#endif