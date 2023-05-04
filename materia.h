//
// Created by Juan on 5/3/2023.
//

#ifndef TPPOO_MATERIA_H
#define TPPOO_MATERIA_H
#include <string>
#include <iostream>

class materia {
private:
    int codigo;
    std::string nombre;
    int nota;
public:
    materia();
    materia(int, std::string);

    int getcodigo();
    std::string getnombre();
    int getnota();

    void setcodigo(int);
    void setnombre(std::string);
    void setnota(int);

    void mostrar();
};


#endif //TPPOO_MATERIA_H
