#include "../include/Usuario.h" 

Usuario::Usuario(string nombre, string mail, string pass){
    this->nombreUsuario = nombre;
    this->email = mail;
    this->password = pass;
}

DataUsuario *Usuario::getDataUsuario(){
    return new DataUsuario(this->nombreUsuario, this->email, this->password);
}

string Usuario::getEmail(){
    return this->email;
}

string Usuario::getNombre(){
    return this->nombreUsuario;
}

string Usuario::getContrasena(){
    return this->password;
}



//Usuario::~Usuario() {
	//}

void Usuario::setNombre(string nombre){
this->nombreUsuario =  nombre ; 

}
void Usuario::setEmail(string mail){

this->email = mail ; 
}
void Usuario::setContrasena(string contra){
this->password = contra ;

}