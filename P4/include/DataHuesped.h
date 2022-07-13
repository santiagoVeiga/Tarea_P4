#ifndef _DATAHUESPED_H
#define _DATAHUESPED_H

#include "DataUsuario.h"


class DataHuesped : public DataUsuario{
	private:
		bool esFinger;
		
	public:
		DataHuesped(string,string,string,bool);//nombre email password, esfinger
		
		bool getEsFinger();
		void Funcion();
		~DataHuesped();
};



#endif