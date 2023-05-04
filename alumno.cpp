//
// Created by Juan on 5/3/2023.
//

#include "alumno.h"

std::string alumno::getcarrera() {
    return carrera;
}

int alumno::getedad() {
    return edad;
}

void alumno::setcarrera(std::string _carrera) {
    carrera = _carrera;
}

void alumno::setedad(int _edad) {
    edad = _edad;
}

void alumno::mostrar() {
    std::cout<<"######## ALUMNO #######"<<std::endl<<std::endl;
    persona::mostrar();
    std::cout<<carrera<<std::endl;
    std::cout<<edad<<std::endl<<std::endl;

    std::cout<<"Notas: "<<std::endl;
    for(int i=0; i<100; i++){
        if(materias[i].getcodigo() != -1){
            materias[i].mostrar();
        }
    }
}

alumno::alumno(int _dni, std::string _nombre, std::string _apellido, std::string _mail, std::string _carrera, int _edad):persona(_dni, _nombre, _apellido, _mail) {
    carrera = _carrera;
    edad = _edad;
}

alumno::alumno():persona() {}

void alumno::cargar_nota(int codigo, int nota) {
    for(auto & materia : materias){
        if(materia.getcodigo() == codigo){
            materia.setnota(nota);
        }
    }
}
