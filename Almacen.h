/*
 * Almacen.h
 *
 *  Created on: 13/06/2018
 *      Author: gerard
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_
#include "Lista.h"
#include "Destinos.h"
#include "Semilla.h"

struct Cosecha{
	char tipo;
	ui costo;
	ui rentabilidad;
	ui cantidad;
};

class Almacen{
		private:
				ui espacioDiscponible;
				bool estaVacio;
				Lista<Destino*>* Destinos;
				ui posicion;
				Lista<Cosecha*>* cosechas;

		public:
				/*post: Se crea el almacen vacio con un espacio Fijo
				 *      Y carga la Lista de Destinos.*/
				Almacen(ui tamanio);
				/*post: Incrementa el espacioDisponible del Almacen.*/
				void extenderCapacidad(ui tamanio);
				/*post: Elige el destino donde desea enviar la cosecha.*/

				void mostrarDestinos();

				void mostrarCosechas();

				ui destinoElegido(ui opcion);

				ui mostrarTamanio();

				ui transaccion(ui pos);

				void procesarSemillas(Lista<Semilla*>* semillas);

				bool coincideCosechaDestino(ui posCosecha,ui posDestino);

				void agregarCosecha(char tipo);
				~Almacen();

		private:
				void cargarDestinos();
				void calcularTransaccion();
				void agregarATipo(Cosecha *cosecha, char Tipo);


};

#endif /* ALMACEN_H_ */
