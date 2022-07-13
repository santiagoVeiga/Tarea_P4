#include "../include/DataUsuario.h"

string DataUsuario::getNomUsu(){
    return nombre;
}

string DataUsuario::getEmailUsu(){
    return email;
}

string DataUsuario::getContrasena(){
    return this->password;
}

DataUsuario::DataUsuario(string nom ,string email, string pass){
    this->nombre = nom;
    this->email = email;
    this->password = pass;
}
