/*
 * Destinos.cpp
 *
 *  Created on: 13/06/2018
 *      Author: gerard
 */

#include "Destinos.h"

Destino::Destino(){
	this->distancia = 0;
	this->precio = 0;
	this->tipo = ' ';
	this->nombreDeDestino = "";
}

void Destino::cargar(std::string nombre,float distancia,ui precio,char tipo){
	this->distancia = distancia;
	this->precio = precio;
	this->tipo = tipo;
	this->nombreDeDestino = nombre;
}

std::string Destino::obtenerDestino(){
	return this->nombreDeDestino;
}

ui Destino::obtenerPrecio(){
	return this->precio;
}

char Destino::obtenerTipo(){
	return this->tipo;
}

float Destino::obtenerDistancia(){
	return this->distancia;
}


