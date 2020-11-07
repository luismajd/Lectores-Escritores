#include <iostream>
#include <windows.h>
#include <time.h>
#include "Proceso.h"
#include "ListaProcesos.h"

#define N_LECTORES 8
#define N_ESCRITORES 2

using namespace std;

int main()
{
    ListaProcesos cola_procesos;
    ListaProcesos procesos_activos;
    srand(time(NULL));

    const int N = N_LECTORES + N_ESCRITORES;

    //Definir posiciones de los dos escritores en la cola
    int pos_esc_1 = rand()%(N) + 1; //Generar número aleatorio del 1 al N
    int pos_esc_2;

    //Asegurar que no se establezcan en la misma posición
    do
    {
        pos_esc_2 = rand()%(N) + 1;
    }
    while(pos_esc_1 == pos_esc_2);

    //Cargar procesos a la cola
    for(unsigned short i=1; i<=N; i++)
    {
        string tipo = (i == pos_esc_1 || i == pos_esc_2)? "escritor" : "lector";
        Proceso proceso(i, tipo);
        cola_procesos.Agregar(proceso);
    }

    //Algoritmo
    do
    {
        cout<<"Procesos en el recurso:"<<endl;
        procesos_activos.MostrarElementos();
        cout<<endl;

        cout<<"Cola de procesos:"<<endl;
        cola_procesos.MostrarElementos();
        cout<<endl;
        cout<<"------------------------------------------------------------"<<endl;

        if(!procesos_activos.EstaVacia())
        {
            procesos_activos.ReducirTiemposRestantes();
            if(procesos_activos.ContieneLectores())
            {
                if(cola_procesos.PrimerElementoEsLector())
                {
                    procesos_activos.Agregar(cola_procesos.SacarPrimerElemento());
                }
            }
        }
        else
        {
            procesos_activos.Agregar(cola_procesos.SacarPrimerElemento());
        }

        Sleep(1000);
    }
    while(!cola_procesos.EstaVacia());

    cout<<"Procesos en el recurso:"<<endl;
    procesos_activos.MostrarElementos();
    cout<<endl;

    cout<<"Cola de procesos:"<<endl;
    cola_procesos.MostrarElementos();
    cout<<endl;

    return 0;
}
