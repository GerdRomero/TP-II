/*
 * Destinos.h
 *
 *  Created on: 13/06/2018
 *      Author: gerard
 */

#ifndef DESTINOS_H_
#define DESTINOS_H_
typedef unsigned short int ui;
#include <string>
class Destino{
		private:
				std::string nombreDeDestino;
				float distancia;
				ui precio;
				char tipo;

		public:
				Destino();
				/*post: Carga las variables.*/
				void cargar(std::string nombre,float distancia,ui precio,char tipo);

				std::string obtenerDestino();

				float obtenerDistancia();

				ui obtenerPrecio();

				char obtenerTipo();
};



#endif /* DESTINOS_H_ */
