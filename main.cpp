#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "Funciones.h"
#include "Codigos.h"

int main(){

    string nombre_ant;
    int v_ant[2];
    string nombre_max;
    int v_max[2];
    int opcion;
    ponerCero(v_ant, 2);
    ponerCero(v_max, 2);

    while(true){
        cout<<endl;
        cout<<"\n\t\t\t\t\t ===================="<<endl;
        cout<<"\n\t\t\t\t\t       GENERALA"<<endl;
        cout<<"\n\t\t\t\t\t 1. UN JUGADOR"<<endl;
        cout<<"\n\t\t\t\t\t 2. DOS JUGARORES"<<endl;
        cout<<"\n\t\t\t\t\t 3. PUNTUACION MAXIMA"<<endl;
        cout<<"\n\t\t\t\t\t 0. FIN DEL JUEGO"<<endl;
        cout<<"\n\t\t\t\t\t ===================="<<endl;
        cout<<"\n\t\t\t\t\t OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1:
                nombre_ant = nombre_max;
                v_ant[0] = v_max[0];
                v_ant[1] = v_max[1];
                nombre_max=empezarJuego(1, nombre_max, v_max);
            break;
            case 2:
                nombre_ant = nombre_max;
                v_ant[0] = v_max[0];
                v_ant[1] = v_max[1];
                nombre_max=empezarJuego(2, nombre_max, v_max);

            break;
            case 3:
                PuntuacionMaxima(v_ant, nombre_ant, v_max, nombre_max);
            break;
            case 0:
                cout<<endl;
                cout<<"\n\t=========================================="<<endl;
                cout<<"\n\t FIN DEL JUEGO - GRACIAS POR PARTICIPAR "<<endl;
                cout<<"\n\t=========================================="<<endl;

                system("pause");
                return 0;
            break;

        }

    }
}


