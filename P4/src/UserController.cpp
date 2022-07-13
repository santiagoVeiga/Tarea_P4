#include "../include/UserController.h"
#include "../include/DataEmpleado.h"



using namespace std;

UserController* UserController::instancia = NULL;

UserController::UserController()
{
}

UserController* UserController::getInstanciaUser()
{
	if (instancia == NULL)
		instancia = new UserController();
	return instancia;
}

//---------------------------caso de uso alta de usuario------------------------------

void UserController::AltaDeUsuario(DataUsuario* DTUsuario)
{
	DTusuario_ingresado=DTUsuario;
}

void UserController::ConfirmarAltaUsuario(){

	DataEmpleado* DTEmpleado = dynamic_cast<DataEmpleado*>(DTusuario_ingresado);
	//Usuario* newU;
	if (DTEmpleado != NULL){
		Empleado* newU = new Empleado(DTEmpleado);
		colEmpleados.insert({newU->getEmail() ,newU}) ;
		DTEmpleado = NULL;
	}
	else
	{
		DataHuesped* DTHuesped = dynamic_cast<DataHuesped*>(DTusuario_ingresado);
		Huesped * newU = new Huesped(DTHuesped);
		colHuespedes.insert({newU->getEmail() , newU});
		DTHuesped = NULL ; 
	}
	delete DTusuario_ingresado  ; 
	
}

void UserController::CancelarAltaUsuario(){
	delete DTusuario_ingresado ;
}

//--------------------caso de uso asignar empleado a hostal---------------------------

set<DataEmpleado*> UserController::ListarEmpleadosSinHostal(){//esta media monstruosa pero creo q anda...

	//HostalController* HC = HostalController::getInstanciaHostal(); 

	set<DataEmpleado*> ColDataEmpleadosListar ;
	map<string, Empleado*>::iterator iter;
	for(iter = colEmpleados.begin() ; iter != colEmpleados.end() ; iter ++){
		Empleado* emp = iter->second ;
		if (emp->GetHostal() == NULL)
			ColDataEmpleadosListar.insert(emp->GetDataEmpleado()) ; 
	}
	//HC = NULL ;
	return  ColDataEmpleadosListar ;
}

void UserController::ElegirEmpleadoSinHostal(string email){
	this->mailEmpleadoSeleccionado = email ; 
}

void UserController::CancelarAltaEmpleadoAHostal(){
	//vaciar el hostal seleccionado y el empleado 
	mailEmpleadoSeleccionado = "" ; 
	HostalController* HC = HostalController::getInstanciaHostal(); 
	HC->SetNombreHostalSeleccionado("");
	HC = NULL ; 
}

//------------------------------ caso de uso registrar estadia-----------------------------------------------

void UserController::IngresarMail(string email){
	mailEmpleadoSeleccionado = email;
}
void UserController::IngresarMail(string email){
	HuespedesReserva.insert(email);
}

Huesped* UserController::getHuespedSeleccionado(){
	return colHuespedes.find(mailEmpleadoSeleccionado)->second;
}

map<string, Huesped*> UserController::getHuespedesRG(){
	set<string>::iterator itr;
	map<string, Huesped*> res;
	for(itr = HuespedesReserva.begin(); itr !=HuespedesReserva.end(); itr++ ){
		res.insert({*itr, colHuespedes.find(*itr)->second});
	}
	return res;
}

bool UserController::ExisteMail(string mail){
	bool registrado = false;
	map<string, Empleado*>::iterator itr;
	map<string, Huesped*>::iterator itr2;
	
	itr = colEmpleados.find(mail);
	if (itr!=colEmpleados.end())
		registrado = true;
	else {
		itr2=colHuespedes.find(mail);
		if (itr2!=colHuespedes.end())
			registrado=true;
	}
	//if (registrado)
	//	throw invalid_argument("Ya existe Usuario registrado para el mail ingresado");	
	return registrado;
}

set<DataReserva*> UserController::ListarReservasNoCanceladas(DataHostal* coso, string email){
	


}

void UserController::ElegirReserva(DataReserva* reserva){



}

//--------------------------------Caso de uso consulta de usuario---------------------------------------

set<string> UserController::ListarUsuarios(){  
	map<string, Empleado*>::iterator itr;
	map<string, Huesped*>::iterator itr2;
	set<string> conjUsu;
	
	for(itr = colEmpleados.begin(); itr!=colEmpleados.end(); itr++)
		conjUsu.insert(itr->first);
	for(itr2 = colHuespedes.begin(); itr2!=colHuespedes.end(); itr2++)
		conjUsu.insert(itr2->first);

	return conjUsu;
}

DataUsuario* UserController::MostrarUsuario(string mail){
	map<string, Empleado*>::iterator coso = colEmpleados.find(mail);
	DataUsuario * usu;
	if (coso == colEmpleados.end()){
		map<string, Huesped*>::iterator coso2 = colHuespedes.find(mail);
		usu = coso2->second->getDataHuesped(); 
	}
	else{
		usu = coso->second->GetDataEmpleado(); 
	}

	return usu;
}

//----------------------------------------------------------------------------------------------------

void UserController::Suscribir()
{
}

void UserController::Desuscribir()
{
}

map<string, Empleado*> UserController::GetColEmpleados(){
	return colEmpleados ; 
}

string UserController::GetMailEmpleadoSeleccionado(){
	return mailEmpleadoSeleccionado ; 
}

UserController::~UserController(){
	
	map<string, Empleado*>::iterator itr;
	for(itr= colEmpleados.begin(); itr != colEmpleados.end(); itr++)
		delete itr->second;	

	map<string, Huesped*>::iterator itr2;
	for(itr2= colHuespedes.begin(); itr2 != colHuespedes.end(); itr2++)
		delete itr2->second;	
	
	//delete DTusuario_ingresado;
}



Empleado* UserController::DevolverEmpleado(string mail){
	return (colEmpleados.find(mail))->second; 
}


set<DataHuesped*> UserController::listarHuespedes(){
	set<DataHuesped*> conjSalida;
	map<string, Huesped*>::iterator iterHues;
	for(iterHues = colHuespedes.begin(); iterHues != colHuespedes.end(); iterHues++)
		conjSalida.insert(iterHues->second->getDataHuesped());
	return conjSalida;
}