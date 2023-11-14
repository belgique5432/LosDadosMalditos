#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define UN_JUGADOR_H_INCLUDED

using namespace std;

extern int dado[];
int mostrarDados()
{
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
}

int unJugador(int& mp, string& mj)
{
    string jugador1;
    int contadorTiradas = 0, puntuacion = 0, rondas = 1;
    int contadorEscalera = 0, sexteto = 0;
    int contadorTrio = 0, TX=0, MAX1=0, MAX2=0;

    cout << "Ingrese nombre de jugador: ";
    cin >> jugador1;

    while (puntuacion <= 500)
    {
        // Reinicia los contadores en cada iteraci�n
        contadorEscalera = 0;
        sexteto = 0;
        MAX1=0, MAX2=0;


        bool sonIguales = true;

        for (int i = 0; i <= 5; i++)
        {
            dado[i] = 1 + rand() % 6;
            if (dado[i] == i + 1)
            {
                contadorEscalera++;
            }
            puntuacion += dado[i];
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
        system("pause");
        cout<<"ES TX "<<MAX1 <<endl;

        if (contadorTiradas % 3 == 0)
        {
            rondas++;
            system("cls");
            rlutil::setColor(rlutil::BLUE);
            rlutil::locate(5,5);
            cout<<"-----------------------------------------";
            rlutil::locate(5,6);
            cout<<" jugador "<<jugador1<<" siguiente ronda "<<rondas<< " puntaje "<<puntuacion<<endl;
            rlutil::locate(5,7);
            cout<<"-----------------------------------------";
            rlutil::locate(44,6);
            cout<<"|";
            rlutil::locate(3,6);
            cout<<"|";
            cout<<endl;
            system("pause");
            rlutil::setColor(rlutil::WHITE);
            system("cls");

        }

        if (contadorEscalera == 6)
        {
            cout << "Victoria por escalera" << endl;
            puntuacion = 501;
        }



        // Verifica la puntuaci�n y contin�a o regresa al men�
        if (puntuacion < 500)
        {
            cout << "Puntuacion actual: " << puntuacion << " (Necesitas 500 para ganar)" << endl;
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
    int puntuacionJugador1 = 0, puntuacionJugador2 = 0, contadorTiradas = 0, rondas = 1;
    bool bandera = true;


    cout<<"Ingrese nombre del jugador 1: ";
    cin>>jugador1;
    cout<<"Ingrese nombre del jugador 2: ";
    cin>>jugador2;

    while (puntuacionJugador1 <= 500 || puntuacionJugador2 <= 500)
    {

        int contadorEscalera = 0, sexteto = 0;
        int contadorTrio = 0, TX=0, MAX1=0, MAX2=0;


        // Reinicia los contadores en cada iteraci�n
        contadorEscalera = 0;
        sexteto = 0;
        MAX1=0, MAX2=0;

            if (contadorTiradas % 6 == 0) {
                    rondas++;
                }


            if (bandera)
            {
                cout<<"Jugador 1";
                bool sonIguales = true;

                for (int i = 0; i <= 5; i++)
                {
                    dado[i] = 1 + rand() % 6;
                    if (dado[i] == i + 1)
                    {
                        contadorEscalera++;
                    }
                    puntuacionJugador1 += dado[i];
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
                contadorTiradas++;
                cout<<"tiradas: " <<contadorTiradas <<endl;
                mostrarDados();
                system("pause");
                cout<<"ES TX "<<MAX1 <<endl;

                if (contadorEscalera == 6)
                {
                    cout << "Victoria por escalera" << endl;
                    puntuacionJugador1 = 501;
                }



                // Verifica la puntuaci�n y contin�a o regresa al men�
                if (puntuacionJugador1 < 500)
                {
                    cout << "Puntuacion actual del jugador 1: " << puntuacionJugador1 << " (Necesitas 500 para ganar)" << endl;
                    system("pause");
                }
            }  else
        {
            cout<<"Jugador 2";

            bool sonIguales = true;

            for (int i = 0; i <= 5; i++)
            {
                dado[i] = 1 + rand() % 6;
                if (dado[i] == i + 1)
                {
                    contadorEscalera++;
                }
                puntuacionJugador2 += dado[i];
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
            contadorTiradas++;
            mostrarDados();
            system("pause");
            cout<<"ES TX "<<MAX1 <<endl;

            if (contadorEscalera == 6)
            {
                cout << "Victoria por escalera" << endl;
                puntuacionJugador2 = 501;
            }



            // Verifica la puntuaci�n y contin�a o regresa al men�
            if (puntuacionJugador2 < 500)
            {
                cout << "Puntuacion actual del jugador 2: " << puntuacionJugador2 << " (Necesitas 500 para ganar)" << endl;
                system("pause");
            }
        }
            contadorTiradas++;
            bandera = !bandera;
}


}

