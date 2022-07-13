#include "../include/Hostal.h"

void Hostal::setNomHos(string nom){
    this->nombreHostal = nom;
}

void Hostal::setDirHos(string dir){
    this->direccion = dir;
}

void Hostal::setTelHos(string tel){
    this->telefono = tel;
}

string Hostal::getNomHos(){
    return this->nombreHostal;
}

string Hostal::getDirHos(){
    return this->direccion;
}

string Hostal::getTelHos(){
    return this->telefono;
}

map<int, Habitacion*> Hostal::GetHabitaciones(){
    return HabitacionesParaUnHostal;
}

Hostal::Hostal(string nombre, string dir, string tel){
    this->nombreHostal = nombre;
    this->direccion = dir;
    this->telefono = tel;
}

Hostal::Hostal(DataHostal *DT){
    this->nombreHostal = DT->getNombre();
    this->direccion = DT->getDireccion();
    this->telefono = DT->getTelefono();
}

bool Hostal::ExisteHabitacion(int elegida)
{
    map<int, Habitacion*>::iterator itr;
    itr = HabitacionesParaUnHostal.find(elegida);
    return itr != HabitacionesParaUnHostal.end();
}

float Hostal::CalcularPromedioCal(){
    map<int, Habitacion*>::iterator iterHab;
    //para cada habitacion de Hostal
    int ctdT = 0, aux1 = 0;
    map<int, Reserva*>::iterator iterRes;
    if(!(HabitacionesParaUnHostal.empty())){

        for(iterHab = HabitacionesParaUnHostal.begin(); iterHab != HabitacionesParaUnHostal.end(); iterHab++){
            Habitacion * hab = iterHab->second;
            int ctd=0 , aux = 0;
            //para cada reserva en hab
            if(!(hab->getConjRes().empty())){
                for(iterRes = hab->getConjRes().begin(); iterRes != hab->getConjRes().end(); iterRes++){
                    if (iterRes->second->getEstadia() != NULL) {
                        if(iterRes->second->getEstadia()->getCalificacion() != NULL){
                            aux += iterRes->second->getEstadia()->getCalificacion()->getCalif();
                            ctd++;
                        }
                    }
                }
            }
            aux1 += aux;
            ctdT+=ctd;
        }
    }

    if (ctdT != 0)
        return aux1/ctdT;
    else
        return 0.0;
}

DataHostal* Hostal::getDataHostal(){
    return new DataHostal(this->nombreHostal, this->direccion, this->telefono, 0.0);
}
//this->CalcularPromedioCal()
DataHostalExtendido * Hostal::getDataHostalExtendido(){
    map<int, Habitacion*>::iterator itr;
    set<DataHabitacion*> colHab;
    set<DataCalificacion*> colCal;
    for(itr = HabitacionesParaUnHostal.begin(); itr != HabitacionesParaUnHostal.end(); itr++){
        colHab.insert(itr->second->getDataHabitacion());
        set<DataCalificacion*>::iterator iter;
        if(!(itr->second->getCalificacionesHabitacion().empty())){
            for(iter = itr->second->getCalificacionesHabitacion().begin(); iter != itr->second->getCalificacionesHabitacion().end(); iter++){
                colCal.insert(*iter);
            }
        }
    }

    return new DataHostalExtendido(this->nombreHostal, this->direccion, this->telefono, 0.0 , colHab, colCal);
}

//this->CalcularPromedioCal()


set<DataHabitacion*> Hostal::getHabsDisp(DtFechaHora* ing, DtFechaHora* eg){
    map<int, Habitacion*>::iterator itr;
    set<DataHabitacion*> res;
    for(itr = HabitacionesParaUnHostal.begin(); itr != HabitacionesParaUnHostal.end(); itr++){
        Habitacion * hab = itr->second;
        map<int, Reserva*>::iterator iterRes;
        //para cada reserva en hab
        bool Disp = true;

            map<int, Reserva*> conjres = hab->getConjRes(); 
            for(iterRes = conjres.begin(); iterRes != conjres.end(); iterRes++){
                Disp = Disp && (iterRes->second->reservaDejaHabDisponible(ing, eg));
            }

        if (Disp == true)
            res.insert(hab->getDataHabitacion());

    }
    return res;
}

void Hostal::AnadirHabitacion(Habitacion* hab){
    HabitacionesParaUnHostal.insert({hab->getNumHab(), hab}); //esto deberia ingresar el par hostal, habitacion al map
}


void Hostal::SetEmpleado(Empleado* emp){
    string mail = emp->getEmail();
    EmpleadosParaUnHostal.insert({mail, emp});
}


Hostal::~Hostal(){
    map<int, Habitacion*>::iterator iter;
    for(iter = HabitacionesParaUnHostal.begin(); iter != HabitacionesParaUnHostal.end(); iter++){
        delete iter->second; 
    }
}


void Hostal::AgregarEstadia(Estadia* est){
    EstadiasParaUnHostal.insert(est); 
}


set<DataEstadia*> Hostal::getSetDataEstadias(){

    set<Estadia*>::iterator iter ; 
    set<DataEstadia*> DataEstadias ; 

    for (iter = EstadiasParaUnHostal.begin(); iter != EstadiasParaUnHostal.end(); iter++){

        DataEstadias.insert((*iter)->GetDataEstadia()); 
    }


    
} 
