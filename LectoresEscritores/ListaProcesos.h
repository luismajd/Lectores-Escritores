#ifndef LISTAPROCESOS_H
#define LISTAPROCESOS_H
#include "Proceso.h"
#include "txtcolor.h"

class ListaProcesos;

class Nodo
{
    private:
        Nodo *ptr;
        Proceso proceso;

    public:
        Nodo(){ ptr = NULL; }
        friend class ListaProcesos;
};

class ListaProcesos
{
    private:
        Nodo *inicio;

    public:
        unsigned short cantidad;
        ListaProcesos() { cantidad = 0; inicio = NULL; }
        void Agregar(Proceso);
        Proceso SacarPrimerElemento();
        void MostrarElementos();
        bool EstaVacia();
        void ReducirTiemposRestantes();
        bool ContieneLectores();
        bool PrimerElementoEsLector();
};

void ListaProcesos::Agregar(Proceso proceso)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->proceso = proceso;
    if(inicio)
    {
        Nodo *actual;
        actual = inicio;
        while(actual->ptr)
        {
            actual = actual->ptr;
        }
        actual->ptr = nuevo;
    }
    else
    {
        inicio = nuevo;
    }
    cantidad++;
}

Proceso ListaProcesos::SacarPrimerElemento()
{
    Nodo *aux;
    aux = inicio;
    inicio = inicio->ptr;
    return aux->proceso;
}

void ListaProcesos::MostrarElementos()
{
    if(inicio)
    {
        Nodo *actual;
        actual = inicio;
        while(actual)
        {
            int color = (actual->proceso.getTipo() == "lector")? 10 : 12;
            TextColor(color);
            cout<<actual->proceso.getID()<<": "<<actual->proceso.getTipo()<<" "<<actual->proceso.tiempoRestante<<endl;
            TextColor(15);
            actual = actual->ptr;
        }
    }
    else
    {
        cout<<"No hay procesos aqui."<<endl;
    }
}

bool ListaProcesos::EstaVacia()
{
    return !inicio;
}

void ListaProcesos::ReducirTiemposRestantes()
{
    if(inicio)
    {
        Nodo *actual, *anterior;
        actual = inicio;
        while(actual)
        {
            actual->proceso.tiempoRestante--;
            if(actual->proceso.tiempoRestante == 0)
            {
                if(actual == inicio)
                {
                    inicio = actual->ptr;
                    delete actual;
                    actual = inicio;
                }
                else
                {
                    anterior->ptr = actual->ptr;
                    delete actual;
                    actual = anterior->ptr;
                }
                continue;
            }
            anterior = actual;
            actual = actual->ptr;
        }
    }
}

bool ListaProcesos::ContieneLectores()
{
    if(inicio)
    {
        Nodo *actual;
        actual = inicio;
        while(actual)
        {
            if(actual->proceso.getTipo() == "lector") return true;
            actual = actual->ptr;
        }
    }
    return false;
}

bool ListaProcesos::PrimerElementoEsLector()
{
    if(inicio) return inicio->proceso.getTipo() == "lector";
    return false;
}

#endif // LISTAPROCESOS_H
