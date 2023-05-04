//
// Created by Juan on 5/3/2023.
//

#ifndef TPPOO_ALUMNO_H
#define TPPOO_ALUMNO_H


#include "persona.h"

class alumno: public persona {
private:
    std::string carrera;
    int edad;
public:
    alumno();
    alumno(int, std::string, std::string, std::string, std::string, int);
    std::string getcarrera();
    int getedad();

    void setcarrera(std::string);
    void setedad(int);

    void cargar_nota(int codigo, int nota);

    void mostrar();
};


#endif //TPPOO_ALUMNO_H
