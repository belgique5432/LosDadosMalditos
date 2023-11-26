#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <cstdio>


using namespace std;

#include "utils.h"

int main()
{
int mp;
    string mj;
    bool bandera = true;

    while (true)
    {


        if (bandera == true) {
            mp = 0;
            bandera = false;
        }

        char opc;

        // Limpia la pantalla y muestra el men�
        system("cls");

        // Imprime el t�tulo del juego
        cout << "El dados malditos" << endl;

        // Imprime las opciones del men�
        cout << "1- Un jugador" << endl;
        cout << "2- Dos jugadores" << endl;
        cout << "3- Mayor puntaje" << endl;
        cout << "4- Salir" << endl;
        // Solicita al usuario ingresar una opci�n
        cout << "Ingrese una opcion" << endl;
        cin >> opc;

        system("cls");
        // Eval�a la opci�n ingresada por el usuario
        switch (opc)
        {
        case '1':
            // Llama a la funci�n para un jugador
            unJugador(mp,mj);
            break;

        case '2':
            // Llama a la funci�n para dos jugadores (debe estar implementada)
            dosJugadores(mp,mj);
            break;

        case '3':
            // Llama a la funci�n para el mayor puntaje (debe estar implementada)
            mayorPuntuacion( mp,mj);
            break;

        case '4':
                system("pause");
            // Sale del programa
            return 0;

        default:
            // Mensaje para opciones inv�lidas
            cout << "Opcion invalida. Intente nuevamente" << endl;
            system("pause");
            break;
        }
    }
}

