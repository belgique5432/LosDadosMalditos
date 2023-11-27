#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "rlutil.h"
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;

#include "utils.h"
    int dado[6];
    int mp;
    string mj;



int main(){
    while (true) {
       char opc;

        // Limpia la pantalla y muestra el menú
        system("cls");

        // Imprime el título del juego
        rlutil::setColor(rlutil::MAGENTA);
        rlutil::locate(44, 5);
        cout << "El dados malditos" << endl;

        // Imprime las opciones del menú
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(44, 6);
        cout << "1- Un jugador" << endl;
        rlutil::locate(44, 7);
        cout << "2- Dos jugadores" << endl;
        rlutil::locate(44, 8);
        cout << "3- Mayor puntaje" << endl;
        rlutil::locate(44, 9);
        cout << "4- Salir" << endl;

        // Solicita al usuario ingresar una opción
        rlutil::locate(44, 10);
        rlutil::setColor(rlutil::MAGENTA);
        cout << "Ingrese una opcion" << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(44, 11);
        cin >> opc;

        // Evalúa la opción ingresada por el usuario
        switch (opc) {
            case '1':
                // Llama a la función para un jugador
                unJugador(mp,mj);
                break;

            case '2':
                // Llama a la función para dos jugadores (debe estar implementada)
                dosJugadores();
                break;

            case '3':
                // Llama a la función para el mayor puntaje (debe estar implementada)
                mayorPuntaje(mp,mj);
                break;

            case '4':
                // Sale del programa
                return 0;

            default:
                // Mensaje para opciones inválidas
                rlutil::setColor(rlutil::RED);
                cout << "Opcion invalida. Intente nuevamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                system("pause");
                break;

        }
    }
}

