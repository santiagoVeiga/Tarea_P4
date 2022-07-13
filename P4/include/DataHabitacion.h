#ifndef _DATAHABITACION_H
#define _DATAHABITACION_H



class DataHabitacion {
	private:
		int numero;
		float precio;
		int capacidad;
	public:
		//numero, precio, capacidad
		DataHabitacion(int,float,int);
		int getNumero();
		float getPrecio();
		int getCapacidad();
		~DataHabitacion();
};












#endif