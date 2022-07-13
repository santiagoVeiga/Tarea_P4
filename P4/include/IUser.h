#ifndef IUSER
#define IUSER

#include "DataHuesped.h"
#include "DataReserva.h"
#include "DataHostal.h"
#include <map>
#include <set>
#include "Empleado.h"

class IUser{
public:


	virtual void AltaDeUsuario(DataUsuario*) = 0 ;
	virtual void ConfirmarAltaUsuario() = 0 ;
	virtual void CancelarAltaUsuario() = 0 ;
	virtual set<DataEmpleado*>ListarEmpleadosSinHostal() = 0 ;
	virtual void ElegirEmpleadoSinHostal(string) = 0 ;
	virtual void CancelarAltaEmpleadoAHostal() = 0 ;
	virtual void IngresarMail(string) = 0 ;
	virtual void IngresarMailHuespedes(string)=0;
	virtual bool ExisteMail(string) = 0;
	virtual set<DataReserva*> ListarReservasNoCanceladas(DataHostal*, string) = 0 ;
	virtual void ElegirReserva(DataReserva*) = 0 ;

	virtual set<string> ListarUsuarios() = 0 ;
	virtual DataUsuario* MostrarUsuario(string) = 0;

	virtual set<DataHuesped*> listarHuespedes()=0;
	virtual Huesped* getHuespedSeleccionado()=0;
	virtual map<string, Huesped*> getHuespedesRG()=0;
	
	virtual void Suscribir() = 0 ;
	virtual void Desuscribir() = 0 ;
	virtual map<string, Empleado*> GetColEmpleados() = 0 ;
	virtual string GetMailEmpleadoSeleccionado() = 0 ;
	virtual ~IUser(){};
	virtual Empleado* DevolverEmpleado(string)= 0;
};

#endif