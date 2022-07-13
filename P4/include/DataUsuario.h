#ifndef _DATAUSUARIO_H
#define _DATAUSUARIO_H

#include <string>
using namespace std;


class DataUsuario {
	private:
		string nombre;
		string email;
		string password;

	public:
		DataUsuario(string,string,string);

		string getNomUsu();
		string getEmailUsu();
		string getContrasena();
		virtual void Funcion(){}; //es necesaria una funcion para el dynamic cast
		virtual ~DataUsuario(){};

};










#endif