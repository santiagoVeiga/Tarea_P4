#include "../include/RegistrosController.h"



using namespace std;



RegistrosController* RegistrosController::instancia = NULL;



RegistrosController::RegistrosController()
{
}

void RegistrosController::FinalizarEstadia(){

}

RegistrosController* RegistrosController::getInstanciaRegistro()
{
	if (instancia == NULL) {
		instancia = new RegistrosController();
		DtFechaHora* fechaActual = new DtFechaHora(13, 06, 2022, 14, 37); //podria levantarse la fecha del equipo
		instancia->fechaSistema = fechaActual;
		instancia->statusDatosDePrueba = false; //por defecto no se cargaron aun
	}
	return instancia;
}

//------------------------------------------OPERACIONES DEL SISTEMA------------------------------------------------


void RegistrosController::TipoDeReserva(int a){
	TipoReserva = a;
}

void RegistrosController::ingresarPeriodoFecha(DtFechaHora* dtFechaIng, DtFechaHora* dtFechaEg){
	fechaInicio = dtFechaIng;
	fechaFinal = dtFechaEg;
}

void RegistrosController::ConfirmarAltaReserva(){
	IHostal* iHostalController = HostalController::getInstanciaHostal();
	//Hostal* hos = iHostalController->getHostalSeleccionado();
	Habitacion * hab = iHostalController->getHabitacionSeleccionada();
	IUser* iUserController = UserController::getInstanciaUser();
	Huesped * huesRR = iUserController->getHuespedSeleccionado();

	if (TipoReserva == 0){//individual int cod, DtFechaHora* ingreso, DtFechaHora* egreso, EstadoReserva est, Huesped * hues, Habitacion * hab
		ReservaIndividual * res = new ReservaIndividual(numRes++,fechaInicio,fechaFinal,Abierta, huesRR,hab);
		hab->AnadirReserva(res);
	}
	else if (TipoReserva == 1)
	{
		map<string, Huesped*> nuevaCol = iUserController->getHuespedesRG();
		ReservaGrupal * res = new ReservaGrupal(numRes++,fechaInicio,fechaFinal,Abierta, huesRR, nuevaCol ,hab);
		hab->AnadirReserva(res);
	}

}

void RegistrosController::CancelarAltaReserva(){
	delete fechaInicio;
	delete fechaFinal;
}






void RegistrosController::MostrarEstadia()
{
}

//-----caso de uso comentar calificacion 







//-------caso de uso consulta de estadia

void RegistrosController::SeleccionarEstadia(DataEstadia* est){

}

DataCalificacion* RegistrosController::MostrarCalificacion(){

}

DataRespuesta* RegistrosController::MostrarRespuesta(){

}

DataReserva* RegistrosController::MostrarReserva(){

}



//-----------caso de uso Baja de reserva
set<DataReserva*> RegistrosController::ListarReservas(){ //para el hostal seleccionado (va a haber comunicacion entre contrladores)

}

void RegistrosController::ElegirReserva(DataReserva* reserva){

}

void RegistrosController::ConfirmarBaja(){

}
void RegistrosController::CancelarBaja(){

}

//--------caso de uso consulta de notificaciones 

set<DataEmpleado*> RegistrosController::ListarEmpleados(){

}

set<DataCalificacionNotificada*> RegistrosController::ListarCalificaciones(Empleado* e){// e es el empleado recordado por el sistema


}


void RegistrosController::CambiarFechaDeSistema(DtFechaHora * fechaNueva) //el control de fecha valida se hace antes
{
	DtFechaHora * fechaActual = this->fechaSistema;
	this->fechaSistema = fechaNueva;
	delete fechaActual; //elimino puntero a fecha anterior
}

DtFechaHora RegistrosController::FechaDeSistema(){
	return this->fechaSistema;
}

void RegistrosController::RegistrarEstadia(int codigoPromo){
  //Estadia(DtFechaHora, int, Reserva*, Huesped*);
	IUser* iUserController = UserController::getInstanciaUser();
	IHostal* ihos = HostalController::getInstanciaHostal();

	Reserva* reservaAux = ihos->GetReservaAuxRegistrarEstadia();
	Estadia* est = new Estadia(fechaSistema, codigoPromo,reservaAux,iUserController->getHuespedSeleccionado());
	iUserController->getHuespedSeleccionado()->agregarAlSetEstadias(est) ;

	//agregar a las estadias de un hostal, pero como encuentro el hostal??????

	Hostal* hos = ihos->getHostalSeleccionado() ; 
	hos->AgregarEstadia(est); 
 
	}











//------------------------------------------------------CARGA DE DATOS------------------------------------------------------------
void RegistrosController::CargarDatosPrueba()
{
	if (statusDatosDePrueba) {
		throw invalid_argument("Ya fueron cargados los datos.");
	}
	else
	{
		IUser* iUserController = UserController::getInstanciaUser();

		//empleados
		DataUsuario* DUsu = new DataEmpleado("Emilia", "emilia@mail", "123", 2, " ");
		iUserController->AltaDeUsuario(DUsu);
		iUserController->ConfirmarAltaUsuario();
		
		DataUsuario* DUsu1 = new DataEmpleado("Leonardo", "leo@mail", "123", 2, " ");
		iUserController->AltaDeUsuario(DUsu1);
		iUserController->ConfirmarAltaUsuario();
		
		DataUsuario* DUsu2 = new DataEmpleado("Alina", "alina@mail", "123", 1, " ");
		iUserController->AltaDeUsuario(DUsu2);
		iUserController->ConfirmarAltaUsuario();
		
		DataUsuario* DUsu3 = new DataEmpleado("Barliman", "barli@mail", "123", 2, " ");
		iUserController->AltaDeUsuario(DUsu3);
		iUserController->ConfirmarAltaUsuario();

		//huespedes
//-------------------------------------------------------------------------------------------
		DataUsuario* H1 = new DataHuesped("Sofia", "sofia@mail.com", "123", 1);
		iUserController->AltaDeUsuario(H1);
		iUserController->ConfirmarAltaUsuario();
		
		DataUsuario* H2 = new DataHuesped("Frodo", "frodo@mail.com", "123", 1);
		iUserController->AltaDeUsuario(H2);
		iUserController->ConfirmarAltaUsuario();
	
		DataUsuario* H3 = new DataHuesped("Sam", "sam@mail.com", "123", 0);
		iUserController->AltaDeUsuario(H3);
		iUserController->ConfirmarAltaUsuario();		
		
		DataUsuario* H4 = new DataHuesped("Merry", "merry@mail.com", "123", 0);
		iUserController->AltaDeUsuario(H4);
		iUserController->ConfirmarAltaUsuario();
	
		DataUsuario* H5 = new DataHuesped("Pippin", "pippin@mail.com", "123", 0);
		iUserController->AltaDeUsuario(H5);
		iUserController->ConfirmarAltaUsuario();
		
		DataUsuario* H6 = new DataHuesped("Seba", "seba@mail.com", "123", 1);
		iUserController->AltaDeUsuario(H6);
		iUserController->ConfirmarAltaUsuario();


		//hostales
		IHostal* iHostalController = HostalController::getInstanciaHostal();
//-------------------------------------------------------------------------------------------

		DataHostal* DHos = new DataHostal("La Posada del Finger", "Av de la Playa 123, Maldonado", "099111111");		
		iHostalController->RegistrarHostal(DHos);		
		iHostalController->SeleccionarHostal(DHos->getNombre());
		DataHabitacion* DHab1 = new DataHabitacion(1, 40, 2);
		iHostalController->NuevaHabitacion(DHab1);
		iHostalController->ConfirmarAltaHabitacion();
		DataHabitacion* DHab2 = new DataHabitacion(2, 10, 7);
		iHostalController->NuevaHabitacion(DHab2);
		iHostalController->ConfirmarAltaHabitacion();
		DataHabitacion* DHab3 = new DataHabitacion(3, 30, 3);
		iHostalController->NuevaHabitacion(DHab3);
		iHostalController->ConfirmarAltaHabitacion();
		DataHabitacion* DHab4 = new DataHabitacion(4, 5, 12);
		iHostalController->NuevaHabitacion(DHab4);
		iHostalController->ConfirmarAltaHabitacion();

		iHostalController->SeleccionarHostal(DHos->getNombre());
		iUserController->ElegirEmpleadoSinHostal("emilia@mail");
		iHostalController->ConfirmarAltaEmpleadoAHostal();

		fechaInicio= new DtFechaHora(1,5,2022,14,0);
		fechaFinal= new DtFechaHora(10,5,2022,10,0);
		ingresarPeriodoFecha(fechaInicio,fechaFinal);
		TipoDeReserva(0);
		iHostalController->SeleccionarHabitacion(DHab1->getNumero());
		iUserController->IngresarMail("sofia@mail.com");
		ConfirmarAltaReserva();

		fechaInicio= new DtFechaHora(7,6,2022,14,0);
		fechaFinal= new DtFechaHora(30,6,2022,11,0);
		ingresarPeriodoFecha(fechaInicio,fechaFinal);
		TipoDeReserva(0);
		iHostalController->SeleccionarHabitacion(DHab3->getNumero());
		iUserController->IngresarMail("sofia@mail.com");
		ConfirmarAltaReserva();

//--------------------------------------------------------------------

		DataHostal* DHos1 = new DataHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512");
		iHostalController->RegistrarHostal(DHos1);

		iHostalController->SeleccionarHostal(DHos1->getNombre());
		iUserController->ElegirEmpleadoSinHostal("leo@mail");
		iHostalController->ConfirmarAltaEmpleadoAHostal();

		iHostalController->SeleccionarHostal(DHos1->getNombre());
		iUserController->ElegirEmpleadoSinHostal("alina@mail");
		iHostalController->ConfirmarAltaEmpleadoAHostal();

//---------------------------------------------------------------------
		DataHostal* DHos2 = new DataHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
		iHostalController->RegistrarHostal(DHos2);
		iHostalController->SeleccionarHostal(DHos2->getNombre());
		DataHabitacion* DHab6 = new DataHabitacion(1, 3, 2);
		iHostalController->NuevaHabitacion(DHab6);
		iHostalController->ConfirmarAltaHabitacion();

		//sus empleados
		iHostalController->SeleccionarHostal(DHos2->getNombre());
		iUserController->ElegirEmpleadoSinHostal("barli@mail");
		iHostalController->ConfirmarAltaEmpleadoAHostal();

		fechaInicio= new DtFechaHora(4,1,2001,20,0);
		fechaFinal= new DtFechaHora(5,1,2001,2,0);
		ingresarPeriodoFecha(fechaInicio,fechaFinal);
		TipoDeReserva(1);
		iHostalController->SeleccionarHabitacion(DHab6->getNumero());
		iUserController->IngresarMail("frodo@mail.com");
		iUserController->IngresarMailHuespedes("frodo@mail.com");
		iUserController->IngresarMailHuespedes("sam@mail.com");
		iUserController->IngresarMailHuespedes("merry@mail.com");
		iUserController->IngresarMailHuespedes("pippin@mail.com");
		ConfirmarAltaReserva();
//---------------------------------------------------------------------------------------------
		DataHostal* DHos3 = new DataHostal("Altos de Fing", "Av del Toro 1424", "099892992");
		iHostalController->RegistrarHostal(DHos3);
		iHostalController->SeleccionarHostal(DHos3->getNombre());

//---------------------------------------------------------------------------------------------
		DataHostal* DHos4 = new DataHostal("Caverna Lujosa", "Amaya 2515", "233233235");
		iHostalController->RegistrarHostal(DHos4);
		iHostalController->SeleccionarHostal(DHos4->getNombre());

		//habitaciones
		DataHabitacion* DHab5 = new DataHabitacion(1, 9, 5);
		iHostalController->NuevaHabitacion(DHab5);
		iHostalController->ConfirmarAltaHabitacion();

		fechaInicio= new DtFechaHora(10,6,2022,14,0);
		fechaFinal= new DtFechaHora(30,6,2022,11,0);
		ingresarPeriodoFecha(fechaInicio,fechaFinal);
		TipoDeReserva(0);
		iHostalController->SeleccionarHabitacion(DHab5->getNumero());
		iUserController->IngresarMail("seba@mail.com");
		ConfirmarAltaReserva();

		delete DHos;
		delete DHos1;
		delete DHos2;
		delete DHos3;
		delete DHos4;

		delete DHab1;
		delete DHab2;
		delete DHab3;
		delete DHab4;
		delete DHab5;
		delete DHab6;


		statusDatosDePrueba = true;
		iUserController = NULL;
	}
}

DataReserva* RegistrosController::SeleccionarReserva(int codigo){

}

RegistrosController::~RegistrosController()
{
	delete fechaSistema;
}
