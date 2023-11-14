#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "rlutil.h"
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;
void mayorPuntaje(){
}

#include "utils.h"
    int dado[6];
    int mp=0;
    string mj;




int main(){

    while (true)
    {
        int opc;
        system("cls");
        cout<<"El dados malditos" <<endl;
        cout<<"1- Un jugador"<<endl;
        cout<<"2- Dos jugadores"<<endl;
        cout<<"3- Mayor puntaje"<<endl;
        cout<<"4- salir"<<endl;

        cout<<"Ingrese una opcion" <<endl;

        cin>>opc;

        switch (opc)
        {
        case 1:
            system("cls");
            unJugador(mp,mj);
            break;

        case 2:
            dosJugadores();
            break;
        case 3:
            system("cls");
            // Llama a una función 'MP'.
            MP(mp,mj);
            break;
        case 4:
            return 0;
        default:
            cout<<"Opcion invalida.Intente nuevamente"<<endl;
            break;
        }


    }

}

