/*
 * Semilla.h
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#ifndef SRC_SEMILLA_H_
#define SRC_SEMILLA_H_
typedef unsigned short int ui;
#include<string>
#include<cstdlib>
#include <iostream>
#include "Lista.h"
using namespace std;
class Semilla{
	private:
		ui costo;
		ui tiempoCosecha;
		ui rentabilidad;
		ui tiempoRecup;
		ui aguaTurno;
		char tipo;
	public:
		Semilla();
		void iniciar(char tipo,ui costo,ui tiempoCosecha,ui rentabilidad,ui tiempoRecup,ui aguaTurno);
		char obtenerTipo();
		ui precio();
		ui cantidadAguaTurno();
		ui turnosRecuperacion();
		ui ganancia();
		ui turnosCosecha();
		bool haySemilla();
		virtual ~Semilla();
};

#endif /* SRC_SEMILLA_H_ */
