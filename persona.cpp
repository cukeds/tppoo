//
// Created by Juan on 5/3/2023.
//

#include "persona.h"


persona::persona() {
    dni = -1;
}

int persona::getdni() {
    return dni;
}

std::string persona::getapellido() {
    return apellido;
}

std::string persona::getnombre() {
    return nombre;
}

std::string persona::getmail() {
    return mail;
}

void persona::setdni(int _dni) {
    dni = _dni;
}

void persona::setapellido(std::string _apellido) {
    apellido = _apellido;
}

void persona::setnombre(std::string _nombre) {
    nombre = _nombre;
}

void persona::setmail(std::string _mail) {
    mail = _mail;
}

void persona::inscribir_materia(materia _materia) {
    for(int i = 0; i < 100; i++){
        if(materias[i].getcodigo() == -1){
            materias[i] = _materia;
            return;
        }
    }
}

void persona::mostrar() {
    std::cout<<dni<<std::endl;
    std::cout<<nombre<<std::endl;
    std::cout<<apellido<<std::endl;
    std::cout<<mail<<std::endl;
}

persona::persona(int _dni, std::string _nombre, std::string _apellido, std::string _mail) {
    dni = _dni;
    nombre = _nombre;
    apellido = _apellido;
    mail = _mail;
}
