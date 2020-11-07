#ifndef PROCESO_H
#define PROCESO_H
#include <iostream>

using namespace std;

class Proceso
{
    private:
        unsigned short id;
        string tipo;

    public:
        int tiempoServicio;
        int tiempoRestante;
        Proceso();
        Proceso(unsigned short, string);
        unsigned short getID();
        string getTipo();
};

#endif // PROCESO_H
