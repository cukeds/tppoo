#include <iostream>
#include "docente.h"
#include "alumno.h"
#include "materia.h"

using namespace std;

int generar_dni(){
    return rand() % 90000000 + 10000000;
}

void alta_alumno(alumno* alumnos, int s){
    string nombre, apellido, mail, carrera;
    int dni, edad;
    dni = generar_dni();
    cout<< "Nombre:"<<endl;
    cin>>nombre;
    cout<<"Apellido: "<<endl;
    cin>>apellido;
    cout<<"Mail: "<<endl;
    cin>>mail;
    cout<<"Carrera: "<<endl;
    cin>>carrera;
    cout<<"Edad: "<<endl;
    cin>>edad;

    for(int i = 0; i < s; i++){
        if(alumnos[i].getdni() == -1){
            alumnos[i] = alumno(dni, nombre, apellido, mail, carrera, edad);
            return;
        }
    }
}

void alta_docente(docente* docentes, int s){
    string nombre, apellido, mail, titulo;
    int dni;
    dni = generar_dni();
    cout<< "Nombre:"<<endl;
    cin>>nombre;
    cout<<"Apellido: "<<endl;
    cin>>apellido;
    cout<<"Mail: "<<endl;
    cin>>mail;
    cout<<"Titulo: "<<endl;
    cin>>titulo;

    for(int i = 0; i < s; i++){
        if(docentes[i].getdni() == -1){
            docentes[i] = docente(dni, nombre, apellido, mail, titulo);
        }
    }
}

void inscribir(persona* personas, materia* materias, int s){
    int dni, codigo;
    materia _materia;
    cout<<"Ingrese el dni de la persona que desea anotar: "<<endl;
    cin>>dni;
    cout<<"Ingrese el codigo de la materia: "<<endl;
    cin>>codigo;

    for(int i = 0; i < s; i++){
        if(materias[i].getcodigo() == codigo){
            _materia = materias[i];
        }
    }
    if(_materia.getcodigo() == -1){
        cout<<"No se encontro la materia"<<endl;
        return;
    }

    for(int i = 0; i < s; i++){
        if(personas[i].getdni() == dni){
            personas[i].inscribir_materia(_materia);
            return;
        };
    }
    cout<<"No se encontro a la persona con ese dni"<<endl;
}
void cargar_nota(alumno* alumnos, int s){
    int dni, codigo, nota;
    cout<<"Ingrese el dni del alumno que desea cargar su nota: "<<endl;
    cin>>dni;
    cout<<"Ingrese el codigo de la materia que desea cargar: "<<endl;
    cin>>codigo;
    cout<<"Ingrese la nota: "<<endl;
    cin>>nota;
    for(int i = 0; i < s; i++){
        if(alumnos[i].getdni() == dni) {
            alumnos[i].cargar_nota(codigo, nota);
            return;
        }
    }
    cout<<"No se encontro el alumno"<<endl;
}
void modificar(){}

int main() {
    int opcion;
    const int s = 100;
    alumno alumnos[s];
    docente docentes[s];
    materia materias[s];

    for(int i = 0; i < 3; i++){
        materias[i] = materia(i, "Programacion " + to_string(i+1));
    }

    alumnos[0] = alumno(1, "Juan", "Degiovanni", "juan@gmail.com", "Ing. En Computacion", 22);
    docentes[0] = docente(1, "Julio", "Gutierrez", "julio@hotmail.com", "Ing. En Sistemas");

    do{
        cout<<"1. Alta (Alumnos y Docentes)"<<endl;
        cout<<"2. Inscribir a materia (Alumnos)"<<endl;
        cout<<"3. Anotar titular (Docente)"<<endl;
        cout<<"4. Cargar Nota (Alumnos)"<<endl;
        cout<<"5. Modificar Datos (Alumnos y Docentes)"<<endl;
        cout<<"6. Ver Datos"<<endl;
        cout<<"7. Salir"<<endl<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                int opcion_2;
                cout<<endl;
                cout<<"1. Dar de alta alumno"<<endl;
                cout<<"2. Dar de alta docente"<<endl;
                cout<<"3. Volver"<<endl;
                cin>>opcion_2;
                switch(opcion_2){
                    case 1:
                        alta_alumno(alumnos, s);
                        break;
                    case 2:
                        alta_docente(docentes, s);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                inscribir(alumnos, materias, s);
                break;
            case 3:
                inscribir(docentes, materias, s);
                break;
            case 4:
                cargar_nota(alumnos, s);
                break;
            case 5: {
                int opcion_3 = 0, opcion_4 = 0, dni;
                cout << endl;
                cout << "1. Modificar datos de alumno" << endl;
                cout << "2. Modificar datos de docente" << endl;
                cout << "3. Volver" << endl;
                cin >> opcion_3;
                cout << endl;

                cout << "Ingrese el dni de la persona a modificar" << endl;
                cin >> dni;
                switch (opcion_3) {
                    case 1: {
                        alumno* _alumno = new alumno();
                        for (auto &_a: alumnos) {
                            if (_a.getdni() == dni) {
                                _alumno = &_a;
                                break;
                            }
                        }
                        if (_alumno->getdni() == -1){
                            cout<<"No se encontro ese alumno"<<endl;
                            break;
                        }
                        do {
                            cout << "1. Modificar nombre" << endl;
                            cout << "2. Modificar apellido" << endl;
                            cout << "3. Modificar mail" << endl;
                            cout << "4. Modificar carrera" << endl;
                            cout << "5. Modificar edad" << endl;
                            cout << "6. Salir" << endl;
                            cin >> opcion_4;

                            switch (opcion_4) {
                                case 1: {
                                    string nombre;
                                    cout << "Nombre: " << endl;
                                    cin >> nombre;
                                    _alumno->setnombre(nombre);
                                    break;
                                }
                                case 2: {
                                    string apellido;
                                    cout << "Apellido: " << endl;
                                    cin >> apellido;
                                    _alumno->setapellido(apellido);
                                    break;
                                }
                                case 3: {
                                    string mail;
                                    cout << "Mail: " << endl;
                                    cin >> mail;
                                    _alumno->setmail(mail);
                                    break;
                                }
                                case 4: {
                                    string carrera;
                                    cout << "Carrera: " << endl;
                                    cin >> carrera;
                                    _alumno->setcarrera(carrera);
                                    break;
                                }
                                case 5: {
                                    int edad;
                                    cout << "edad: " << endl;
                                    cin >> edad;
                                    _alumno->setedad(edad);
                                    break;
                                }
                                default:
                                    cout << "No..." << endl;
                                    break;
                            }
                        } while (opcion_4 != 6);
                        break;
                    }
                    case 2: {
                        docente* _docente = new docente();
                        for (auto &_d: docentes) {
                            if (_d.getdni() == dni) {
                                _docente = &_d;
                            }
                        }
                        if(_docente->getdni() == -1){
                            cout<<"No se encontro ese docente"<<endl;
                            break;
                        }
                        do {
                            cout << "1. Modificar nombre" << endl;
                            cout << "2. Modificar apellido" << endl;
                            cout << "3. Modificar mail" << endl;
                            cout << "4. Modificar titulo" << endl;
                            cout << "6. Salir" << endl;
                            cin >> opcion_4;

                            switch (opcion_4) {
                                case 1: {
                                    string nombre;
                                    cout << "Nombre: " << endl;
                                    cin >> nombre;
                                    _docente->setnombre(nombre);
                                    break;
                                }
                                case 2: {
                                    string apellido;
                                    cout << "Apellido: " << endl;
                                    cin >> apellido;
                                    _docente->setapellido(apellido);
                                    break;
                                }
                                case 3: {
                                    string mail;
                                    cout << "Mail: " << endl;
                                    cin >> mail;
                                    _docente->setmail(mail);
                                    break;
                                }
                                case 4: {
                                    string titulo;
                                    cout << "Titulo: " << endl;
                                    cin >> titulo;
                                    _docente->settitulo(titulo);
                                    break;
                                }
                                default:
                                    cout << "No..." << endl;
                                    break;
                            }
                        } while (opcion_4 != 5);
                        break;
                    }
                    default:
                        cout << "No..." << endl;
                        break;
                }
                break;
            }
            case 6:
                int i;
                for(i = 0; i < 100; i++){
                    if(alumnos[i].getdni() != -1){
                        alumnos[i].mostrar();
                    }
                };
                for(i = 0; i < 100; i++){
                    if(docentes[i].getdni() != -1){
                        docentes[i].mostrar();
                    }
                };
                for(i = 0; i < 100; i++){
                    if(materias[i].getcodigo() != -1){
                        materias[i].mostrar();
                    }
                };
                break;
            default:
                cout<<"No..."<<endl;
                break;
        }
    }while(opcion != 7);
    return 0;
}
