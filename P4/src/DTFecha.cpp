#include <string>
#include "../include/DTFecha.h"

DTFecha::DTFecha()
{
  this->dia = this->mes = this->anio = 1;
}

DTFecha::DTFecha(int a, int b, int c, int d)
{
  dia = a;
  mes = b;
  anio = c;
  hora = d;
}

DTFecha::~DTFecha(){
}

void DTFecha::setDia(int dia){ this->dia = dia; }
void DTFecha::setMes(int mes){ this->mes = mes; }
void DTFecha::setAnio(int anio){ this->anio = anio; }
void DTFecha::setHora(int hora){ this->hora = hora; }

int DTFecha::getDia() { return this->dia; }

int DTFecha::getMes() { return this->mes; }

int DTFecha::getAnio() { return this->anio; }

int DTFecha::getHora() { return this->hora; }