#include "../include/DtFechaHora.h"


using namespace std;

DtFechaHora::DtFechaHora(){}

DtFechaHora::DtFechaHora(int undia, int unmes, int unano, int unhora, int unminuto) {
	dia = undia;
	mes = unmes;
	ano = unano;
	hora = unhora;
	minuto = unminuto;
}

DtFechaHora::DtFechaHora(DtFechaHora* unDtFechahora) {
	dia = unDtFechahora->getDia();
	mes = unDtFechahora->getMes();
	ano = unDtFechahora->getAno();
	hora = unDtFechahora->getHora();
	minuto = unDtFechahora->getMinuto();
}

int DtFechaHora::getDia() const {
	return dia;
}

int DtFechaHora::getMes() const {
	return mes;
}

int DtFechaHora::getAno() const {
	return ano;
}

int DtFechaHora::getHora() const {
	return hora;
}

int DtFechaHora::getMinuto() const {
	return minuto;
}

DtFechaHora* operator+(const DtFechaHora& unDtFechahora, const DtFechaHora& otroDtFechahora) {
	int min = unDtFechahora.getMinuto() + otroDtFechahora.getMinuto();
	int hor = unDtFechahora.getHora() + otroDtFechahora.getHora();
	int di = unDtFechahora.getDia() + otroDtFechahora.getDia();
	int me = unDtFechahora.getMes() + otroDtFechahora.getMes();
	int an = unDtFechahora.getAno() + otroDtFechahora.getAno();
	if (min >= 60) {
		min = min % 60;
		hor++;
	}
	if (hor >= 24) {
		hor = hor % 24;
		di++;
	}
	if (di > 31) {
		di = di % 31;
		me++;
	}
	if (me > 12) {
		me = me % 12;
		an++;
	}
	DtFechaHora* dfh = new DtFechaHora(di, me, an, hor, min);
	return dfh;
}

DtFechaHora* operator-(const DtFechaHora& unDtFechahora, const DtFechaHora& otroDtFechahora) {
	int min = unDtFechahora.getMinuto() - otroDtFechahora.getMinuto();
	int hor = unDtFechahora.getHora() - otroDtFechahora.getHora();
	int di = unDtFechahora.getDia() - otroDtFechahora.getDia();
	int me = unDtFechahora.getMes() - otroDtFechahora.getMes();
	int an = unDtFechahora.getAno() - otroDtFechahora.getAno();
	if (min < 0) {
		min = min + 60;
		hor--;
	}
	if (hor < 0) {
		hor = hor + 24;
		di--;
	}
	if (di < 1) {
		di = di + 31;
		me--;
		if (di < 1) {
			di = di + 31;
			me--;
		}
	}
	if (me < 1) {
		me = me + 12;
		an--;
		if (me < 1) {
			me = me + 12;
			an--;
		}
	}
	DtFechaHora* dfh = new DtFechaHora(di, me, an, hor, min);
	return dfh;
}


bool operator>(const DtFechaHora& unDtFechahora, const DtFechaHora& otroDtFechahora) {
	bool res;
	res = unDtFechahora.getAno() > otroDtFechahora.getAno();
	if (otroDtFechahora.getAno() == unDtFechahora.getAno()) {
		res = unDtFechahora.getMes() > otroDtFechahora.getMes();
		if (otroDtFechahora.getMes() == unDtFechahora.getMes()) {
			res = unDtFechahora.getDia() > otroDtFechahora.getDia();
			if (otroDtFechahora.getDia() == unDtFechahora.getDia()) {
				res = unDtFechahora.getHora() > otroDtFechahora.getDia();
				if (otroDtFechahora.getDia() == unDtFechahora.getHora()) {
					res = unDtFechahora.getMinuto() > otroDtFechahora.getDia();
				}
			}
		}
	}
	return res;
}

ostream& operator<<(ostream& output, const DtFechaHora& unDtFechahora) {
	if (unDtFechahora.getMinuto() < 10) {
		output << unDtFechahora.getDia() << "/" << unDtFechahora.getMes() << "/" << unDtFechahora.getAno() << ", " << unDtFechahora.getHora() << ":0" << unDtFechahora.getMinuto() << "hs";
	} else {
		output << unDtFechahora.getDia() << "/" << unDtFechahora.getMes() << "/" << unDtFechahora.getAno() << ", " << unDtFechahora.getHora() << ":" << unDtFechahora.getMinuto() << "hs";
	}
	return output;
}


DtFechaHora::~DtFechaHora(){
	
}