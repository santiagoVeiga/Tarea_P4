#include "../include/sistema.h"
#include "../include/IUser.h"
#include "../include/UserController.h"
#include "../include/IHostal.h"
#include "../include/HostalController.h"
#include "../include/IRegistros.h"
#include "../include/RegistrosController.h"



Sistema* Sistema::instancia = NULL;


Sistema::Sistema()
{
}

Sistema::~Sistema()
{
}

Sistema* Sistema::getInstancia()
{
	if (instancia == NULL) {
		instancia = new Sistema();
	}
	return instancia;
}



IHostal* Sistema::getIHostal()
{
	return HostalController::getInstanciaHostal();
}

IUser* Sistema::getIUser()
{
	return UserController::getInstanciaUser() ;
}

IRegistro* Sistema::getIRegistros()
{
	return RegistrosController::getInstanciaRegistro();
}
