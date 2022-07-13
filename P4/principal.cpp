#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstddef>
#include <string>
#include <stdexcept>
#include <set>
#include <stdlib.h>

#include "include/sistema.h"
#include "include/IHostal.h"
#include "include/IUser.h"
#include "include/IRegistros.h"

#include "include/DataCalificacion.h"
#include "include/DataCalificacionNotificada.h"
#include "include/DataEmpleado.h"
#include "include/DataEstadia.h"
#include "include/DataHabitacion.h"
#include "include/DataHostal.h"
#include "include/DataHuesped.h"
#include "include/DataReservaGrupal.h"
#include "include/DataReservaIndividual.h"

#include "include/DataRespuesta.h"
#include "include/DataUsuario.h"
#include "include/DTFecha.h"

#include<unistd.h>


using namespace std;

Sistema *sys;  //es la clase que oficia de fab=-----
IRegistro* ireg;
IHostal* ihos;
IUser* iusr;


// Prototipos de las funciones
void menuPrincipal();
void menuHostales();
void menuUsuarios();
void menuReservas();
void menuEstadias();
void menuOtros();
void retraso(int);
void cabezal();
void eliminarSetDTH(set<DataHostal*>);
void eliminarSetDTHE(set<DataHostalExtendido*>);
void ImprimirHostalExtendido(DataHostalExtendido*);
void ImprimirEmpleadosSinHostal(set<DataEmpleado*>);
void ImprimirReservas(set<DataReserva*>);
void ImprimirReservasNoCanceladas(set<DataReserva*>);
void ImprimirHuespedes(set<DataHuesped*>);
void ImprimirHabitaciones(set<DataHabitacion*>);
void eliminarSetDTReserva(set<DataReserva*>); 
void eliminarSetDTE(set<DataHuesped*>);
void eliminarSetDTHab(set<DataHabitacion*>);

// Funciones auxiliares
void MostrarHostales(set<DataHostal*>, int); //muestra en pantalla los hostales con la info del datahostal
void MostrarHostalesExtendido(set<DataHostalExtendido*>);
DtFechaHora * IngresarFecha(); //permite ingresar una fecha y devuelve un DtFechaHora
void ImprimirUsuario(DataUsuario*);
void eliminarSetDTE(set<DataEmpleado*>);

int main()
{
    sys = Sistema::getInstancia();
    ireg = sys->getIRegistros();
    ihos = sys->getIHostal(); //getIHostal devuelve un puntero a una instancia de Ihostal
    iusr = sys->getIUser();
    
    system("clear"); 
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl<< endl << endl << endl<< endl << endl << endl ;
    cout<< "                                            ██████╗ ██╗███████╗███╗   ██╗██╗   ██╗███████╗███╗   ██╗██╗██████╗  ██████╗ " << endl ; 
    cout<< "                                            ██╔══██╗██║██╔════╝████╗  ██║██║   ██║██╔════╝████╗  ██║██║██╔══██╗██╔═══██╗" << endl ; 
    cout<< "                                            ██████╔╝██║█████╗  ██╔██╗ ██║██║   ██║█████╗  ██╔██╗ ██║██║██║  ██║██║   ██║" << endl ; 
    cout<< "                                            ██╔══██╗██║██╔══╝  ██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║██║  ██║██║   ██║" << endl ; 
    cout<< "                                            ██████╔╝██║███████╗██║ ╚████║ ╚████╔╝ ███████╗██║ ╚████║██║██████╔╝╚██████╔╝" << endl ; 
    cout<< "                                            ╚═════╝ ╚═╝╚══════╝╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝╚═╝╚═════╝  ╚═════╝ " << endl ; 

    retraso(2) ; 
    system("clear"); 

    menuPrincipal();
    
    delete ihos ;
    delete iusr ; 
    delete ireg ; 
    delete sys ; 

    return 0;
}

void menuPrincipal()
{
    int opcion;
    bool repetir = true;

    do
    {
         

        cabezal();
        cout << "\n\n\t\t\t  \033[1;35m   MENU PRINCIPAL \033[0m\n" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1. Hostales" << endl;
        cout << "\t2. Usuarios" << endl;
        cout << "\t3. Reservas" << endl;
        cout << "\t4. Estadias" << endl;
        cout << "\t5. Otros" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        retraso(3);
        system("clear"); 

        switch (opcion)
        {
        case 1:
            menuHostales();
            break;

        case 2:
            menuUsuarios();
            break;

        case 3:
            menuReservas();
            break;

        case 4:
            menuEstadias();
            break;

        case 5:
            menuOtros();
            break;

        case 0:
        








cout<<"██╗  ██╗ █████╗ ███████╗████████╗ █████╗     ██╗     ██╗   ██╗███████╗ ██████╗  ██████╗ "<<endl;
cout<<"██║  ██║██╔══██╗██╔════╝╚══██╔══╝██╔══██╗    ██║     ██║   ██║██╔════╝██╔════╝ ██╔═══██╗"<<endl;
cout<<"███████║███████║███████╗   ██║   ███████║    ██║     ██║   ██║█████╗  ██║  ███╗██║   ██║"<<endl;
cout<<"██╔══██║██╔══██║╚════██║   ██║   ██╔══██║    ██║     ██║   ██║██╔══╝  ██║   ██║██║   ██║"<<endl;
cout<<"██║  ██║██║  ██║███████║   ██║   ██║  ██║    ███████╗╚██████╔╝███████╗╚██████╔╝╚██████╔╝"<<endl;
cout<<"╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝  ╚═════╝ "<<endl;
                                                                                        

        retraso(20);

          //cin >> opcion ;
            
            repetir = false;
            break;
        }
    } while (repetir);
}

// Definiciones de las funciones

void menuHostales()
{
    int opcion;
    bool repetir = true;

    do
    {   
        cabezal();
        cout << "\n\n\t\t\t  \033[1;35m HOSTALES \033[0m\n" << endl;
        cout << "\t\t\t------------------------" << endl;
        cout << "\n\t1. Alta de Hostal" << endl;
        cout << "\t2. Consultar Hostal" << endl;
        cout << "\t3. Consultar Top3 Hostales" << endl;
        cout << "\t4. Nueva Habitacion" << endl;
        cout << "\t0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        retraso(3);
        system("clear"); 


        switch (opcion)
        {
        case 1:{//-----------------------------------------------------------------
            cabezal();
            string nombreHostal, dir;
            string telefono;
            cout << "Ingrese el nombre del Hostal: ";
            cin.ignore();
            getline(cin, nombreHostal);
            cout << "Ingrese la direccion del Hostal: ";
            getline(cin, dir);
            cout << "Ingrese el telefono del Hostal: ";
            cin >> telefono;
            
            DataHostal * DT = new DataHostal(nombreHostal, dir, telefono, 0.0);
            try {
                ihos->RegistrarHostal(DT);
                delete DT;
                cout << "\nSe ha registrado el hostal.\n";
                retraso(20);
                system("clear"); 

                break;
            }
            catch(invalid_argument& e)
            {
                cerr << e.what() << endl;
                delete DT;
                retraso(10);
                system("clear");
                break;
            }
            
        }  
        case 2:{//-------------------------Consulta De Hostal-------------------------------------------
            cabezal();
            
            
            // listar hostales 
            // seleccionar Hostal
            // MostrarHostal 
            // El caso de uso comienza cuando un usuario desea consultar la información de un
            // hostal. El sistema lista todos los hostales registrados y el usuario selecciona uno. A
            // continuación, el sistema lista la información básica del hostal (pero incluyendo
            // también promedio de calificaciones, así como los comentarios y calificaciones de las
            // habitaciones), así como la información de las habitaciones que posee y sus tipos de
            // consumo. Además, lista las reservas que se han hecho en ese hostal, sea cual sea su
            // estado.
      
            string nomHos; 
            //int ConfCanc ; 
           
            set<DataHostal*> setDH = ihos->ListarHostales();
            MostrarHostales(setDH, 0); 
            eliminarSetDTH(setDH);

            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos); 
            
            
            try{
                ihos->SeleccionarHostal(nomHos);
            }
            catch (const std::exception& e){
                cerr << e.what() << endl;
                retraso(10);
                system("clear");
                break;
            }
           
            DataHostalExtendido * nuevo = ihos->MostrarHostal();

            ImprimirHostalExtendido(nuevo);


            cout << "presione enter para continuar..." ; 
            cin.get();
            system("clear");
            
            break;
        }
        case 3:{//-----------------------------------------------------------------
            ihos->ConsultarTop3Hostales();
            break;
        }

        case 4:{//-----------------------------Nueva Habitacion------------------------------------
            cabezal();
            
            string nomHos; 
            int ConfCanc ; 
           
            set<DataHostal*> setDH = ihos->ListarHostales();
            MostrarHostales(setDH, 0); 
            eliminarSetDTH(setDH);


            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos); 
            
            try
            {
                ihos->SeleccionarHostal(nomHos);

                int numeroHabitacion, capacidad;
                float precio;


                cout << "Ingrese el numero de Habitacion: ";
                cin >> numeroHabitacion;
                cout << "Ingrese el precio de la Habitacion: ";
                cin >> precio;
                cout << "Ingrese la capacidad de la Habitacion: ";
                cin >> capacidad;

                DataHabitacion* dt = new DataHabitacion(numeroHabitacion, precio, capacidad);

                try
                {
                    ihos->NuevaHabitacion(dt);
                    cout << "(0) confirmar alta (1) cancelar alta : ";
                    cin >> ConfCanc;

                    if (ConfCanc == 0) {
                        ihos->ConfirmarAltaHabitacion();
                        cout << "Fue registrada la habitacion.\n";
                        retraso(20);
                        system("clear");
                    
                    }
                    else {
                        ihos->CancelarAltaHabitacion();
                        cout << "Fue cancelada el alta.\n"; \
                        retraso(10);
                        system("clear");

                    }
                    delete dt;
                    break;
                }
                catch (const std::exception& h)
                {
                    cerr << h.what() << endl;
                    delete dt;
                      retraso(10);
                      system("clear");
                    break;
                } 
            }
            catch (const std::exception& e)
            {
                cerr << e.what() << endl;
                retraso(10);
                system("clear");
                break;
                
            }


        }
        case 0://-----------------------------------------------------------------
            repetir = false;
            break;
        }
    } while (repetir);
}

void menuUsuarios()//------------------------------------------------------------------------------------------------------------
{
    int opcion;
    bool repetir = true;

    do
    {
        cabezal();
        cout << "\n\n\t\t\t  \033[1;35m USUARIOS \033[0m\n" << endl;
        cout << "\t\t\t-------------------------" << endl;
        cout << "\n\t1. Alta de Usuario" << endl;
        cout << "\t2. Consulta de Usuario" << endl;
        cout << "\t3. Asignar empleado a Hostal" << endl;
        cout << "\t4. Suscribir empleado a notificaciones" << endl;
        cout << "\t5. Cancelar suscripcion a notificaciones" << endl;
        cout << "\t0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        retraso(3);
        system("clear"); 

        switch (opcion)
        {
        case 1://-------------------- alta de usuario--------------------------------
        {   cabezal();

            string nombre, email, contrasena;
            int HoE = 0 ;
            int confirmarOcancelar = 1 ;

            cout << "ingresar nombre: " ;
            cin.ignore();
            getline(cin, nombre);
            bool sigue=true;
            while (sigue){
                cout << "ingresar email: " ; 
                getline(cin, email);                
                sigue=iusr->ExisteMail(email);
                if(sigue)
                    cout << "Ya hay usuario registrado con ese mail\n";
            }
            cout << "ingresar contrasena: " ;
            getline(cin, contrasena);
            cout << "huesped (0) o empleado (1) :";
            cin >> HoE;

            DataUsuario * DUsu;

            if (HoE == 0){
                int esfinger;
                cout << "Es finger?(0 no, 1 si) : ";
                cin >> esfinger;
                if (esfinger == 0)
                    DUsu = new DataHuesped(nombre, email, contrasena, false);
                else 
                    DUsu = new DataHuesped(nombre, email, contrasena, true);
            }
            else if (HoE == 1){
                int cargo;
                cout << "elegir cargo : " << "Limpieza (0)\n" << "Administracion (1)\n"
                << "Recepcion (2)\n" << "Infraestructura (3)\n";
                cin >> cargo ;

                DUsu = new DataEmpleado(nombre,email,contrasena,cargo, " ");
            };

            iusr->AltaDeUsuario(DUsu) ; //----
            cout << "(0) confirmar alta (1) cancelar alta: "; 
            cin >> confirmarOcancelar;
            cout << endl;
            if (confirmarOcancelar == 0){
                iusr->ConfirmarAltaUsuario();//------
                cout << "usuario registrado correctamente\n" ; 
            }
            else{
                iusr->CancelarAltaUsuario();
                cout << "alta cancelada correctamente\n" ; 
            }

            retraso(30);
            system("clear"); 
            break;
            
        }
        case 2://--------------------Consulta de usuario------------------------
        {
            cabezal();
            string mail;
            set<string> conjUsu = iusr->ListarUsuarios(); 
            cout << "Elija un usuario de la siguiente lista: \n";
            set<string>::iterator itr;
            for(itr=conjUsu.begin(); itr != conjUsu.end(); itr++)
                cout << "-"<< *itr << endl;
            bool sigue=false;
            while (!sigue){
                cout << "Escriba el mail:"; 
                cin.ignore();
                getline(cin, mail);                
                sigue = iusr->ExisteMail(mail);
                if(!sigue)
                    cout << "No hay usuario registrado con ese mail\n";
            }



            DataUsuario * dt = iusr->MostrarUsuario(mail);
            
            ImprimirUsuario(dt); 

            conjUsu.clear();
            delete dt ; 
            dt = NULL ; 
            

            cout << "presione una tecla para continuar ... " ; 
            char auxiliar ; 
            cin >> auxiliar ; 
            //retraso(50);
            system("clear"); 
            break;
        } 
        case 3://------------------------Asignar empleado a Hostal-----------------------------------------
        {
            string mail;
            cabezal();
            string nomHos; 
            //int ConfCanc ; 

            set<DataHostal*> setDH = ihos->ListarHostales();
            MostrarHostales(setDH, 0); 
            eliminarSetDTH(setDH);

            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos);

            //seleccionas hostal
            try{
                ihos->SeleccionarHostal(nomHos);
            }
            catch (const std::exception& e){
                cerr << e.what() << endl;
                break;
            }

            set<DataEmpleado*> conjEmp = iusr->ListarEmpleadosSinHostal();
            ImprimirEmpleadosSinHostal(conjEmp);
            eliminarSetDTE(conjEmp); 

            cout << "\nSeleccione un empleado : ";
            //cin.ignore();
            getline(cin, mail);

            iusr->ElegirEmpleadoSinHostal(mail);

            cout << "(1) confirmar alta (0) cancelar alta" << endl ; 
            cin >> opcion ; 

            if (opcion == 1){
                ihos->ConfirmarAltaEmpleadoAHostal();
                cout << "alta empleado a hostal confirmada" << endl ; 
            }
            else {
                iusr->CancelarAltaEmpleadoAHostal();
                cout << "alta empleado a hostal cancelada" << endl ; 
            }
            retraso(20);
            system("clear"); 
            break;
        }
        case 4://-----------------------------------------------------------------
        {
        break;
        }
        case 5://------------------------------------------------------------------
         {
        break;
        }
        case 0://-------------------------------------------------------------------
        {   
            repetir = false;
            break;
        }
        }
    } while (repetir);
}

void menuReservas()//-----------------------------Menu Reservas-------------------------------------------------------------------------------
{
    int opcion2;
    bool repetir = true;
    do
    {    
        cabezal();
        cout << "\n\n\t\t\t  \033[1;35m RESERVAS \033[0m\n" << endl;
        cout << "\t\t\t-------------------------" << endl;
        cout << "\n\t1. Realizar Reserva" << endl;
        cout << "\t2. Consulta de Reserva" << endl;
        cout << "\t3. Baja de Reserva" << endl;
        cout << "\t0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion2;
        system("clear"); 
        
        switch (opcion2){
        case 1://---------------------realizar reserva---------------------------------------------
        {
            cabezal();
            set<DataHostalExtendido*> listaDTHH = ihos->ListarHostalesDetallado();
            MostrarHostalesExtendido(listaDTHH); 
            eliminarSetDTHE(listaDTHH);
            
            string nomHos;
            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos);

            //seleccionas hostal
            try{
                ihos->SeleccionarHostal(nomHos);
            }
            catch (const std::exception& e){
                cerr << e.what() << endl;
                break;
            }

            cout << endl;
            int dd, mm, aaaa, hh, min = 0;
            cout << "Ingrese la fecha de ingreso como dd MM aaaa hh: ";
            cin >> dd >> mm >> aaaa >> hh;
            DtFechaHora * dtFechaIng = new DtFechaHora(dd, mm, aaaa, hh, min);

            cout << "Ingrese la fecha de egreso como dd MM aaaa hh: ";
            cin >> dd >> mm >> aaaa >> hh;
            DtFechaHora * dtFechaEg = new DtFechaHora(dd, mm, aaaa, hh, min);

            ireg->ingresarPeriodoFecha(dtFechaIng,dtFechaEg);

            int TipoReserva;
            cout << "Ingrese el tipo de reserva: individual(0) grupal(1): ";
            cin >> TipoReserva;
            ireg->TipoDeReserva(TipoReserva);


            set<DataHabitacion*> listaHab = ihos->ListarHabitacionesDisponibles(dtFechaIng, dtFechaEg);//---------------



            if (listaHab.empty()){
                cout << "no hay habitaciones disponibles para las fechas ingresadas";
                eliminarSetDTHab(listaHab);
                cout << "presione enter para continuar..." ; 
                cin.get();
                system("clear");
            
            
            }
            else {
                cout << "Las habitaciones disponibles son: \n";
                ImprimirHabitaciones(listaHab);
                eliminarSetDTHab(listaHab);
                int numHab;
                cout <<"\nIngresar numero de la habitacion : ";
                cin >> numHab;
                ihos->SeleccionarHabitacion(numHab);

                set<DataHuesped*> conj = iusr->listarHuespedes();
                ImprimirHuespedes(conj);

                cout << "Elija el huesped que realizara la reserva: ";
                eliminarSetDTE(conj);

                string mail;
                getline(cin, mail);
                bool sigue= iusr->ExisteMail(mail);
                while (!sigue){
                    cout << "Escriba el mail: ";
                    //cin.ignore();
                    getline(cin, mail);
                    sigue = iusr->ExisteMail(mail);
                    if(!sigue)
                        cout << "No hay huesped registrado con ese mail\n";
                }

                //ingreso del huesped que hace la reserva
                iusr->IngresarMail(mail);
                iusr->IngresarMailHuespedes(mail);

                
                if (TipoReserva == 1){
                    bool NoMas = true;
                    iusr->IngresarMailHuespedes(mail);

                    cout << "Agregue huespedes a la reserva.\n";
                    while (NoMas){
                        cout << "Escriba el mail: ";
                        cin.ignore();
                        getline(cin, mail);
                        if (iusr->ExisteMail(mail))
                            iusr->IngresarMailHuespedes(mail);
                        cout << "Desea agregar mas huespedes? (0) no (1) si: ";
                        cin >> NoMas;
                    }
                }
                int confCanc;
                cout << "Confirma la reserva (1) o cancelar (0)? : ";
                cin >> confCanc;
                if (confCanc == 1){
                    ireg->ConfirmarAltaReserva();
                    cout << "Reserva confirmada exitosamente\n" ;
                }
                else {
                    ireg->CancelarAltaReserva();
                    cout << "Reserva cancelada\n" ;
                }
            cout << "presione enter para continuar..." ; 
            
            cin.ignore();
            cin.get();
            system("clear");
            }
            break;   
        }
        case 2://--------------------consulta de reserva----------------------------------------------
        {
           // listar hostales 
           // seleccionar Hostal
           // listar reservas
           
            string nomHos;       

            set<DataHostal*> setDH = ihos->ListarHostales();
            MostrarHostales(setDH,0); 
            eliminarSetDTH(setDH);

            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos); 
            try{
                ihos->SeleccionarHostal(nomHos);
            }
            catch (const std::exception& e){
                cerr << e.what() << endl;
                break;
            }

            //listar reserva

            set<DataReserva*> coleccionReservas = ihos->ListarReservas();
            if (coleccionReservas.empty()){
                 cout << "no hay reservas para el hostal seleccionado" << endl ; 

            }
            else{
                ImprimirReservas(coleccionReservas);

            }

            eliminarSetDTReserva(coleccionReservas); 
            cout << "presione enter para continuar..." ; 
            cin.get();
            system("clear");
            
            break ; 
        } 
        case 3://---------------Baja De Reserva---------------------------------------------------
        {
            //listar hostales, seleccionar hostal, listar reservas, elegir reserva, confirmar baja, cancelar reserva
            string nomHos;
            set<DataHostal*> setDH = ihos->ListarHostales();
            MostrarHostales(setDH,0); 
            eliminarSetDTH(setDH);

            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos); 
            try{
                ihos->SeleccionarHostal(nomHos);
            }
            catch (const std::exception& e){
                cerr << e.what() << endl;
                break;
            }
            //listar reservas
            set<DataReserva*> coleccionReservas = ihos->ListarReservas(); 
            ImprimirReservasNoCanceladas(coleccionReservas); 
            eliminarSetDTReserva(coleccionReservas); 
            //ireg->SeleccionarReserva() ; //hay que implementarla


            int confcanc ; 
            cout << "Confirmar baja reserva (0) Cancelar baja reserva (1)" ; 
            cin >> confcanc ; 
            //if (confcanc == 0)
                



            break ; 
        } 
        case 0://------------------------------------------------------------------
            repetir = false;
            break;
        }
    } while (repetir);
}

void menuEstadias()//------------------------------------------------------------------------------------------------------------
{
    int opcion;
    bool repetir = true;



    do
    {   cabezal();
        cout << "\n\n\t\t\t  \033[1;35m ESTADIAS \033[0m\n" << endl;
        cout << "\t\t\t-------------------------" << endl;
        cout << "\n\t1. Registrar Estadia" << endl;
        cout << "\t2. Mostrar Estadia" << endl;
        cout << "\t3. Finalizar Estadia" << endl;
        cout << "\t4. Calificar Estadia" << endl;
        cout << "\t5. Comentar Calificacion" << endl;
        cout << "\t0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        system("clear"); 

        switch (opcion)
        {
        case 1://------------------Registrar Estadia--------------------------------------
        {
            cabezal();
            set<DataHostalExtendido*> listaDTHH = ihos->ListarHostalesDetallado();
            MostrarHostalesExtendido(listaDTHH); 
            eliminarSetDTHE(listaDTHH);
            
            string nomHos;
            cout <<"\nIngresar nombre del hostal : ";
            cin.ignore();
            getline(cin, nomHos);

            //seleccionas hostal
            try{
                ihos->SeleccionarHostal(nomHos);
            }
            catch (const std::exception& e){
                cerr << e.what() << endl;
                break;
            }

            cout << "Huesped que registra la estadia: " << endl;
            //eliminarSetDTE(conj);

            string mail;
            bool sigue=false;
            while (!sigue){
                cout << "Escriba el mail: "; 
                getline(cin, mail);
                sigue = iusr->ExisteMail(mail);
                if(!sigue)
                    cout << "No hay huesped registrado con ese mail\n";
            }
            //ingreso del huesped que hace la estadia
            iusr->IngresarMail(mail);

            set<DataReserva*> colReservasNoCanceladas =  ihos->ListarReservasNoCanceladas();
            ImprimirReservasNoCanceladas(colReservasNoCanceladas);


            int numRes;
            cout <<"\nIngresar codigo de reserva: ";
            cin >> numRes;



            ihos->CerrarReserva(numRes); //marca la reserva como cerrada
                                         //deberia seleccionar la reserva ya que se pide DataReserva * en estadia

            int codigoPromo;
            cout <<"Ingresar codigo de promocion (0 si no hay): " ; 
            cin >> codigoPromo;


            ireg->RegistrarEstadia(codigoPromo);

            cout <<"Estadia registrada correctamente" << endl ;

            retraso(20);
            system("clear");
            break ; 
        }
        case 2://--------------------------------Mostrar estadia----------------------------------
        {

            // listar hos 
            // seleccionar Hostal
            // listar estadias 
            // seleccionar Estadia
            // mostrar estadia
            // mostrar Calificacion
            // mostrar Respuesta
            // mostrar Reserva

            // necesitamos el set de estadaias para cada hostal...
            // ahora solo esta guardada en los huespedes





            break ; 
        }
        case 3://------------------------------------------------------------------
        {

            break ; 
        }
        case 4://------------------------------------------------------------------
        {

            break ; 
        }
        case 5://------------------------------------------------------------------
        {
            
            break ; 
        }
        case 0://------------------------------------------------------------------
            repetir = false;
            break;
        }
    } while (repetir);
}

void menuOtros()//------------------------------------------------------------------------------------------------------------
{
    int opcion;
    bool repetir = true;


    do
    {   cabezal();
        cout << "\n\n\t\t\t  \033[1;35m OTROS \033[0m\n" << endl;
        cout << "\t\t\t-------------------------" << endl;
        cout << "\n\t1. Cambiar Fecha de Sistema" << endl;
        cout << "\t2. Inicializar/Cargar Datos" << endl;
        cout << "\t0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;
        system("clear"); 

        switch (opcion)
        {
        case 1://------------------------------------------------------------------
        {   cabezal();
            cout << "La fecha actual del sistema es: " << "\033[1;35m" << ireg->FechaDeSistema() <<" \033[0m\n"<<endl;
            DtFechaHora * nuevaFecha = IngresarFecha();
            cout << "La fecha ingresada es: " << "\033[1;35m" << *nuevaFecha <<" \033[0m\n" << endl;
            ireg->CambiarFechaDeSistema(nuevaFecha);
            cout << "La nueva fecha del sistema es: " << "\033[1;35m" << ireg->FechaDeSistema()<<" \033[0m\n"  <<endl ;
            retraso(20);
            system("clear"); 
            break;
        }
        case 2://------------------------------------------------------------------
            try
            {
                ireg->CargarDatosPrueba();
                cout << "Los datos de prueba se cargaron correctamente" << endl;
                retraso(10);
                system("clear");
                break;
            }
            catch (const std::exception& d)
            {

            }
            


        case 0://------------------------------------------------------------------
            repetir = false;
            break;
        }
    } while (repetir);
}



void MostrarHostales(set<DataHostal*> setDH, int Tipo) {// muestra hostales y hostales detallado
    set<DataHostal*>::iterator itr;
    int numerador = 1;
    if (setDH.empty())
        cout << "No hay Hostales";
    else
        for(itr = setDH.begin(); itr!=setDH.end(); itr++){
            DataHostal * aux = *itr;
            cout << "\033[1;32m-------------\033[0m"<< numerador++ << "\033[1;32m-------------\033[0m" << endl ; 
            cout << "╠ "<<"Nombre: " << aux->getNombre() << endl ; 
            
            cout << "╠ "<<"Direccion: " << aux->getDireccion() << endl ; 
            
            cout << "╠ "<<"Telefono: " << aux->getTelefono() << endl ; 

            if (Tipo == 1 && aux->getPromedio() != 0)
                cout << "╠ "<<"Promedio Calificaciones: " << aux->getPromedio() << endl ;
            else if (Tipo == 1 && aux->getPromedio() == 0)
                 cout << "╠ "<<"No Tiene Calificaciones" << endl ;

            cout << "\033[1;32m---------------------------\033[0m" << endl ; 
        }
}

void MostrarHostalesExtendido(set<DataHostalExtendido*> setDH){
    set<DataHostalExtendido*>::iterator itr;
    int numerador = 1;
    if (setDH.empty())
        cout << "No hay Hostales";
    else
        for(itr = setDH.begin(); itr!=setDH.end(); itr++){
            DataHostal * aux = *itr;
            cout << "\033[1;32m-------------\033[0m"<< numerador++ << "\033[1;32m-------------\033[0m" << endl ; 
            cout << "╠ "<<"Nombre: " << aux->getNombre() << endl ; 
            
            cout << "╠ "<<"Direccion: " << aux->getDireccion() << endl ; 
            
            cout << "╠ "<<"Telefono: " << aux->getTelefono() << endl ; 

            if (aux->getPromedio() != 0 )
                cout << "╠ "<<"Promedio Calificaciones: " << aux->getPromedio() << endl ;
            else if (aux->getPromedio() == 0)
                 cout << "╠ "<<"No Tiene Calificaciones" << endl ;

            cout << "\033[1;32m---------------------------\033[0m" << endl ; 
        }
}



void ImprimirHostalExtendido(DataHostalExtendido* nuevo){
    cout << "\033[1;32m---------------------------\033[0m" << endl ;
    cout << "╠ Hostal: " << nuevo->getNombre() << endl;
    cout << "╠ Direccion: " << nuevo->getDireccion() << endl;
    cout << "╠ Telefono: " << nuevo->getTelefono() << endl;
    cout << "╠ Promedio: " << nuevo->getPromedio() << endl;
    cout << "\033[1;32m---------------------------\033[0m" << endl ;
    set<DataHabitacion*>::iterator itr;
    set<DataHabitacion*> habs = nuevo->getHabs(); 
    for(itr = habs.begin() ; itr != habs.end() ; itr++){
        cout << "╠  Habitacion nº: " << (*itr)->getNumero() << endl;
        cout << "╠  Precio: " << (*itr)->getPrecio() << endl;
        cout << "╠ Capacidad: " << (*itr)->getCapacidad() << endl;
        cout << "\033[1;32m---------------------------\033[0m" << endl ;
    }

    // set<DataCalificacion*>::iterator iter;
    // for(iter = (nuevo->getCalifs()).begin(); iter != (nuevo->getCalifs()).end(); iter++){
    //     cout << "Calificacion: " << (*iter)->getCalificacion() << "/5" << endl;
    //     cout << "Comentario: " << (*iter)->getComentario() << endl;
    //     cout << "\033[1;32m---------------------------\033[0m" << endl ;
    // }

}



DtFechaHora * IngresarFecha() {
    int dd, mm, aaaa, hh, min = 0;
    cout << "ingresar nueva fecha de sistema como dd MM aaaa hh mm: ";
    cin >> dd >> mm >> aaaa >> hh >> min;
    DtFechaHora * dtFecha = new DtFechaHora(dd, mm, aaaa, hh, min);
    return dtFecha;
}



void ImprimirUsuario(DataUsuario* dtu){
	DataEmpleado* DTEmpleado = dynamic_cast<DataEmpleado*>(dtu); 
    cout << "-----------------------"<< endl ; 
    cout << "╠ "<< "Nombre : " << dtu->getNomUsu() << endl ; 
    cout << "╠ " << "Email : "<<dtu->getEmailUsu() << endl ;
    if(DTEmpleado != NULL){
        cout << "╠ " << "Hostal : "<<DTEmpleado->getHostalTrabaja() << endl  ; 
        
        switch (DTEmpleado->getCargo())
        {
        case 0: 
            cout << "╠ "<< "Cargo : " <<"Limpieza" << endl ; 
            break;
        case 1: 
            cout << "╠ "<< "Cargo : " <<"Administracion" << endl ; 
            break;
        case 2:
            cout << "╠ " << "Cargo : "<<"Recepcion" << endl ; 
            break;
        case 3: 
            cout << "╠ "<< "Cargo : " <<"Infraestructura" << endl ; 
            break;
        }
    }
    else {
        	DataHuesped* DTHuesped = dynamic_cast<DataHuesped*>(dtu);
           if (DTHuesped->getEsFinger())
            cout << "╠ " <<"Es Finger" << endl ;   
           else cout <<"╠ " << "No es Finger" << endl ; 
    }
    cout << "-----------------------"<< endl ; 
}

void ImprimirHabitaciones(set<DataHabitacion*> listaHab){
    set<DataHabitacion*>::iterator iter;

    cout << "\033[1;32m-------------\033[0m" << endl ; 

    for(iter=listaHab.begin(); iter!=listaHab.end(); iter++){
        cout << "╠ Numero:" << (*iter)->getNumero()<<endl;
        cout << "╠ Precio:" << (*iter)->getPrecio()<<endl;
        cout << "╠ Capacidad:" << (*iter)->getCapacidad()<<endl;
        cout << "\033[1;32m-------------\033[0m" << endl ; 
    }

}

void ImprimirHuespedes(set<DataHuesped*> setT){
    set<DataHuesped*>::iterator itr;
     cout << "\033[1;32m-------------\033[0m" << endl ; 
    for (itr = setT.begin(); itr != setT.end(); itr++){
        cout <<"╠ " <<(*itr)->getEmailUsu() << endl ;
        cout << "\033[1;32m-------------\033[0m" << endl ; 
	}
}

void ImprimirEmpleadosSinHostal(set<DataEmpleado*> setT){
    set<DataEmpleado*>::iterator itr;
     cout << "\033[1;32m-------------\033[0m" << endl ; 
    for (itr = setT.begin(); itr != setT.end(); itr++){
        cout <<"╠ " <<(*itr)->getEmailUsu() << endl ;
        cout << "\033[1;32m-------------\033[0m" << endl ; 
	}
}

void ImprimirReservas(set<DataReserva*> setT){
    set<DataReserva*>::iterator itr;

    cout << "\033[1;32m--------------------\033[0m" << endl ; 
    for (itr = setT.begin(); itr != setT.end(); itr++){
        cout <<"╠  Codigo reserva: " << (*itr)->getCodigo() << endl ;
        cout <<"╠  CheckIn: " << *((*itr)->getCheckIn()) << endl ;
        cout <<"╠  CheckOut: " << *((*itr)->getCheckOut()) << endl ;
        cout <<"╠  Estado: " << (*itr)->getEstado() << endl ;
        cout <<"╠  Numero de habitacion: " << (*itr)->getNumeroHabitacion() << endl ;

        DataReservaIndividual* DTRI = dynamic_cast<DataReservaIndividual*>(*itr); 
        if (DTRI != NULL) {
            cout <<"╠  Huesped: " << DTRI->getHuesped()->getNomUsu() << endl ;
        }
        else{
            DataReservaGrupal* DTRG = dynamic_cast<DataReservaGrupal*>(*itr); 
            set<DataHuesped*> SDTH = DTRG->getSetDTH(); 
            ImprimirHuespedes(SDTH); 
        }
        cout << "\033[1;32m--------------------\033[0m" << endl ; 
    }
}


void ImprimirReservasNoCanceladas(set<DataReserva*> setT){
    set<DataReserva*>::iterator itr;

    cout << "\033[1;32m--------------------\033[0m" << endl ; 
    for (itr = setT.begin(); itr != setT.end(); itr++){
        cout <<"╠  Codigo reserva: " << (*itr)->getCodigo() << endl ;
        cout <<"╠  CheckIn: " << *((*itr)->getCheckIn()) << endl ;
        cout <<"╠  CheckOut: " << *((*itr)->getCheckOut()) << endl ;
        cout <<"╠  Estado: " << (*itr)->getEstado() << endl ;
        cout <<"╠  Numero de habitacion: " << (*itr)->getNumeroHabitacion() << endl ;
/*        cout <<"╠  A nombre de: " << (*itr)->getNombreReserva()<< endl;
        

        
        DataReservaIndividual* DTRI = dynamic_cast<DataReservaIndividual*>(*itr); 
        if (DTRI != NULL) {
            cout <<"╠  A nombre de: " << DTRI->getHuesped()->getNomUsu() << endl ;
        }
        else{
            DataReservaGrupal* DTRG = dynamic_cast<DataReservaGrupal*>(*itr); 
            set<DataHuesped*> SDTH = DTRG->getSetDTH(); 
            ImprimirHuespedes(SDTH); 
        }
        */
        cout << "\033[1;32m--------------------\033[0m" << endl ; 
    }



}

void retraso(int num){
    unsigned int microsecond = 100000;
    usleep(num * microsecond);
}

void cabezal(){
    cout << "#####################################################PPROGRAM#########################################################" << endl ;
} 



void eliminarSetDTH(set<DataHostal*> setT){
    set<DataHostal*>::iterator itr;
    for (itr = setT.begin(); itr != setT.end(); itr++){
        delete *itr ; 
	}
}
void eliminarSetDTHE(set<DataHostalExtendido*> setT){
    set<DataHostalExtendido*>::iterator itr;
    for (itr = setT.begin(); itr != setT.end(); itr++){
        delete *itr ; 
	}
}
void eliminarSetDTE(set<DataEmpleado*> setT) {
    set<DataEmpleado*>::iterator itr  ;
    for (itr = setT.begin(); itr != setT.end(); itr++){
        delete *itr;
	}
}

void eliminarSetDTE(set<DataHuesped*> setT) {
    set<DataHuesped*>::iterator itr  ;
    for (itr = setT.begin(); itr != setT.end(); itr++){
        delete *itr;
	}
}

void eliminarSetDTHab(set<DataHabitacion*> setT){
    set<DataHabitacion*>::iterator itr  ;
    for (itr = setT.begin(); itr != setT.end(); itr++){
        delete *itr;
	}
}

void eliminarSetDTReserva(set<DataReserva*> setT){
    set<DataReserva*>::iterator itr  ;
    for (itr = setT.begin(); itr != setT.end(); itr++){
        delete *itr;
	}
}