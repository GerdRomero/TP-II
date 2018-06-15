/*
 * Almacen.cpp
 *
 *  Created on: 13/06/2018
 *      Author: gerard
 */
#include "Almacen.h"
#include<fstream>

Almacen::Almacen(ui tamanio){
	this->espacioDiscponible = 0;
	this->estaVacio = true;
	this->cosechas = new Lista<Cosecha*>;
	cargarDestinos();
}

void Almacen::cargarDestinos(){
	std::string rutaEntrada = "Datos/destinos.txt";
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());
	while (! entrada.eof()) {
		Destino* destino = new Destino();

		std::string nombre;
		float distancia;
		ui precio;
		char tipo;

		entrada>>nombre;
		if (! entrada.eof()) {
			entrada>> distancia;
			entrada>> precio;
			entrada>> tipo;

			destino->cargar(nombre,distancia,precio,tipo);
		}
	}
}

void Almacen::mostrarDestinos(){
	ui i = 1;
	std::cout<<"******************************************************************"<<std::endl;
	std::cout<<"*************** LOS DESTINOS A DONDE PUEDE ENVIAR SON ************"<<std::endl;
	std::cout<<"******************************************************************"<<std::endl;
	this->Destinos->iniciarCursor();
	while (this->Destinos->avanzarCursor()){
		Destino* destino =  this->Destinos->obtenerCursor();
		std::cout<<i<<destino->obtenerDestino()<<"|"<<destino->obtenerDestino()<<"|"<<
				destino->obtenerPrecio()<<"|"<<destino->obtenerTipo()<<"|"<<std::endl;
		i++;
	}
}

ui Almacen::destinoElegido(ui opcion){
	Destino* destino= this->Destinos->obtener(opcion);
	ui cobro = destino->obtenerPrecio();
	return cobro;
}
/* ******** ACA ESTA LA DUDA TIENE O NO QE HABER UNA GANANCIA POR ENVIAR ************/
ui Almacen::transaccion(ui pos){
	Cosecha* cosecha = this->cosechas->obtener(pos);
	ui ganancia = cosecha->
}

void Almacen::procesarSemillas(Lista<Semilla*>* semillas){
	semillas->iniciarCursor();
	while(semillas->avanzarCursor()){
		Semilla* semilla = semillas->obtenerCursor();
		Cosecha* cosecha = new Cosecha;
		cosecha->tipo = semilla->obtenerTipo();
		cosecha->cantidad = 0;
		cosecha->costo = semilla->precio();
		cosecha->rentabilidad = semilla->ganancia();
		this->cosechas->agregar(cosecha);
	}
}

ui Almacen::mostrarTamanio(){
	return this->espacioDiscponible;
}

void Almacen::extenderCapacidad(ui tamanio){
	this->espacioDiscponible = tamanio;
}

void Almacen::agregarCosecha(char tipo){
	this->estaVacio = false;
	this->cosechas->iniciarCursor();
	while(this->cosechas->avanzarCursor()){
		Cosecha* cosecha = this->cosechas->obtenerCursor();
		agregarATipo(cosecha,tipo);
	}
}

void Almacen::agregarATipo(Cosecha* cosecha, char tipo){
	if (cosecha->tipo == tipo){
		cosecha->cantidad += 1;
	}
}

void Almacen::mostrarCosechas(){
	std::cout<<"********* SUS COSECHAS GUARDADAS SON ********"<<std::endl;
	std::cout<<"|TIPO DE COSECHA | CANTIDAD"<<endl;
	this->cosechas->iniciarCursor();
	while (this->cosechas->avanzarCursor()){
		Cosecha* cosecha = this->cosechas->obtenerCursor();
		std::cout<<"|       "<<cosecha->tipo<<"        |   "<<cosecha->cantidad<<std::endl;
	}
}

bool Almacen::coincideCosechaDestino(ui posCosecha,ui posDestino){
	Cosecha* cosecha = this->cosechas->obtener(posCosecha);
	Destino* destino = this->Destinos->obtener(posDestino);
	return (cosecha->tipo == destino->obtenerTipo());
}

Almacen::~Almacen(){
	delete this->cosechas;
}




