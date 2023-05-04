//
// Created by Juan on 5/3/2023.
//

#include "docente.h"

std::string docente::gettitulo() {
    return titulo;
}

void docente::settitulo(std::string _titulo) {
    titulo = _titulo;
}

void docente::mostrar() {
    std::cout<<"######## DOCENTE #######"<<std::endl<<std::endl;
    persona::mostrar();
    std::cout<<titulo<<std::endl<<std::endl;
}

docente::docente(int _dni, std::string _nombre, std::string _apellido, std::string _mail, std::string _titulo):persona(_dni, _nombre, _apellido, _mail) {
    titulo = _titulo;
}

docente::docente():persona() {}
