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

int unJugador(int& mp, string& mj)
{
	string jugador1;
	int contadorTiradas = 0, puntuacion = 0, rondas = 1, contador;
	int contadorEscalera = 0, banderaV = 0;
	int contadorTrio = 0, TX=0, MAX1=0, MAX2=0;

	cout << "Ingrese nombre de jugador: ";
	cin >> jugador1;
	system("cls");
	while (puntuacion <= 500)
	{
		// Reinicia los contadores en cada iteración
		contadorEscalera = 0;
		banderaV=0;
		MAX1=0, MAX2=0;


		srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios.
		// CARGA DEL DADO
		for (int i = 0; i <= 5; i++)
		{
			dado[i] = 1 + rand() % 6;


			if (dado[i] == i + 1)
			{
				contadorEscalera++;
			}
		}

		// MUESTRA DEL DADO Y NUMERO DE RONDA
		cout << "Ronda: " << rondas<<" Jugador: "<<jugador1 << endl;
		contadorTiradas++;
		mostrarDados();


		// VALIDACIONES  **** VALIDACIONES ***** VALIDACIONES ***** VALIDACIONES

		//CODIGO ESCALERA

		if (contadorEscalera == 6)
		{

			rlutil::locate(80,3);
			rlutil::setColor(rlutil::RED);
			cout<<"-----------------------------------------";
			rlutil::locate(95,5);
			cout << "Victoria por escalera" << endl;
			rlutil::locate(80,7);
			cout<<"-----------------------------------------";
			cout<<endl;
			rlutil::setColor(rlutil::WHITE);
			system("pause");
			break;
		}

		// CODIGO DE SEXTETO X Y 6
		bool sonIguales = true;
		for (int i = 1; i < 6; i++)
		{
			if (dado[i] != dado[0])
			{
				sonIguales = false;
			}
		}

		if (sonIguales==true)
		{
			banderaV=1;
			if(dado[0]==6)
			{
				rlutil::locate(80,3);
				rlutil::setColor(rlutil::RED);
				cout<<"-----------------------------------------";
				rlutil::locate(95,5);
				cout <<endl<<"Sexteto de Seis! :c puntuacion volvera a 0 "<<endl;
				rlutil::locate(80,7);
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);

				;
				puntuacion=0;
			}
			else
			{
				cout<<endl<<"Puntuacion actual "<<puntuacion<<endl;
				cout << "Sexteto de "<<dado[0]<<" Por lo que "<<dado[0]<<" se multiplicara X 50"<<endl;
				puntuacion+=dado[0]*50;
			}
		}
		// FIN CICLO SEXTETO

		// CODIGO TRIO X ***** CODIGO TRIO X
		if(sonIguales==false)
		{
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
						banderaV=1;
						if (MAX1==0)
						{
							MAX1=dado[D];
							contadorTrio = 0;
						}
						else
						{
							MAX2=dado[D];
							contadorTrio = 0;
						}
						if(MAX2>MAX1)
						{
							MAX1=MAX2;
						}
					}

				}
			}
			if(MAX1!=0)
			{
				puntuacion += MAX1*10;
				rlutil::locate(80,3);
				rlutil::setColor(rlutil::RED);
				cout<<"-----------------------------------------";
				rlutil::locate(95,5);
				cout<<"Salio un -TRIOX++- GENIAL"<<endl;
				rlutil::locate(80,7);
				cout<<"-----------------------------------------";
				cout<<endl;
				rlutil::setColor(rlutil::WHITE);


			}
		}
		// FIN CODIGO TRIO X  **** FIN CODIGO TRIO X *****

		//SI NINGUNA VALIDACION SE CUMPLIO SUMA LOS DADOS
		if(banderaV==0)
		{
			for (int i = 0; i <= 5; i++)
			{
				puntuacion+=dado[i];
			}
		}
		// FIN VALIDACIONES  **** FIN VALIDACIONES ***** FIN VALIDACIONES ***** FIN VALIDACIONES


		// Verifica la puntuación y continúa o regresa al menú
		if (puntuacion < 500)
		{
			cout <<endl<< "Puntuacion actual: " << puntuacion << " (Necesitas 500 para ganar)" << endl;
			system("pause");
		}

		//MOSTRADOR DE CAMBIO DE RONDA
		if (contadorTiradas % 3 == 0)
		{
			rondas++;
			system("cls");
			rlutil::setColor(rlutil::YELLOW);
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
	} //CIERRE DEL WHILE


	//CARGA EL MAYOR PUNTAJE A SCORE SI ESTE ES MAYOR A MP
	if(puntuacion>mp)
	{
		mp = puntuacion;
		mj = jugador1;
	}

	return 0; // Puedes devolver un valor si es necesario
}

// ********* FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********
// ********* FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********
// ********* FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********  FIN FUNCION UN JUGADAOR ***********

int mayorPuntaje(int& mp, string& mj)
{
	if(mp==0)
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
// ********* FIN FUNCION MAYOR PUNTAJE ***********  FIN FUNCION MAYOR PUNTAJE ***********  FIN FUNCION MAYOR PUNTAJE ***********
// ********* FIN FUNCION MAYOR PUNTAJE ***********  FIN FUNCION MAYOR PUNTAJE ***********  FIN FUNCION MAYOR PUNTAJE ***********


int dosJugadores()
{
	string jugador1, jugador2;
	int puntuacionJugador1 = 0, puntuacionJugador2 = 0, contadorTiradas = 0, rondas = 0, banderaV = 0;
	bool bandera = true;


	cout<<"Ingrese nombre del jugador 1: ";
	cin>>jugador1;
	cout<<"Ingrese nombre del jugador 2: ";
	cin>>jugador2;

	while (puntuacionJugador1 <= 500 || puntuacionJugador2 <= 500)
	{

		int contadorEscalera = 0, sexteto = 0, contador = 0;
		int contadorTrio = 0, TX=0, MAX1=0, MAX2=0, banderaV = 0;


		// Reinicia los contadores en cada iteración
		contadorEscalera = 0;
		sexteto = 0;
		MAX1=0, MAX2=0;

		if (contadorTiradas % 6 == 0)
		{
			if (rondas != 0)
			{
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

			}
			cout << "Ronda: " << rondas << endl;
			mostrarDados();

			//sextetos

			bool sonIguales = true;
			for (int i = 1; i < 6; i++)
			{
				if (dado[i] != dado[0])
				{
					sonIguales = false;
				}
			}

			if (sonIguales==true)
			{
				banderaV=1;
				if(dado[0]==6)
				{
					cout <<endl<<"Sexteto de Seis! :c Tu Score volvera a 0 "<<endl;
					puntuacionJugador1=0;
				}
				else
				{
					cout<<endl<<"Puntuacion actual "<<puntuacionJugador1<<endl;
					cout << "Sexteto de "<<dado[0]<<" Por lo que "<<dado[0]<<" se multiplicara X 50"<<endl;
					puntuacionJugador1+=dado[0]*50;
				}
			}
			// CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X
			if(sonIguales==false)
			{
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
							banderaV=1;
							if (MAX1==0)
							{
								MAX1=dado[D];
								contadorTrio = 0;
							}
							else
							{
								MAX2=dado[D];
								contadorTrio = 0;
							}
							if(MAX2>MAX1)
							{
								MAX1=MAX2;
							}
						}

					}
				}
				if(MAX1!=0)
				{
					puntuacionJugador1 += MAX1*10;
				}
			}

			// CODIGO TRIO X  CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X





			if (contadorEscalera == 6)
			{
				cout << "Victoria por escalera" << endl;
				puntuacionJugador1 = 501;
			}

			if(banderaV==0)
			{
				for (int i = 0; i <= 5; i++)
				{
					puntuacionJugador1+=dado[i];
				}
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
			}
                                                cout << "Ronda: " << rondas << endl;
			mostrarDados();

			bool sonIguales = true;
			for (int i = 1; i < 6; i++)
			{
				if (dado[i] != dado[0])
				{
					sonIguales = false;
				}
			}

			if (sonIguales==true)
			{
				banderaV=1;
				if(dado[0]==6)
				{
					cout <<endl<<"Sexteto de Seis! :c Tu Score volvera a 0 "<<endl;
					puntuacionJugador2=0;
				}
				else
				{
					cout<<endl<<"Puntuacion actual "<<puntuacionJugador2<<endl;
					cout << "Sexteto de "<<dado[0]<<" Por lo que "<<dado[0]<<" se multiplicara X 50"<<endl;
					puntuacionJugador2+=dado[0]*50;
				}
			}
			// CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X
			if(sonIguales==false)
			{
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
							banderaV=1;
							if (MAX1==0)
							{
								MAX1=dado[D];
								contadorTrio = 0;
							}
							else
							{
								MAX2=dado[D];
								contadorTrio = 0;
							}
							if(MAX2>MAX1)
							{
								MAX1=MAX2;
							}
						}

					}
				}
				if(MAX1!=0)
				{
					puntuacionJugador2 += MAX1*10;
				}
			}
			// CODIGO TRIO X  CODIGO TRIO X CODIGO TRIO X CODIGO TRIO X




			if (contadorEscalera == 6)
			{
				cout << "Victoria por escalera" << endl;
				puntuacionJugador2 = 501;
			}

			if(banderaV==0)
			{
				for (int i = 0; i <= 5; i++)
				{
					puntuacionJugador2+=dado[i];
				}
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
