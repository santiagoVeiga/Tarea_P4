#ifndef _USUARIO_H
#define _USUARIO_H


#include <string>
#include "DataUsuario.h"




using namespace std;

class Usuario {
private:
    string nombreUsuario;
    string email;
    string password;

public:
    Usuario(string,string,string);
    DataUsuario* getDataUsuario();
    void setNombre(string);
    void setEmail(string);
    void setContrasena(string);

    string getEmail(); 
    string getNombre();
    string getContrasena();

    virtual ~Usuario(){} ;
    //virtual void Funcion()= 0; 
};

#endif