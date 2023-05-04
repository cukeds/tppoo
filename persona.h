//
// Created by Juan on 5/3/2023.
//


#ifndef TPPOO_PERSONA_H
#define TPPOO_PERSONA_H
#include <string>
#include "materia.h"
#include <iostream>

class persona {
protected:
    int dni;
    std::string apellido;
    std::string nombre;
    std::string mail;

    materia materias[100];
public:
    persona();
    persona(int, std::string, std::string, std::string);

    int getdni();
    std::string getapellido();
    std::string getnombre();
    std::string getmail();

    void setdni(int);
    void setapellido(std::string);
    void setnombre(std::string);
    void setmail(std::string);

    void inscribir_materia(materia);

    virtual void mostrar();
};


#endif //TPPOO_PERSONA_H
