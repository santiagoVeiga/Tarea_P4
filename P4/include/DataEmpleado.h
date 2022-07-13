#ifndef _DATAEMPLEADO_H
#define _DATAEMPLEADO_H

#include "DataUsuario.h"
#include "EnumCargo.h"


class DataEmpleado :public DataUsuario {
	private:
		EnumCargo cargo;
		string NombreHostal;
	public:									        	//!nombre hostal
		DataEmpleado(string,string,string,int,string);//cargo orden 0-3 limpieza administracion recepcion infraestructura
		//DataEmpleado(DataUsuario);

		EnumCargo getCargo();
		string getHostalTrabaja(); 
		void Funcion();
		~DataEmpleado();
};










#endif
