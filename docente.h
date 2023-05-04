//
// Created by Juan on 5/3/2023.
//

#ifndef TPPOO_DOCENTE_H
#define TPPOO_DOCENTE_H


#include "persona.h"

class docente: public persona {
private:
    std::string titulo;

public:
    docente();
    docente(int, std::string, std::string, std::string, std::string);

    std::string gettitulo();
    void settitulo(std::string);

    void mostrar();
};


#endif //TPPOO_DOCENTE_H
