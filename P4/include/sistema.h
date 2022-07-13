#ifndef SISTEMA
#define SISTEMA

#include "IHostal.h"
#include "IRegistros.h"
#include "IUser.h"
#include "UserController.h"
#include "HostalController.h"
#include "RegistrosController.h"

class Sistema
{
private:

	static Sistema* instancia;
	Sistema();

public:
	
	~Sistema();


	static Sistema* getInstancia();
	

	IHostal* getIHostal();
	IUser* getIUser();
	IRegistro* getIRegistros();

};

#endif