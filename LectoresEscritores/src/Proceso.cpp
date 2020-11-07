#include "Proceso.h"

Proceso::Proceso()
{
    //ctor
}

Proceso::Proceso(unsigned short id, string tipo)
{
    this->id = id;
    this->tipo = tipo;
    tiempoServicio = rand()%(5) + 1;
    tiempoRestante = tiempoServicio;
}

unsigned short Proceso::getID()
{
    return id;
}

string Proceso::getTipo()
{
    return tipo;
}
