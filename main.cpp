//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<string>
#include <fstream>
#include "Juego.h"
typedef unsigned short int ui;
#include <stdlib.h>

void leer(string rutaEntrada){
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	while (! entrada.eof()) {
		char tipo;
		int costo;
		int tiempoCosecha;
		int rentabilidad;
		int tiempoRecup;
		int aguaTurno;

		entrada >> tipo;
		if (! entrada.eof()) {
			entrada >> costo;
			entrada >> tiempoCosecha;
			entrada >> rentabilidad;
			entrada >> tiempoRecup;
			entrada >> aguaTurno;

			cout << tipo << " | " << costo << " | " << tiempoCosecha <<"|"<< rentabilidad<<"|"<<tiempoRecup<<"|"<<aguaTurno << endl;
		}
	}

		/* cierra el archivo, liberando el recurso */
	entrada.close();
}
int main() {
	//leer("Datos/cultivos.txt");


	Juego granjeros;
	granjeros.elegirDificultad();
	granjeros.agregarJugadores(1);
	while(!granjeros.finJuego()){
		granjeros.comenzarTurno();
	}


	return 0;
}
