
#include "Semilla.h"

Semilla::Semilla() {
	this->tipo = ' ';
	this->costo = NULL;
	this->tiempoCosecha=NULL;
	this->rentabilidad=NULL;
	this->tiempoRecup=NULL;
	this->aguaTurno=NULL;
}

void Semilla::iniciar(char tipo,ui costo,ui tiempoCosecha,ui rentabilidad,ui tiempoRecup,ui aguaTurno){
	this->tipo = tipo;
	this->costo = costo;
	this->tiempoCosecha = tiempoCosecha;
	this->rentabilidad = rentabilidad;
	this->tiempoRecup  = tiempoRecup;
	this->aguaTurno = aguaTurno;
}

char Semilla::obtenerTipo(){
		return this->tipo;
	}

ui Semilla::precio(){
	return this->costo;
}

ui Semilla::cantidadAguaTurno(){
	return this->aguaTurno;
}

ui Semilla::turnosRecuperacion(){
	return this->tiempoRecup;
}
ui Semilla::ganancia(){
	return this->rentabilidad;
}
ui Semilla::turnosCosecha(){
	return this->tiempoCosecha;
}

Semilla::~Semilla() {
	// TODO Auto-generated destructor stub
}
