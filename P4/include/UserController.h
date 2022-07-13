#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H


#include <string>
#include <set>
#include <map>
#include "IUser.h"
#include "Huesped.h"
#include "Empleado.h"
#include "DataReserva.h"
#include "DataHostal.h"
#include "HostalController.h"
#include "DataUsuario.h"

using namespace std;


class UserController : public IUser { // realiza la intefaz IUser
private:
	//implementacion singleton
	static UserController* instancia; //static para que el atributo sea de clase
	UserController();
	map<string, Usuario*> colUsuarios; // la clave es mail
	map<string, Empleado*> colEmpleados;
	map<string, Huesped*> colHuespedes;
	DataUsuario* DTusuario_ingresado = NULL;
	string mailEmpleadoSeleccionado = ""; //clave del empleado seleccionado
	set<string> HuespedesReserva;

public:
	//implementacion singleton
	static UserController* getInstanciaUser(); //static para que la operacion sea de clase


	//operaciones

	void AltaDeUsuario(DataUsuario*);
	void ConfirmarAltaUsuario();
	void CancelarAltaUsuario();
	set<DataEmpleado*>ListarEmpleadosSinHostal();
	void ElegirEmpleadoSinHostal(string);
	void CancelarAltaEmpleadoAHostal();
	void IngresarMail(string);
	void IngresarMailHuespedes(string );
	bool ExisteMail(string);
	set<DataReserva*> ListarReservasNoCanceladas(DataHostal*, string);
	void ElegirReserva(DataReserva*);
	set<string> ListarUsuarios();
	DataUsuario * MostrarUsuario(string);
	void Suscribir();
	void Desuscribir();
	set<DataHuesped*> listarHuespedes();
	map<string, Empleado*> GetColEmpleados();
	Huesped* getHuespedSeleccionado();
	map<string, Huesped*> getHuespedesRG();
	string GetMailEmpleadoSeleccionado();
	~UserController();
	Empleado* DevolverEmpleado(string);

};

#endif