#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define UN_JUGADOR_H_INCLUDED

using namespace std;

extern int dado[];
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

int unJugador()
{
    string jugador1,mj;
    int contadorTiradas = 0, puntuacion = 0, rondas = 1, contador;
    int contadorEscalera = 0, sexteto = 0;
    int contadorTrio = 0, TX=0, MAX1=0, MAX2=0,mp=0;

    cout << "Ingrese nombre de jugador: ";
    cin >> jugador1;

    while (puntuacion <= 500)
    {
        // Reinicia los contadores en cada iteración
        contadorEscalera = 0;
        sexteto = 0;
        MAX1=0, MAX2=0;


        srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios.
        for (int i = 0; i <= 5; i++)
        {
            dado[i] = 1 + rand() % 6;
            if (dado[i] == i + 1)
            {
                contadorEscalera++;
            }
            if (dado[i] == 6)
            {
                sexteto++;
            }

        }
// CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X
        for (int N = 0; N < 6; N++)
        {
            contadorTrio= 0;
            for(int D = 0; D <= 5; D++)
            {
                if (dado[D] == dado[N])
                {
                    contadorTrio ++;
                }
                if(contadorTrio==3)
                {
                    if (MAX1==0)
                    {
                        MAX1=dado[D];
                        contadorTrio = 0;
                    }
                    else
                    {
                        MAX2=dado[D];
                    }
                    if(MAX2>MAX1)
                    {
                        MAX1=MAX2;
                    }
                }

            }
        }
        puntuacion += MAX1*10;

// CODIGO TRIO X  CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X




        cout << "Ronda: " << rondas << endl;
        contadorTiradas++;
        mostrarDados();

        if (contadorTiradas % 3 == 0)
        {
            rondas++;
            system("cls");
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(44,3);
            cout<<"-----------------------------------------";
            rlutil::locate(44,5);
            cout<<" jugador "<<jugador1<<" suiguente ronda "<<rondas<< " puntaje "<<puntuacion<<endl;
            rlutil::locate(44,7);
            cout<<"-----------------------------------------";
            cout<<endl;
            rlutil::locate(44,8);
            system("pause");
            rlutil::setColor(rlutil::WHITE);
            system("cls");

        }

        if (contadorEscalera == 6)
        {
            cout << "Victoria por escalera" << endl;
            puntuacion = 501;
        }

        if (sexteto == 6)
        {
            cout<<"Sexteto!, puntuacion vuelve a 0"<<endl;
            puntuacion = 0;
        }

        if (contadorTrio < 3)
        {
            for (int x = 0; x < 6; x++)
            {
                puntuacion+= dado[x];
            }
        }



        // Verifica la puntuación y continúa o regresa al menú
        if (puntuacion < 500)
        {
            cout <<endl<< "Puntuacion actual: " << puntuacion << " (Necesitas 500 para ganar)" << endl;
            system("pause");
        }
    }
    //CARGA EL MAYOR PUNTAJE A SCORE SI ESTE ES MAYOR A MP
    if(puntuacion>mp)
    {
        mp = puntuacion;
        mj = jugador1;
    }

    return 0; // Puedes devolver un valor si es necesario
}


int MP(int& mp, string& mj)
{
    if(mp==0)
    {
        cout<<"Aun no se ha registrado ningun puntaje"<<endl;
        system("pause");
    }
    else
    {
        cout << "Jugador con mayor puntaje registrado es: "<<mj<< endl;
        cout << "Puntaje: "<<mp<< endl;
        system("pause");
    }


}

int dosJugadores()
{
    string jugador1, jugador2;
    int puntuacionJugador1 = 0, puntuacionJugador2 = 0, contadorTiradas = 0, rondas = 0;
    bool bandera = true;


    cout<<"Ingrese nombre del jugador 1: ";
    cin>>jugador1;
    cout<<"Ingrese nombre del jugador 2: ";
    cin>>jugador2;

    while (puntuacionJugador1 <= 500 || puntuacionJugador2 <= 500)
    {

        int contadorEscalera = 0, sexteto = 0, contador = 0;
        int contadorTrio = 0, TX=0, MAX1=0, MAX2=0;


        // Reinicia los contadores en cada iteración
        contadorEscalera = 0;
        sexteto = 0;
        MAX1=0, MAX2=0;

        if (contadorTiradas % 6 == 0)
        {
            if (rondas != 0) {
                                system("cls");
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(44,3);
            cout<<"-----------------------------------------";
            rlutil::locate(44,5);
            cout<<" suiguente ronda "<<rondas<<endl;
            rlutil::locate(44,6);
            cout<<" jugador "<<jugador1<< " puntaje "<<puntuacionJugador1<<endl;
            rlutil::locate(44,7);
            cout<<" jugador "<<jugador2<< " puntaje "<<puntuacionJugador2<<endl;
            rlutil::locate(44,8);
            cout<<"-----------------------------------------";
            cout<<endl;
            rlutil::locate(44,9);
            system("pause");
            rlutil::setColor(rlutil::WHITE);
            system("cls");

            }
            rondas++;

        }


        if (bandera)
        {
            cout<<endl<<endl<<"Jugador 1"<<endl;
            srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios.
            for (int i = 0; i <= 5; i++)
            {
                dado[i] = 1 + rand() % 6;
                if (dado[i] == i + 1)
                {
                    contadorEscalera++;
                }
                if (dado[i] == 6) {
                    sexteto++;
                }

            }
// CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X
            for (int N = 1; N < 7; N++)
            {
                contadorTrio=0;
                for(int D = 0; D <= 5; D++)
                {
                    if (dado[D] == N)
                    {
                        contadorTrio ++;
                    }
                    if(contadorTrio==3)
                    {
                        if (MAX1==0)
                        {
                            MAX1=dado[D];
                            contadorTrio = 0;
                        }
                        else
                        {
                            MAX2=dado[D];
                        }
                        if(MAX2>MAX1)
                        {
                            MAX1=MAX2;
                        }
                    }

                }
            }
            puntuacionJugador1 += MAX1*10;

// CODIGO TRIO X  CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X



            cout << "Ronda: " << rondas << endl;
            mostrarDados();

            if (contadorEscalera == 6)
            {
                cout << "Victoria por escalera" << endl;
                puntuacionJugador1 = 501;
            }

            if (contadorTrio < 3)
            {
                for (int x = 0; x < 6; x++)
                {
                    puntuacionJugador1+= dado[x];
                }
            }

            if (sexteto == 6)
            {
                cout<<"Sexteto! la puntuacion del jugador 1 volvera a 0";
                puntuacionJugador1 = 0;
            }



            // Verifica la puntuación y continúa o regresa al menú
            if (puntuacionJugador1 < 500)
            {
                cout <<endl<< "Puntuacion actual del jugador 1: " << puntuacionJugador1 << " (Necesitas 500 para ganar)" << endl;
                system("pause");
            }
        }
        else
        {
            cout<<endl<<endl<<"Jugador 2"<<endl;

            srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios.
            for (int i = 0; i <= 5; i++)
            {
                dado[i] = 1 + rand() % 6;
                if (dado[i] == i + 1)
                {
                    contadorEscalera++;
                }
                if (dado[i] == 6)
                {
                    sexteto++;
                }
            }
// CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X
            for (int N = 1; N < 7; N++)
            {
                for(int D = 0; D <= 5; D++)
                {
                    if (dado[D] == N)
                    {
                        contadorTrio ++;
                    }
                    if(contadorTrio==3)
                    {
                        if (MAX1==0)
                        {
                            MAX1=dado[D];
                        }
                        else
                        {
                            MAX2=dado[D];
                        }
                        if(MAX2>MAX1)
                        {
                            MAX1=MAX2;
                        }
                    }

                }
            }
            puntuacionJugador2 += MAX1*10;

// CODIGO TRIO X  CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X



            cout << "Ronda: " << rondas << endl;
            mostrarDados();

            if (contadorEscalera == 6)
            {
                cout << "Victoria por escalera" << endl;
                puntuacionJugador2 = 501;
            }

            if (contadorTrio < 3)
            {
                for (int x = 0; x < 6; x++)
                {
                    puntuacionJugador2+= dado[x];
                }
            }

            if (sexteto == 6)
            {
                cout<<"Sexteto! La puntuacion del jugador 2 volvera a 0" <<endl;
                puntuacionJugador2 = 0;

            }



            // Verifica la puntuación y continúa o regresa al menú
            if (puntuacionJugador2 < 500)
            {
                cout <<endl<< "Puntuacion actual del jugador 2: " << puntuacionJugador2 << " (Necesitas 500 para ganar)" << endl;
                system("pause");
            }
        }
        contadorTiradas++;
        bandera = !bandera;
    }


}

