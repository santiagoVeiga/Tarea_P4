#ifndef HOSTALCONTROLLER_H
#define HOSTALCONTROLLER_H
#include <string>
#include <set>
#include <map>

#include "DataHostalExtendido.h"
#include "DataHabitacion.h"
#include "DtFechaHora.h"
#include "IHostal.h"
#include "Hostal.h"
#include "UserController.h"
#include "Huesped.h"
#include "Empleado.h"
#include "DataReservaIndividual.h"
#include "DataReservaGrupal.h"
#include "ReservaIndividual.h"
#include "ReservaGrupal.h"






using namespace std;   


class HostalController : public IHostal { // HostalController realiza la intefaz IHostal
	private:
		//implementacion singleton
		static HostalController* instancia; //static para que el atributo sea de clase
		HostalController();
		map<string, Hostal*> col; // la clave es el nombre
		string nombre_hostal_seleccionado ; 
		DataHabitacion* DTHabitacionNueva = NULL;
		int habitacionRecordada;
		Reserva* ReservaAuxRegistrarEstadia ; 
		

	public:
		//implementacion singleton
		static HostalController* getInstanciaHostal(); //static para que la operacion sea de clase


		//operaciones
		void RegistrarHostal(DataHostal*);
        //void ConsultarHostal();
		void ReservasDelHostal(); //devuelve un set de dataReserva
		void ConsultarTop3Hostales();
		float PromedioHostal(Hostal*);
		DataHostalExtendido* MostrarHostal();
		
		set<DataHabitacion*> ListarHabitacionesDisponibles(DtFechaHora*, DtFechaHora*); //devuelve un set de dataHabitacionm
		void SeleccionarHostal(string); 
		set<DataHostalExtendido*> ListarHostalesDetallado(); //dfevuelve un set de dataHostal
		void ConfirmarAltaHabitacion(); 
		void CancelarAltaHabitacion(); 

		Hostal * getHostalSeleccionado();
		Habitacion * getHabitacionSeleccionada();

		void SeleccionarHabitacion(int numHab);
		void ConfirmarAltaEmpleadoAHostal(); 
		void NuevaHabitacion(DataHabitacion*);
		string GetNombreHostalSeleccionado();
		void SetNombreHostalSeleccionado(string);
		set<DataHostal*> ListarHostales();
		set<DataReserva*> ListarReservas();
		set<DataReserva*> ListarReservasNoCanceladas();
		void CerrarReserva(int); 
		Reserva* GetReservaAuxRegistrarEstadia(); 

	
	
	

		~HostalController();


};

#endif
