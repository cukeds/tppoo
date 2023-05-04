//
// Created by Juan on 5/3/2023.
//

#include "materia.h"

materia::materia() {
    codigo = -1;
}

materia::materia(int _codigo, std::string _nombre) {
    codigo = _codigo;
    nombre = _nombre;
    nota = -1;
}

int materia::getcodigo() {
    return codigo;
}

std::string materia::getnombre() {
    return nombre;
}

int materia::getnota() {
    return nota;
}

void materia::setcodigo(int _codigo) {
    codigo = _codigo;
}

void materia::setnombre(std::string _nombre) {
    nombre = _nombre;
}

void materia::setnota(int _nota) {
    nota = _nota;
}

void materia::mostrar() {
    std::cout<<"cod("<<codigo<<") "<<nombre;
    if(nota != -1){
        std::cout<<": "<<nota;
    }
    std::cout<<std::endl<<std::endl;
}
