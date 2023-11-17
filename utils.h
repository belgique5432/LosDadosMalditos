#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define UN_JUGADOR_H_INCLUDED

using namespace std;

extern int dado[6];
int dado[6];
int mp;
string mj;

/*Funcion mostrarDados:
        Se encarga de imprimir un dise�o de dado dependiendo del numero recibido
        utiliza el dado[i] para eso
*/
int mostrarDados()
{
    rlutil::setColor(rlutil::MAGENTA);
    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 2)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 3)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 4)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 5)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 6)
        {
            cout << " -------   ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 2)
        {
            cout << "| *     |  ";
        }
        else if (dado[i] == 3)
        {
            cout << "| *     |  ";
        }
        else if (dado[i] == 4)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 5)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 6)
        {
            cout << "| *   * |  ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << "|   *   |  ";
        }
        else if (dado[i] == 2)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 3)
        {
            cout << "|   *   |  ";
        }
        else if (dado[i] == 4)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 5)
        {
            cout << "|   *   |  ";
        }
        else if (dado[i] == 6)
        {
            cout << "| *   * |  ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << "|       |  ";
        }
        else if (dado[i] == 2)
        {
            cout << "|     * |  ";
        }
        else if (dado[i] == 3)
        {
            cout << "|     * |  ";
        }
        else if (dado[i] == 4)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 5)
        {
            cout << "| *   * |  ";
        }
        else if (dado[i] == 6)
        {
            cout << "| *   * |  ";
        }
    }

    cout << endl;

    for (int i = 0; i <= 5; i++)
    {
        if (dado[i] == 1)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 2)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 3)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 4)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 5)
        {
            cout << " -------   ";
        }
        else if (dado[i] == 6)
        {
            cout << " -------   ";
        }
    }
    rlutil::setColor(rlutil::WHITE);
}

int unJugador(int &mp, string &mj)
{
    string jugador1, ganador;
    int contadorTiradas = 0, puntuacion = 0, rondas = 1, contador;
    int contadorEscalera = 0, banderaV = 0;
    int contadorTrio = 0, TX = 0, MAX1 = 0, MAX2 = 0;

    cout << "Ingrese nombre de jugador: ";
    cin >> jugador1;

    //

    // Bucle principal de unJugador

    while (puntuacion <= 500 && rondas <= 8)
    {
        // Reinicia los contadores en cada iteraci�n
        contadorEscalera = 0;
        banderaV = 0;
        MAX1 = 0, MAX2 = 0;

        srand(time(NULL)); // Inicializa la semilla para la generaci�n de n�meros aleatorios.
        // Carga del dao
        for (int i = 0; i <= 5; i++)
        {
            dado[i] = 1 + rand() % 6;
            if (dado[i] == i + 1)
            {
                contadorEscalera++;
            }
        }

       cout << "Ronda: " << rondas<<" Jugador: "<<jugador1 << endl;
		contadorTiradas++;
		mostrarDados();

        // VALIDACIONES  **** VALIDACIONES ***** VALIDACIONES ***** VALIDACIONES

        // Codigo de escalera
        if (contadorEscalera == 6)
        {
           	rlutil::setColor(rlutil::RED);
			cout<<"-----------------------------------------";
			rlutil::locate(48,5);
			cout << "Victoria por escalera" << endl;
			rlutil::locate(44,7);
			cout<<"-----------------------------------------";
			cout<<endl;
			rlutil::locate(44,8);
			rlutil::setColor(rlutil::WHITE);
			system("pause");
			break;
        }

        // Codigo de sexteto x y sexteto
        bool sonIguales = true;
        for (int i = 1; i < 6; i++)
        {
            if (dado[i] != dado[0])
            {
                sonIguales = false;
            }
        }

        if (sonIguales == true)
        {
            banderaV = 1;
            if (dado[0] == 6)
            {
	rlutil::setColor(rlutil::RED);
				cout<<"-----------------------------------------";
				cout<<endl;
				cout<<" Sexteto de Seis! :c puntuacion volvera a 0 "<<endl;
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);
				puntuacion = 0;
            }
            else
            {
                cout << endl
                     << "Puntuacion actual " << puntuacion << endl;
                cout << "Sexteto de " << dado[0] << " Por lo que " << dado[0] << " se multiplicara X 50" << endl;
                puntuacion += dado[0] * 50;
            }
        }
        // Fin de sexteto

        // Codigo de Trio x
        if (sonIguales == false)
        {
            for (int N = 0; N < 6; N++)
            {
                contadorTrio = 0;
                for (int D = 0; D <= 5; D++)
                {
                    if (dado[D] == dado[N])
                    {
                        contadorTrio++;
                    }
                    if (contadorTrio == 3)
                    {
                        banderaV = 1;
                        if (MAX1 == 0)
                        {
                            MAX1 = dado[D];
                            contadorTrio = 0;
                        }
                        else
                        {
                            MAX2 = dado[D];
                            contadorTrio = 0;
                        }
                        if (MAX2 > MAX1)
                        {
                            MAX1 = MAX2;
                        }
                    }
                }
            }
            if (MAX1 != 0)
            {
                rlutil::setColor(rlutil::RED);
				cout<<endl<<"-----------------------------------------"<<endl;
				cout<<"Salio un -TRIOX++- GENIAL"<<endl;
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);
                puntuacion += MAX1 * 10;
            }
        }
        // Fin del codigo de Trio x

        // Si no se cumple ninguna condicion se suman los dados
        if (banderaV == 0)
        {
            for (int i = 0; i <= 5; i++)
            {
                puntuacion += dado[i];
            }
        }
        // FIN VALIDACIONES  **** FIN VALIDACIONES ***** FIN VALIDACIONES ***** FIN VALIDACIONES

        // Verifica la puntuaci�n y contin�a o regresa al men�
        if (puntuacion < 500)
        {
            cout << endl
                 << "Puntuacion actual: " << puntuacion << " (Necesitas 500 para ganar)" << endl;
            system("pause");
        }

        // Muestra el cambio de las rondas

        if (contadorTiradas % 3 == 0)
        {
            rondas++;
            system("cls");
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(44, 3);
            cout << "-----------------------------------------";
            rlutil::locate(44, 5);
            cout << " jugador " << jugador1 << " suiguente ronda " << rondas << " puntaje " << puntuacion << endl;
            rlutil::locate(44, 7);
            cout << "-----------------------------------------";
            cout << endl;
            rlutil::locate(44, 8);
            system("pause");
            rlutil::setColor(rlutil::WHITE);
            system("cls");
        }
    }
            system("cls");
			rlutil::setColor(rlutil::MAGENTA);
			rlutil::locate(44,3);
			cout<<"-----------------------------------------";
			rlutil::locate(48,5);
			cout<<"VICTORIA USTED GANO "<<endl;
			rlutil::locate(48,6);
			cout<<" con "<<puntuacion<<" puntos "<<endl;
			rlutil::locate(44,7);
			cout<<"-----------------------------------------";
			cout<<endl;
			rlutil::locate(44,8);
			system("pause");
			rlutil::setColor(rlutil::WHITE);
			system("cls");

    // Carga la puntuacion a mp y define al jugador de la puntuacion

    if (puntuacion > mp)
    {
        mp = puntuacion;
        mj = jugador1;
    }
    //

    // Muestra el ganador de la partida y la cantidad de rondas que tardo en ganar

    if (puntuacion >= 500)
    {
        ganador = jugador1;
        system("cls");
        cout << "El ganador es: " << jugador1 << " le tomo: " << rondas << " ganar" << endl;
        system("pause");
        system("cls");
    }

    return 0;
}

// ********* FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********

// Funcion de mayor puntaje

int mayorPuntaje(int &mp, string &mj)
{

    if (mp == 0)
    {
       system("cls");
		rlutil::setColor(rlutil::RED);
		rlutil::locate(44,3);
		cout<<"-----------------------------------------";
		rlutil::locate(44,5);
		cout<<"Aun no se ha registrado ningun puntaje"<<endl;
		rlutil::locate(44,7);
		cout<<"-----------------------------------------";
		cout<<endl;
		rlutil::locate(44,8);
		system("pause");
		rlutil::setColor(rlutil::WHITE);

    }
    else
    {
       system("cls");
		rlutil::setColor(rlutil::GREEN);
		rlutil::locate(44,3);
		cout<<"-----------------------------------------";
		rlutil::locate(44,5);
		cout << "Jugador con mayor puntaje registrado es: "<<mj<< endl;
		rlutil::locate(44,7);
		cout << "Puntaje: "<<mp<< endl;
		rlutil::locate(44,8);
		cout<<"-----------------------------------------";
		cout<<endl;
		rlutil::locate(44,9);
		system("pause");
		rlutil::setColor(rlutil::WHITE);

    }
}

// ********* FIN FUNCION MAYOR PUNTAJE ***********  FIN FUNCION MAYOR PUNTAJE ***********  FIN FUNCION MAYOR PUNTAJE ***********

//****************FUNCION DE DOS JUGADORES *****************

int dosJugadores(int &mp, string &mj)
{
    string jugador1, jugador2, ganador;
    int puntuacionJugador1 = 0, puntuacionJugador2 = 0, contadorTiradas = 0, rondas = 0, banderaV = 0;
    bool bandera = true;

    cout << "Ingrese nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese nombre del jugador 2: ";
    cin >> jugador2;

    while (puntuacionJugador1 <= 500 || puntuacionJugador2 <= 500 && rondas <= 8)
    {

        int contadorEscalera = 0, sexteto = 0, contador = 0;
        int contadorTrio = 0, TX = 0, MAX1 = 0, MAX2 = 0, banderaV = 0;

        // Reinicia los contadores en cada iteraci�n
        contadorEscalera = 0;
        sexteto = 0;
        MAX1 = 0, MAX2 = 0;

        // Muestra los carteles entre rondas para saber la puntuacion y suma las rondas

        if (contadorTiradas % 6 == 0)
        {
            if (rondas != 0) // Verifica que no sea la primer ronda para no tirar el cartel al inicio del juego
            {
                system("cls");
                rlutil::setColor(rlutil::YELLOW);
                rlutil::locate(44, 3);
                cout << "-----------------------------------------";
                rlutil::locate(44, 5);
                cout << " suiguente ronda " << rondas << endl;
                rlutil::locate(44, 6);
                cout << " jugador " << jugador1 << " puntaje " << puntuacionJugador1 << endl;
                rlutil::locate(44, 7);
                cout << " jugador " << jugador2 << " puntaje " << puntuacionJugador2 << endl;
                rlutil::locate(44, 8);
                cout << "-----------------------------------------";
                cout << endl;
                rlutil::locate(44, 9);
                system("pause");
                rlutil::setColor(rlutil::WHITE);
                system("cls");
            }
            rondas++;
        }

        if (bandera) // verifica el valor de la bandera para saber que jugador tira el dado
        {
            cout << endl
                 << endl
                 << "Jugador 1" << endl;

            srand(time(NULL)); // Inicializa la semilla para la generaci�n de n�meros aleatorios.

            for (int i = 0; i <= 5; i++)
            {
                dado[i] = 1 + rand() % 6;
                if (dado[i] == i + 1)
                {
                    contadorEscalera++;
                }
            }

            // Sexteto x y sexteto

            bool sonIguales = true;
            for (int i = 1; i < 6; i++)
            {
                if (dado[i] != dado[0])
                {
                    sonIguales = false;
                }
            }

            if (sonIguales == true)
            {
                banderaV = 1;
                if (dado[0] == 6)
                {
rlutil::setColor(rlutil::RED);
				cout<<"-----------------------------------------";
				cout<<endl;
				cout<<" Sexteto de Seis! :c puntuacion volvera a 0 "<<endl;
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);
				puntuacionJugador1 = 0;
                }
                else
                {
                    cout << endl
                         << "Puntuacion actual " << puntuacionJugador1 << endl;
                    cout << "Sexteto de " << dado[0] << " Por lo que " << dado[0] << " se multiplicara X 50" << endl;
                    puntuacionJugador1 += dado[0] * 50;
                }
            }

            // Codigo de Trio X

            if (sonIguales == false)
            {
                for (int N = 0; N < 6; N++)
                {
                    contadorTrio = 0;
                    for (int D = 0; D <= 5; D++)
                    {
                        if (dado[D] == dado[N])
                        {
                            contadorTrio++;
                        }
                        if (contadorTrio == 3)
                        {
                            banderaV = 1;
                            if (MAX1 == 0)
                            {
                                MAX1 = dado[D];
                                contadorTrio = 0;
                            }
                            else
                            {
                                MAX2 = dado[D];
                                contadorTrio = 0;
                            }
                            if (MAX2 > MAX1)
                            {
                                MAX1 = MAX2;
                            }
                        }
                    }
                }
                if (MAX1 != 0)
                {
                  rlutil::setColor(rlutil::LIGHTMAGENTA);
				cout<<endl<<"-----------------------------------------"<<endl;
				cout<<"Salio un -TRIOX++- GENIAL"<<endl;
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);
                    puntuacionJugador1 += MAX1 * 10;
                }
            }

            // Muestra los dados y las rondas

            cout << "Ronda: " << rondas << endl;
            mostrarDados();

            // Verifica si se cumple la condicion para la victoria por escalera

            if (contadorEscalera == 6)
            {
                cout << "Victoria por escalera" << endl;
                puntuacionJugador1 = 501;
            }

            if (banderaV == 0) // Si no se cumple ninguna condicion se suma el valor de los dados
            {
                for (int i = 0; i <= 5; i++)
                {
                    puntuacionJugador1 += dado[i];
                }
            }

            // Verifica la puntuaci�n y contin�a o regresa al men�
            if (puntuacionJugador1 < 500)
            {
                cout << endl
                     << "Puntuacion actual del jugador 1: " << puntuacionJugador1 << " (Necesitas 500 para ganar)" << endl;
                system("pause");
            }
        }
        else
        {
            cout << endl
                 << endl
                 << "Jugador 2" << endl;

            srand(time(NULL)); // Inicializa la semilla para la generaci�n de n�meros aleatorios.
            for (int i = 0; i <= 5; i++)
            {
                dado[i] = 1 + rand() % 6;
                if (dado[i] == i + 1)
                {
                    contadorEscalera++;
                }
            }

            // Inicio de sexteto x y sexteto

            bool sonIguales = true;
            for (int i = 1; i < 6; i++)
            {
                if (dado[i] != dado[0])
                {
                    sonIguales = false;
                }
            }

            if (sonIguales == true)
            {
                banderaV = 1;
                if (dado[0] == 6)
                {
rlutil::setColor(rlutil::RED);
				cout<<"-----------------------------------------";
				cout<<endl;
				cout<<" Sexteto de Seis! :c puntuacion volvera a 0 "<<endl;
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);
                puntuacionJugador2 = 0;
                }
                else
                {
                    cout << endl
                         << "Puntuacion actual " << puntuacionJugador2 << endl;
                    cout << "Sexteto de " << dado[0] << " Por lo que " << dado[0] << " se multiplicara X 50" << endl;
                    puntuacionJugador2 += dado[0] * 50;
                }
            }

            // Codigo de Trio X

            if (sonIguales == false)
            {
                for (int N = 0; N < 6; N++)
                {
                    contadorTrio = 0;
                    for (int D = 0; D <= 5; D++)
                    {
                        if (dado[D] == dado[N])
                        {
                            contadorTrio++;
                        }
                        if (contadorTrio == 3)
                        {
                            banderaV = 1;
                            if (MAX1 == 0)
                            {
                                MAX1 = dado[D];
                                contadorTrio = 0;
                            }
                            else
                            {
                                MAX2 = dado[D];
                                contadorTrio = 0;
                            }
                            if (MAX2 > MAX1)
                            {
                                MAX1 = MAX2;
                            }
                        }
                    }
                }
                if (MAX1 != 0)
                {
                 rlutil::setColor(rlutil::RED);
				cout<<endl<<"-----------------------------------------"<<endl;
				cout<<"Salio un -TRIOX++- GENIAL"<<endl;
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);

                puntuacionJugador2 += (MAX1 * 10);
                }
            }

            // Muestra los dados y las rondas

            cout << "Ronda: " << rondas << endl;
            mostrarDados();

            if (contadorEscalera == 6)
            {

rlutil::locate(44,3);
			rlutil::setColor(rlutil::RED);
			cout<<"-----------------------------------------";
			rlutil::locate(48,5);
			cout << "Victoria por escalera" << endl;
			rlutil::locate(44,7);
			cout<<"-----------------------------------------";
			cout<<endl;
			rlutil::locate(44,8);
			rlutil::setColor(rlutil::WHITE);
			system("pause");
			break;

            }

            if (banderaV == 0) // Si no se cumple ninguna condicion suma los valores de los dados
            {
                for (int i = 0; i <= 5; i++)
                {
                    puntuacionJugador2 += dado[i];
                }
            }

            // Verifica la puntuaci�n y contin�a o regresa al men�

            if (puntuacionJugador2 < 500)
            {
                cout << endl
                     << "Puntuacion actual del jugador 2: " << puntuacionJugador2 << " (Necesitas 500 para ganar)" << endl;
                system("pause");
            }
        }

        // Suma las tiradas de los dados y cambia la bandera para el cambio de jugador

        contadorTiradas++;
        bandera = !bandera;
    }

    // Setea la puntuacion maxima con el nombre del jugador que la posee y que puntuacion consiguio

    if (puntuacionJugador1 > mp)
    {
        mp = puntuacionJugador1;
        mj = jugador1;
    }
    if (puntuacionJugador2 > mp)
    {
        mp = puntuacionJugador2;
        mj = jugador2;
    }

    // Muestra el ganador de la partida y la cantidad de rondas que tardo en ganar

    if (puntuacionJugador1 >= 500 & puntuacionJugador1 > puntuacionJugador2)
    {
        ganador = jugador1;
         rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);

            system("cls");
			rlutil::setColor(rlutil::GREEN);
			rlutil::locate(44,3);
			cout<<"-----------------------------------------";
			rlutil::locate(44,5);
			cout << "El ganador es: " << jugador1 << " le tomo: " << rondas << " ganar" << endl;
			rlutil::locate(44,7);
			cout<<"-----------------------------------------";
			cout<<endl;
			rlutil::locate(44,8);
			system("pause");
			rlutil::setColor(rlutil::WHITE);
			system("cls");
    }
    if (puntuacionJugador2 >= 500 && puntuacionJugador2 > puntuacionJugador1)
    {
        ganador = jugador1;
         rlutil::setBackgroundColor(rlutil::CYAN);
      system("cls");
			rlutil::setColor(rlutil::MAGENTA);
			rlutil::locate(44,3);
			cout<<"-----------------------------------------";
			rlutil::locate(44,5);
			 cout << "El ganador es: " << jugador2 << " le tomo: " << rondas << " ganar" << endl;
			rlutil::locate(44,7);
			cout<<"-----------------------------------------";
			cout<<endl;
			rlutil::locate(44,8);
			system("pause");
			rlutil::setColor(rlutil::WHITE);
			system("cls");
    }
}
