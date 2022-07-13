#ifndef REGISTROSCONTROLLER_H
#define REGISTROSCONTROLLER_H


#include <string>
#include <set>
#include <map>
#include "IRegistros.h"
#include "DtFechaHora.h"
#include "DataHostal.h"
#include "HostalController.h"
#include "DataCalificacionNotificada.h"



using namespace std;

class RegistrosController : public IRegistro {
private:
	//implementacion singleton
	static RegistrosController* instancia; //static para que el atributo sea de clase
	DtFechaHora* fechaSistema;
	RegistrosController();
	bool statusDatosDePrueba;
	int TipoReserva;
	DtFechaHora *fechaInicio, *fechaFinal;
	int numRes=0;

public:
	//implementacion singleton
	static RegistrosController* getInstanciaRegistro(); //static para que la operacion sea de clase

	//operaciones 
	//caso de uso Realizar Reserva
	//void ConsultaDeReserva();
	//void BajaDeReserva();
	void RegistrarEstadia(int);
	void MostrarEstadia();
	void FinalizarEstadia();
	void CambiarFechaDeSistema(DtFechaHora*);
	void CargarDatosPrueba();
	void SeleccionarEstadia(DataEstadia*);
	DataCalificacion* MostrarCalificacion();
	DataRespuesta* MostrarRespuesta();
	DataReserva* MostrarReserva();
	set<DataReserva*> ListarReservas();

	DataReserva* SeleccionarReserva(int);
	
	void ElegirReserva(DataReserva*);
	void ConfirmarBaja();
	void CancelarBaja();
	set<DataEmpleado*> ListarEmpleados();
	set<DataCalificacionNotificada*> ListarCalificaciones(Empleado*) ;
	DtFechaHora FechaDeSistema();
	void TipoDeReserva(int);
	void ingresarPeriodoFecha(DtFechaHora*,DtFechaHora*);
	void ConfirmarAltaReserva();
	void CancelarAltaReserva();
	~RegistrosController();
	void CrearEstadia(int);

};

#endif