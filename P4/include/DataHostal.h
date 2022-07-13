#ifndef _DATAHOSTAL_H
#define _DATAHOSTAL_H

#include <string>

using namespace std;



class DataHostal {
	private:
		string nombre;
		string direccion;
		string telefono;
		float promedio = 0;
		
	public:
		DataHostal(string,string,string);
		DataHostal(string,string,string, float);//nombre, dir, tel, prom
		string getNombre();
		string getDireccion();
		string getTelefono();
		float getPromedio();

		~DataHostal();
};


#endif
