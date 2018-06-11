
#include "Terreno.h"
Terreno::Terreno() {
	this->Sembrada=false;
	this->parcelaPodrida=false;
	this->seCosecho=false;
	this->Parcela.tipo = '#';
	this->Parcela.numeroDeRiegos = 0;
	this->Parcela.recuperacion = 0;
	this->Parcela.rentabilidad = 0;
	this->Parcela.tiempoHastaCosecha = 0;
	this->Parcela.tiempoTrasSiembra = 0;
	this->ESTADO = vacia;
}

char Terreno::mostrarTipo(){
	return this->Parcela.tipo;
}

bool Terreno::estaVacia(){
	return ((!this->Sembrada) && (!this->parcelaPodrida));
}

bool Terreno::regoCorrectamente(){
	return (this->Parcela.numeroDeRiegos == this->Parcela.tiempoHastaCosecha);
}

void Terreno::cambiarACosechado(){
	this->Parcela.rentabilidad  = 0;
	this->Parcela.tiempoHastaCosecha = 0;
	this->ESTADO = reposo;
	this->Parcela.numeroDeRiegos = 0;
	this->seCosecho = true;
	this->Parcela.tipo = '#';
}

void Terreno::recuperarParcela(){
	if ((this->seCosecho && (this->Parcela.recuperacion == 0)) ||
			(this->parcelaPodrida && (this->Parcela.recuperacion == 0))){
		this->Sembrada = false;
	}
}

void Terreno::decrementarRecuperacion(){
	if (((this->Parcela.recuperacion > 0) && this->seCosecho) || (this->parcelaPodrida  && this->Parcela.recuperacion > 0)){
		this->Parcela.recuperacion --;
	}
}

void Terreno::incrementarTiempoTrasSiembra(){
	this->Parcela.tiempoTrasSiembra++;
}

void Terreno::podrirParcela(){
	if((this->Sembrada)&& (!this->seCosecho) && ((this->Parcela.numeroDeRiegos) < (this->Parcela.tiempoTrasSiembra))){
		this->ESTADO = reposo;
		this->Parcela.tipo = 'P';
		this->Parcela.rentabilidad  = 0;
		this->Parcela.tiempoHastaCosecha = 0;
		this->Parcela.numeroDeRiegos = 0;
		this->parcelaPodrida = true;
	}
}

/********* quitar ccomentARIOS*/

void Terreno::actualizando(){
	this->incrementarTiempoTrasSiembra();
	this->podrirParcela();
	this->decrementarRecuperacion();
	this->recuperarParcela();
}

ui Terreno::obtenerRentabilidad(){
	return this->Parcela.rentabilidad;
}

void Terreno::aumentarNumeroDeRiegos(){
	this->Parcela.numeroDeRiegos++;
}

void Terreno::cambiarEstadoDeParcelaSembrada(Semilla * aSembrar){
	this->Parcela.rentabilidad = aSembrar->ganancia();
	this->Parcela.recuperacion = aSembrar->turnosRecuperacion();
	this->Parcela.tiempoHastaCosecha = aSembrar->turnosCosecha();
	this->Sembrada = true;
	this->ESTADO = sembrada;
	this->Parcela.numeroDeRiegos = 0;
	this->Parcela.tipo=aSembrar->obtenerTipo();
}

