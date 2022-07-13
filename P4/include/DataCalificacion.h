#ifndef _DATACALIFICACION_H
#define _DATACALIFICACION_H

#include <string>
using namespace std;

class DataCalificacion{
private:
	string com;
	int cal;

public:
	DataCalificacion();
	DataCalificacion(string, int);
	string getComentario();
	int getCalificacion();
	~DataCalificacion();
};

#endif