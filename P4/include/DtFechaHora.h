#ifndef _DTFECHAHORA_H
#define _DTFECHAHORA_H

#include <iostream>

using namespace std;

class DtFechaHora {
	private:
		int dia, mes, ano, hora, minuto;
	public:
		DtFechaHora();
		DtFechaHora(int,int,int,int,int);
		DtFechaHora(DtFechaHora*);
		int getDia() const;
		int	getMes() const;
		int getAno() const;
		int getHora() const;
		int getMinuto() const;
		~DtFechaHora();

};

DtFechaHora* operator+(const DtFechaHora& unDtFechahora, const DtFechaHora& otroDtFechahora);

DtFechaHora* operator-(const DtFechaHora& unDtFechahora, const DtFechaHora& otroDtFechahora);

bool operator>(const DtFechaHora& unDtFechahora, const DtFechaHora& otroDtFechahora);

ostream& operator<<(ostream& output, const DtFechaHora& unDtFechahora);






/*
DtFechaHora& DtFechaHora::operator=(const DtFechaHora& f) {
	if (this != f) {
		this->dia = f.getDia();
		this->mes = f.getMes();
		this->ano = f.getAno();
		this->hora = f.getHora();
		this->minuto = f.getMinuto();
	}
	return *this; //esto significa lo apuntado, es como recorrer el puntero
}
*/

#endif