#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define UN_JUGADOR_H_INCLUDED

using namespace std;



int mostrarDados(int dado[])
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


int mayorPuntuacion (int mp, string mj)
{
    if (mp == 0)
    {
        cout<<"Todavia no hay puntuaciones establecidas" <<endl;
        system("pause");
    }
    else
    {
        cout<<"El jugador de mayor puntaje es: " <<mj;
        system("pause");
    }
}


// Función principal del juego para un solo jugador
int unJugador(int& mp, string& mj)
{
    int dado[6], puntuacion = 0, rondas = 1, comparaPuntuaciones[3], puntuacionJugador1 = 0;
    int c,p,x,i, Max = 0, banderaV = 0, contadorTrio = 0, Max1 = 0, Max2 = 0, puntuacionFinal = 0, bandera6 = 0;
    string jugador1;

    cout << "Ingrese nombre de jugador:" << endl;
    cin >> jugador1;
    // Bucle principal del juego
    while (puntuacionFinal <= 500 && rondas <= 10)
    {
        Max1 = 0, Max2 = 0, Max = 0;
        banderaV = 0, bandera6 = 0;
        int contadorEscalera = 0;
        cout<<" ronda "<<rondas<<" jugador "<<jugador1<<endl;
        // Bucle para realizar 3 rondas por jugador

        for (int x = 0; x < 3; x++ )
        {
            puntuacion = 0;
            banderaV = 0;
            contadorEscalera = 0;

            // Inicialización del arreglo comparaPuntuaciones
            if(x==0)
            {
                for (int i = 0; i < 3; i++)
                {
                    comparaPuntuaciones[i] = 0;

                }

            }

            // Generación de valores aleatorios para los dados
            srand(time(NULL));
            for (int c = 0; c < 6; c++)
            {
                dado[c] = 1 + rand() % 6;
                // cin>>dado[c];
                if (dado[c] == c + 1)
            {
                contadorEscalera++;
            }
            }

            // Llamada a la función para mostrar los valores de los dados
            mostrarDados(dado);

            // Comprobación de si todos los dados son iguales
        if (contadorEscalera == 6) {
            cout<<"Escalera, ganaste la partida!" <<endl;
            puntuacionFinal = 501;
            break;
        }

            bool sonIguales = true;
            for (int i = 0; i < 6; i++)
            {
                if (dado[i] != dado[0])
                {
                    sonIguales = false;
                }
            }

            // Manejo de la situación cuando todos los dados son iguales
            if (sonIguales == true)
            {
                banderaV = 1;
                if (dado[0] == 6)
                {
                    cout << "Sexteto! la puntuación vuelve a cero" << endl;
                    bandera6=1;
                    puntuacion=0;
                    break;
                }
                else
                {
                    cout << "Sexteto de " << dado[0] << " La puntuación multiplica el valor del dado * 50" << endl;
                    puntuacion += dado[0] * 50;
                    cout<<"La puntuacion actual es: "<<puntuacion;
                }
            }

            // Manejo de la situación cuando no todos los dados son iguales
            Max1 = 0;
            Max2 = 0;
            if (sonIguales == false)
            {
                // Comprobación de tríos
                for (int N = 0; N < 6; N++)
                {
                    contadorTrio = 0;
                    for (int D = 0; D < 6; D++)
                    {
                        if (dado[D] == dado[N])
                        {
                            contadorTrio++;
                        }
                        if (contadorTrio == 3)
                        {
                            banderaV = 1;
                            if (Max1 == 0)
                            {
                                Max1 = dado[D];
                                contadorTrio = 0;
                            }
                            else
                            {
                                Max2 = dado[D];
                                contadorTrio = 0;
                            }
                            if (Max2 > Max1)
                            {
                                Max1 = Max2;
                            }
                        }
                    }
                }
                // Manejo de la situación cuando se obtiene un trío
                if (Max1 != 0)
                {
                    cout << "Salio un Trio X" << endl;
                    puntuacion += Max1 * 10;
                }

                // Manejo de la situación cuando no se obtiene un trío
                if (banderaV == 0)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        puntuacion += dado[i];
                    }
                }
            }

            // Almacenamiento de la puntuación de la ronda en el arreglo comparaPuntuaciones
            comparaPuntuaciones[x] = puntuacion;
            cout << " Puntuacion " << puntuacion  << endl;

            // Pausa para mostrar la puntuación antes de la siguiente ronda
            system("pause");


            // Determinación de la puntuación máxima de la ronda
            for (int y = 0; y < 3; y++)
            {
                if (comparaPuntuaciones[y] > Max && bandera6 != 1)
                {
                    Max = comparaPuntuaciones[y];
                }
            }
            puntuacionJugador1 = Max;
        }


        // Mostrar la puntuación de la ronda
        cout << "Puntuacion de la ronda: " << puntuacionJugador1 << endl;
        system("pause");
        system("cls");
        rondas++;

        // Actualización de la puntuación total y visualización
        puntuacionFinal += Max;
        if(bandera6==1)
        {
            cout<<endl<<"Recorda que sacaste un sexteto de 6, tu puntuacion vuelve a 0 :c"<<endl;
            puntuacionJugador1=0;
            puntuacionFinal=0;
        }
        cout << "La puntuacion Total es: " << puntuacionFinal << " Ronda: " << rondas << endl;
        system("pause");

        // Actualización de la máxima puntuación y el nombre del jugador
        if (mp == 0)
        {
            mp = puntuacionFinal;
            mj = jugador1;
        }
        else if (puntuacionFinal > mp)
        {
            mp = puntuacionFinal;
            mj = jugador1;
        }
    }//W22
    system("cls");
    cout<<" el jugador "<<jugador1<<" termino el juego con "<<puntuacionFinal<<" puntos "<<" y  en "<<rondas<<" rondas "<<endl;
    system("pause");

    // Finalización del juego y retorno de 0
    return 0;
}

int dosJugadores(int& mp, string& mj)
{
    int dado[6], puntuacionJugador1 = 0, puntuacionJugador2 = 0, puntuacion = 0, rondas = 1, comparaPuntuaciones[3];
    int Max = 0, banderaV = 0, contadorTrio = 0, Max1 = 0, Max2 = 0, puntuacionFinalJugador1 = 0, puntuacionFinalJugador2 = 0, contador = 0, bandera6 = 0;
    string jugador1, jugador2;
    bool bandera = true;

    cout << "Ingrese nombre del jugador 1: " << endl;
    cin >> jugador1;
    cout << "Ingrese nombre del jugador 2: " << endl;
    cin >> jugador2;
    system("pause");
    system("cls");

    // Bucle principal del juego

    while (puntuacionFinalJugador1 <= 500 & puntuacionFinalJugador2 <= 500 && rondas <= 10)
    {
        Max1 = 0, Max2 = 0, Max = 0;
        banderaV = 0;
        bool banderaEscalera = false;

        if (contador != 0)
        {
            cout << "La puntuacion Total de " <<jugador1 <<" es: " << puntuacionFinalJugador1 << " Ronda: " << rondas << endl;
            cout << "La puntuacion Total de " <<jugador2 <<" es: "<< puntuacionFinalJugador2 << " Ronda: " << rondas << endl;
            system("pause");
            system("cls");
        }
        contador++;
        if (bandera == true)
        {

            cout<<"Turno de: " <<jugador1 <<" Ronda " <<rondas <<" Puntaje total: " <<puntuacionFinalJugador1<<endl;
            // Bucle para realizar 3 rondas por jugador
            for (int x = 0; x < 3; x++ )
            {
                puntuacion = 0;
                banderaV = 0;
                Max1 = 0;
                Max2 = 0;
                int contadorEscalera = 0;


                // Inicialización del arreglo comparaPuntuaciones
                if(x==0)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        comparaPuntuaciones[i] = 0;
                    }
                }

                // Generación de valores aleatorios para los dados
                srand(time(NULL));
                for (int c = 0; c < 6; c++)
                {
                     dado[c] = 1 + rand() % 6;
                    //cin>>dado[c];
              if (dado[c] == c + 1)
            {
                contadorEscalera++;
            }

                }

            if (contadorEscalera == 6) {
            cout<<"Escalera, ganaste la partida " <<jugador1 <<"!"<<endl;
            puntuacionFinalJugador1 = 501;
            banderaEscalera = true;
            rondas = rondas - 1;
            break;
        }

                // Llamada a la función para mostrar los valores de los dados
                mostrarDados(dado);

                // Comprobación de si todos los dados son iguales
                bool sonIguales = true;
                for (int i = 0; i < 6; i++)
                {
                    if (dado[i] != dado[0])
                    {
                        sonIguales = false;
                    }
                }

                // Manejo de la situación cuando todos los dados son iguales
                if (sonIguales == true)
                {
                    banderaV = 1;
                    if (dado[0] == 6)
                    {
                        cout << "Sexteto! la puntuación vuelve a cero" << endl;
                        bandera6=1;
                        puntuacion=0;
                        break;
                    }
                    else
                    {
                        cout << "Sexteto de " << dado[0] << " La puntuación multiplica el valor del dado * 50" << endl;
                        puntuacion += dado[0] * 50;
                    }
                }

                // Manejo de la situación cuando no todos los dados son iguales
                Max1 = 0;
                Max2 = 0;
                if (sonIguales == false)
                {
                    // Comprobación de tríos
                    for (int N = 0; N < 6; N++)
                    {
                        contadorTrio = 0;
                        for (int D = 0; D < 6; D++)
                        {
                            if (dado[D] == dado[N])
                            {
                                contadorTrio++;
                            }
                            if (contadorTrio == 3)
                            {
                                banderaV = 1;
                                if (Max1 == 0)
                                {
                                    Max1 = dado[D];
                                    contadorTrio = 0;
                                }
                                else
                                {
                                    Max2 = dado[D];
                                    contadorTrio = 0;
                                }
                                if (Max2 > Max1)
                                {
                                    Max1 = Max2;
                                }
                            }
                        }
                    }

                    // Manejo de la situación cuando se obtiene un trío
                    if (Max1 != 0)
                    {
                        cout << "Salio un Trio X" << endl;
                        puntuacion += Max1 * 10;
                    }

                    // Manejo de la situación cuando no se obtiene un trío
                    if (banderaV == 0)
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            puntuacion += dado[i];
                        }
                    }
                }
                // Almacenamiento de la puntuación de la ronda en el arreglo comparaPuntuaciones
                comparaPuntuaciones[x] = puntuacion;

                // Pausa para mostrar la puntuación antes de la siguiente ronda
                system("pause");


                // Determinación de la puntuación máxima de la ronda
                for (int y = 0; y < 3; y++)
                {
                    if (comparaPuntuaciones[y] > Max && bandera6 != 1)
                    {
                        Max = comparaPuntuaciones[y];
                    }

                }
                puntuacionJugador1 = Max;
            }

            // Mostrar la puntuación de la ronda
            cout << "Puntuacion de la ronda: " << puntuacionJugador1 << endl;
            system("pause");
            system("cls");

            // Actualización de la puntuación total y visualización
            puntuacionFinalJugador1 += Max;
            if(bandera6==1)
            {
                cout<<endl<<"Recorda que sacaste un sexteto de 6, tu puntuacion vuelve a 0 :c"<<endl;
                puntuacionFinalJugador1=0;
                bandera6 = 0;
            }
            bandera = !bandera;

        }

        if (bandera == false && banderaEscalera == false)
        {
            cout<<"Turno de: " <<jugador2 <<" Ronda " <<rondas <<" Puntaje total: " <<puntuacionFinalJugador2<<endl;
            puntuacion = 0;
            Max = 0;
            // Bucle para realizar 3 rondas por jugador
            for (int x = 0; x < 3; x++ )
            {
                puntuacion = 0;
                banderaV = 0;
                Max1 = 0;
                Max2 = 0;
                int contadorEscalera = 0;


                // Inicialización del arreglo comparaPuntuaciones
                if(x==0)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        comparaPuntuaciones[i] = 0;
                    }
                }

                // Generación de valores aleatorios para los dados
                srand(time(NULL));
                for (int c = 0; c < 6; c++)
                {
                     dado[c] = 1 + rand() % 6;
                    //cin>>dado[c];
                if (dado[c] == c + 1)
            {
                contadorEscalera++;
            }
                }

                // Llamada a la función para mostrar los valores de los dados
                mostrarDados(dado);

            if (contadorEscalera == 6) {
            cout<<"Escalera, ganaste la partida " <<jugador2 <<" !" <<endl;
            puntuacionFinalJugador2 = 501;
            rondas = rondas - 1;
            break;
        }

                // Comprobación de si todos los dados son iguales
                bool sonIguales = true;
                for (int i = 0; i < 6; i++)
                {
                    if (dado[i] != dado[0])
                    {
                        sonIguales = false;
                    }
                }

                // Manejo de la situación cuando todos los dados son iguales
                if (sonIguales == true)
                {
                    banderaV = 1;
                    if (dado[0] == 6)
                    {
                        cout << "Sexteto! la puntuación vuelve a cero" << endl;
                        bandera6=1;
                        puntuacion=0;
                        break;
                    }
                    else
                    {
                        cout << "Sexteto de " << dado[0] << " La puntuación multiplica el valor del dado * 50" << endl;
                        puntuacion += dado[0] * 50;
                    }
                }

                // Manejo de la situación cuando no todos los dados son iguales
                Max1 = 0;
                Max2 = 0;
                if (sonIguales == false)
                {
                    // Comprobación de tríos
                    for (int N = 0; N < 6; N++)
                    {
                        contadorTrio = 0;
                        for (int D = 0; D < 6; D++)
                        {
                            if (dado[D] == dado[N])
                            {
                                contadorTrio++;
                            }
                            if (contadorTrio == 3)
                            {
                                banderaV = 1;
                                if (Max1 == 0)
                                {
                                    Max1 = dado[D];
                                    contadorTrio = 0;
                                }
                                else
                                {
                                    Max2 = dado[D];
                                    contadorTrio = 0;
                                }
                                if (Max2 > Max1)
                                {
                                    Max1 = Max2;
                                }
                            }
                        }
                    }

                    // Manejo de la situación cuando se obtiene un trío
                    if (Max1 != 0)
                    {
                        cout << "Salio un Trio X" << endl;
                        puntuacion += Max1 * 10;
                    }

                    // Manejo de la situación cuando no se obtiene un trío
                    if (banderaV == 0)
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            puntuacion += dado[i];
                        }
                    }
                }
                // Almacenamiento de la puntuación de la ronda en el arreglo comparaPuntuaciones
                comparaPuntuaciones[x] = puntuacion;

                // Pausa para mostrar la puntuación antes de la siguiente ronda
                system("pause");


                // Determinación de la puntuación máxima de la ronda
                for (int y = 0; y < 3; y++)
                {
                    if (comparaPuntuaciones[y] > Max)
                    {
                        Max = comparaPuntuaciones[y];
                    }

                }
                puntuacionJugador2 = Max;
            }

            // Mostrar la puntuación de la ronda
            cout << "Puntuacion de la ronda: " << puntuacionJugador2 << endl;
            system("pause");
            system("cls");

            // Actualización de la puntuación total y visualización
            puntuacionFinalJugador2 += Max;
            if(bandera6==1)
            {
                cout<<endl<<"Recorda que sacaste un sexteto de 6, tu puntuacion vuelve a 0 :c"<<endl;
                puntuacionFinalJugador2=0;
                bandera6 = 0;
            }
            bandera = !bandera;

        }
        rondas++;
        if (puntuacionFinalJugador1 > mp)
        {
            mp = puntuacionFinalJugador1;
            mj = jugador1;
        }
        if (puntuacionFinalJugador2 > mp)
        {
            mp = puntuacionFinalJugador2;
            mj = jugador2;
        }
    }
    if (puntuacionFinalJugador1 > puntuacionFinalJugador2)
    {
        cout<<"El ganador es el jugador: " <<jugador1 <<"Tuvo que hacer: " <<rondas <<" Rondas"<<endl;
        system("pause");
    }
    else
    {
        cout<<"El ganador es el jugador: " <<jugador2 <<"Tuvo que hacer: " <<rondas <<" Rondas"<<endl;
        system("pause");
    }


}
