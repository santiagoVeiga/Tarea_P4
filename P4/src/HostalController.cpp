#include "../include/HostalController.h"

using namespace std; 

HostalController* HostalController::instancia = NULL;

HostalController::HostalController()
{
}
/*
void HostalController::ConsultarHostal()
{
}
*/

//revisar si se usa en algun momento
Hostal * HostalController::getHostalSeleccionado(){
	return col.find(nombre_hostal_seleccionado)->second;
}

Habitacion * HostalController::getHabitacionSeleccionada(){
	return col.find(nombre_hostal_seleccionado)->second->GetHabitaciones().find(habitacionRecordada)->second;
}



HostalController* HostalController::getInstanciaHostal() { 
	if (instancia == NULL)
        instancia = new HostalController();
	return instancia;
}

void HostalController::RegistrarHostal(DataHostal *hos)  
{
	map<string, Hostal*>::iterator itr;
	itr = col.find(hos->getNombre()); //este control se deberia hacer antes de llegar aca

	if (itr != col.end()) {
		throw invalid_argument("Ya existe hostal con ese nombre."); // la comunicacion con el usuario no se hace en el controlador
	}

	if (itr == col.end()){
		Hostal *hostal = new Hostal(hos);
		col.insert({hos->getNombre(), hostal});
	} 
}


void HostalController::SeleccionarHabitacion(int numHab){
	habitacionRecordada = numHab;
}


//---------------------------------caso de uso alta de habitacion---------------------------------------------------------------------

set<DataHostal*> HostalController::ListarHostales(){
	set<DataHostal*> colRet;
	map<string, Hostal*>::iterator itr;

	for (itr = col.begin(); itr != col.end(); itr++){
		DataHostal* DT = itr->second->getDataHostal();
		colRet.insert(DT);
	}
	return colRet;
}

void HostalController::SeleccionarHostal(string nombre){//operacion lista, a chequear

	map<string, Hostal*>::iterator itr;
	itr = col.find(nombre); 
	if (itr == col.end()) {
		throw invalid_argument("\033[1;35m El hostal seleccionado no esta registrado. \033[0m\n");
	}
	else
		nombre_hostal_seleccionado = nombre ; 
}

void HostalController::NuevaHabitacion(DataHabitacion* datahabitacion){
	Hostal* hostal = (col.find(nombre_hostal_seleccionado))->second;
	if (hostal->ExisteHabitacion(datahabitacion->getNumero()))
		throw invalid_argument("Ya existe habitacion registrada con ese numero para el hostal elegido.");
	
	DTHabitacionNueva = datahabitacion ; 

}

void HostalController::ConfirmarAltaHabitacion(){

	Habitacion* HabitacionNueva = new Habitacion(DTHabitacionNueva);
	Hostal* hostal = (col.find(nombre_hostal_seleccionado))->second ;
	HabitacionNueva->SetHostal(hostal); 
	hostal->AnadirHabitacion(HabitacionNueva);
	// hostal = NULL ; 
	// HabitacionNueva = NULL ; 

}

void HostalController::CancelarAltaHabitacion(){
	

}

//------------------------------CancelarAltaHabitacion


void HostalController::ReservasDelHostal(){

}



void HostalController::ConsultarTop3Hostales(){

}

float HostalController::PromedioHostal(Hostal* hos){
	return 
}

DataHostalExtendido* HostalController::MostrarHostal(){
	return col.find(nombre_hostal_seleccionado)->second->getDataHostalExtendido();
}





//----------------------caso de uso--------------------------------



//---------------------------------------------------------------------------------------



set<DataHostalExtendido*> HostalController::ListarHostalesDetallado(){
	set<DataHostalExtendido*> colDTH;
	map<string, Hostal*>::iterator itr5;

	for (itr5 = col.begin(); itr5 != col.end(); itr5++){
		DataHostalExtendido* DT = itr5->second->getDataHostalExtendido();
		colDTH.insert(DT);
	}
	return colDTH;
}

set<DataHabitacion*> HostalController::ListarHabitacionesDisponibles(DtFechaHora*ing, DtFechaHora*eg){
	map<string, Hostal*>::iterator itr = col.find(nombre_hostal_seleccionado);
	Hostal * hos = itr->second;
	return hos->getHabsDisp(ing, eg);
}



void HostalController::ConfirmarAltaEmpleadoAHostal(){  //caso de uso asignar empleado a hostal

    IUser* UC = UserController::getInstanciaUser();

	Hostal* hos = (col.find(nombre_hostal_seleccionado))->second;
	Empleado* emp = UC->DevolverEmpleado(UC->GetMailEmpleadoSeleccionado());

	
	hos->SetEmpleado(emp);
	emp->SetHostal(hos);
}



HostalController::~HostalController(){
	//delete DTHabitacionNueva;
	map<string, Hostal*>::iterator itr;
	for(itr= col.begin(); itr != col.end(); itr++)
		delete itr->second;
}

void HostalController::SetNombreHostalSeleccionado(string nom){
	nombre_hostal_seleccionado=nom;
}


set<DataReserva*> HostalController::ListarReservas(){// caso de uso consulta de reserva
	
	set<DataReserva*> DTReservas; 
	
	Hostal* HostalElegido = (col.find(nombre_hostal_seleccionado))->second;
	map<int, Habitacion*> SetHab = HostalElegido->GetHabitaciones() ; 
	map<int, Habitacion*>::iterator itr;
	for(itr=SetHab.begin(); itr != SetHab.end(); itr++){
		Habitacion* hab = itr->second ;
		map<int,Reserva*> conjRes = hab->getConjRes();
		map<int,Reserva*>::iterator itrReservas ; 
		for(itrReservas=conjRes.begin(); itrReservas != conjRes.end(); itrReservas++){
			Reserva* ReservaAux = itrReservas->second ; 
			
			DataReserva* DTRes ; 
			ReservaIndividual* resInd = dynamic_cast<ReservaIndividual*>(ReservaAux);
			if (resInd != NULL){
				DTRes = resInd->GetDataReserva();
			}
			else {
				ReservaGrupal* resGrup = dynamic_cast<ReservaGrupal*>(ReservaAux);
				DTRes = resGrup->GetDataReserva() ; 
			}
			DTReservas.insert(DTRes); 

			
		}
	}
	return DTReservas ; 

}

set<DataReserva*> HostalController::ListarReservasNoCanceladas(){
	set<DataReserva*> DtReservasNoCanceladas ; 
	
	Hostal* HostalElegido = (col.find(nombre_hostal_seleccionado))->second;
	map<int, Habitacion*> SetHab = HostalElegido->GetHabitaciones() ; 
	map<int, Habitacion*>::iterator itr;
	for(itr=SetHab.begin(); itr != SetHab.end(); itr++){
		Habitacion* hab = itr->second ;
		map<int,Reserva*> conjRes = hab->getConjRes();
		map<int,Reserva*>::iterator itrReservas ; 
		for(itrReservas=conjRes.begin(); itrReservas != conjRes.end(); itrReservas++){
			Reserva* ReservaAux = itrReservas->second ; 
			
			DataReserva* DTRes ; 
			ReservaIndividual* resInd = dynamic_cast<ReservaIndividual*>(ReservaAux);
			if (resInd != NULL){
				if (resInd->getEstado() == Cancelada)
					DTRes = resInd->GetDataReserva();
			}
			else {
				ReservaGrupal* resGrup = dynamic_cast<ReservaGrupal*>(ReservaAux);
				if (resGrup->getEstado() == Cancelada)
					DTRes = resGrup->GetDataReserva() ; 
			}
			DtReservasNoCanceladas.insert(DTRes); 			
		}
	}
	return DtReservasNoCanceladas ; 




}

void HostalController::CerrarReserva(int codigo){
	Reserva* ResAux	;
	map<int, Habitacion*>::iterator iter ;
	bool cond = false ;
	map<int, Habitacion*> habitaciones = col.find(nombre_hostal_seleccionado)->second->GetHabitaciones(); 
	for (iter = habitaciones.begin(); iter != habitaciones.end(); iter++){
		map<int, Reserva*> ConjRes = iter->second->getConjRes();
		map<int, Reserva*>::iterator iter2 ;
		for (iter2 = ConjRes.begin(); iter2 != ConjRes.end(); iter2++){
			if(iter2->second->getCodigo() == codigo){
				iter2->second->cerrarReserva();
				cond = true ;
				ResAux = iter2->second ; 
			}
			if (cond)
				break ;
		}
		if (cond)
			break ;
	}

	ReservaAuxRegistrarEstadia = ResAux ; 



Reserva* HostalController::GetReservaAuxRegistrarEstadia(){
	return ReservaAuxRegistrarEstadia ; 

}