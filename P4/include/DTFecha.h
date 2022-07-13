

#ifndef _DATAFECHA_H
#define _DATAFECHA_H




class DTFecha
{
private:
  int dia, mes, anio, hora;

public:
  DTFecha(int, int, int, int);
  DTFecha();
  ~DTFecha();
  void setDia(int);
  void setMes(int);
  void setAnio(int);
  void setHora(int);
  int getDia();
  int getMes();
  int getAnio();
  int getHora();

};



#endif