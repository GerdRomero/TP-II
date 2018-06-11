/*
 * Jugador.cpp
 *
 *  Created on: 08/06/2018
 *      Author: gerard
 */

#include "Jugador.h"
//#include "ArchivosL.h"
#include "Terreno.h"
#include <fstream>
#include<iostream>
#include <string>


Jugador::Jugador(ui dificultad){
	this->terrenos=new Lista<Terreno**>;
	this->posicionTerrenoEnJuego=0;
	this->finTurno=false;
	this->numero.filas = 0;
	this->numero.culumnas = 0;
	this->pos[0] = 0;
	this->pos[1] = 0;
	this->cantTerrenos=0;
	this->terrenoEnJuego = NULL;
	this->aSembrar=NULL;
	//this->mercado=NULL;
	this->dificultad=dificultad;
	cargarDificJugador(dificultad);
	//his->mercado=new Mercado(cultivos);

}

/*********************************/
void Jugador::apuntarTerreno(){
	this->terrenoEnJuego = this->terrenos->obtener(1);
}

void Jugador::cargarDificJugador(ui dificultad){
	ui N,M;
	if(dificultad==1){
		N=5, M=5;
	}else if(dificultad==2){
		N=6, M=7;
	}else if(dificultad==3){
		N=7, M=9;
	}
	agregarTerreno(N+1,M+1);
	//Almacen *almacen=new Almacen(2*(N+M));
	//this->almacen=new Almacen(2*(N+M));
	this->estado.creditos=2*N*M;
	this->estado.cantAgua=N*M;
	this->estado.turnosRestantes=2*N*M;
	this->numero.filas = N+1;
	this->numero.culumnas = M+1;
	apuntarTerreno();

}


ui Jugador::opcionValida(ui min, ui max){
	ui opcion;
	std::cout<<"Ingrese una opcion: "<<std::endl;
	std::cin>>opcion;
	if(opcion>max|| opcion<min){
		opcionValida(min, max);
	}
	return opcion;
}
/*
void Jugador::venderTerreno(){
	ui terrenoAVender=terrenoValido();
	Terreno **terrenoACotizar=this->terrenos->obtener(terrenoAVender);
	if(terrenoAVender!=this->posicionTerrenoEnJuego){
	//ui ganancia=this->mercado->cotizarTerreno(terrenoACotizar);
	this->terrenos->remover(terrenoAVender);
	this->estado.creditos+=ganancia;
	std::cout<<"Se vendio el terreno correctamente. "<<std::endl;
	}
	else{
		std::cout<<"Debe cambiar el terreno que está"
				" utilizando para venderlo"<<std::endl;
	}
}*/



/*
void Jugador::verificarDimensionTerreno(){
	ui fil, col;
	std::cout<<"Ingrese la fila :"<<std::endl;
	std::cin>>fil;
	this->pos[0]=fil;
	std::cout<<"Ingrese la columna: "<<std::endl;
	std::cin>>col;
	this->pos[1]=col;
	if (fil>(2*this->dificultad)||col>(2*this->dificultad)){
		std::cout<<"Puede comprar un terreno de hasta "<<
				(2*this->dificultad)<<"*"<<(2*this->dificultad)<<std::endl;
		verificarDimensionTerreno();
	}
}*/

/*
void Jugador::comprarTerreno(){
	falta tomar el caso de pedir dimension por dificultad
	verificarDimensionTerreno();
	ui fil=filaTerreno();
	ui col=columnaTerreno();
	//std::cout<<fil<<" * "<<col<<"dimensiones "<<std::endl;
	//ui costo=this->mercado->venderTerreno(fil, col);
	if(hayCreditos(costo)){
		agregarTerreno(fil,col);
		this->estado.creditos-=costo;
		std::cout<<"Se compro un terreno exitosamente. "<<std::endl;
	}else{
		std::cout<<"No hay creditos suficientes"<<std::endl;
	}
}*/

/*
void Jugador::comprarCapacAlmacen(){
	//porsu faltan metodos de comprobacion
	ui capac;
	std::cout<<"Ingrese la capacidad a agregar: "<<std::endl;
	cin>>capac;
	//Multiplicar costo por dificultad
	//ui costo=this->mercado->venderTamanioAlmacen(capac);
	if(hayCreditos(costo)){
		//this->almacen->extender(capac);
		this->estado.creditos-=costo;
		std::cout<<"Se extendio el almacen en "<<capac<<std::endl;
	}else{
		std::cout<<"No hay creditos suficientes "<<std::endl;
	}
}*/

/*Metodo a practicar uso en todas las compras*/

bool Jugador::hayCreditos(ui costoCompra){
	ui comparacion=this->estado.creditos;
	return (comparacion-costoCompra)>=0;
}
/*
void Jugador::venderCosecha(){
	ui costo, cantAEnviar;
	//this->almacen->leerDestino();
	cantAEnviar=this->almacen->elegirCosecha();
	costo=this->almacen->prepararCosecha(cantAEnviar);
	if(hayCreditos(costo)&&cantAEnviar>0){
		char cosecha=this->almacen->obtenerTipoCosechaPreparada();
		ui ganancia=this->mercado->venderCosecha(cosecha,cantAEnviar);
		this->estado.creditos+=ganancia;
		std::cout<<"Se envio correctamente la cosecha. "<<std::endl;
		std::cout<<"Obtuvo "<<ganancia<< " de ganancia. "<<std::endl;
		//this->almacen->vaciarCosecha();
	}
	else{
		std::cout<<"No hay creditos suficientes o no tiene cosecha de ese tipo."<<std::endl;
	}
} */
void Jugador::mostrarMenuCompras(){
	std::cout<<"1- Comprar semillas "<<std::endl;
	std::cout<<"2- Vender Cosecha "<<std::endl;
	std::cout<<"3- Comprar Terreno "<<std::endl;
	std::cout<<"4 -Vender Terreno "<<std::endl;
	std::cout<<"5- Comprar espacio en Almacen "<<std::endl;
	std::cout<<"6- Volver al Menu anterior "<<std::endl;


}
void Jugador::comprar(){
	mostrarMenuCompras();
	ui opcion=opcionValida(1,6);
	switch(opcion){
	case 1:
		//comprarSemillas();
		break;
	case 2:
		//venderCosecha();
		break;
	case 3:
		//comprarTerreno();
		break;
	case 4:
		//venderTerreno();
		break;
	case 5:
		//comprarCapacAlmacen();
		break;
	case 6:
		/*agregar retorno*/

		break;
	}
}

bool Jugador::noFinalizado(){
	return this->finTurno;
}

/***************** AGREGO TERRENO *******************/
void Jugador::agregarTerreno(ui fil, ui col){

	Terreno ** terreno = new Terreno*[fil];
	for( ui i = 1 ; i< col; i++ ){ //// VERIFICAR++++++++++++++++++++++++eergfrgege
	  terreno[i] = new Terreno[col];
	}
	//terreno[0][0].agregarDimension(fil,col);
	this->terrenos->agregar(terreno);

	//std::cout<<"terrenos agregados "<<this->terrenos->contarElementos()<<std::endl;
	this->cantTerrenos+=1;

}

void Jugador::agregarTerreno(){
	ui fila = this->numero.filas;
	ui columna = this->numero.culumnas;
	Terreno ** terreno = new Terreno*[fila];
	for( ui i=0; i < columna; i++ )
	  terreno[i] = new Terreno[columna];
	this->terrenos->agregar(terreno);
	this->cantTerrenos+=1;
}

void Jugador::obtenerTerrenoEnJuego(ui posicionTerreno){
	this->terrenoEnJuego=this->terrenos->obtener(posicionTerreno);
}
ui Jugador::terrenoValido(){
	ui posTerreno;
	std::cout<<this->cantTerrenos<<std::endl;
	std::cout<<"Ingrese un numero de terreno: "<<std::endl;
	std::cout<<"Tiene "<<this->cantTerrenos<<" terrenos. "<<std::endl;
	std::cin>>posTerreno;
	if(posTerreno>this->cantTerrenos|| posTerreno<=0){
		std::cout<<"Tiene "<<this->cantTerrenos<<" terrenos. "<<std::endl;
		std::cout<<"Ingrese un numero de terreno valido: "<<std::endl;
		terrenoValido();
	}
	return posTerreno;
}

void Jugador::sembrarTerreno(Semilla * elegida){
	this->aSembrar = elegida;

	ui fil = 0,col = 0;
	while (((fil < 1) || (fil > this->numero.filas)) &&
			  ((col < 1) || (this->numero.culumnas < col))){
				std::cout<<"Numero de Fila: ";
				std::cin>> fil;
				std::cout<<"Numero de Columna: ";
				std::cin>> col;
	}

	if (this->terrenoEnJuego[fil][col].estaVacia()){
		this->terrenoEnJuego[fil][col].cambiarEstadoDeParcelaSembrada(this->aSembrar);
		restarCredito(this->aSembrar->precio());
		std::cout<<"******** SEMBRO CORRECTAMENTE *********"<<std::endl;
	}
	else{
		std::cout <<"***** LA PARCELA SE ENCUENTRA SEMBRADA O REPOSO *****"<<std::endl;
	}
}

void Jugador::regarTerreno(){
	ui fil = 0,col = 0;
	while (((fil < 1) || (fil > this->numero.filas)) &&
			  ((col < 1) || (this->numero.culumnas < col))){
				std::cout<<"Numero de Fila: ";
				std::cin>> fil;
				std::cout<<"Numero de Columna: ";
				std::cin>> col;
	}
	if (!this->terrenoEnJuego[fil][col].estaVacia()){
		this->estado.cantAgua-=this->aSembrar->cantidadAguaTurno();
		this->terrenoEnJuego[fil][col].aumentarNumeroDeRiegos();
		std::cout<<"***** REGO CORRECTAMENTE *****"<<endl;
	}
	else{
		std::cout <<"***** INTENTA REGAR DONDE NO HAY NADA SEMBRADO*****"<<std::endl;
	}
}
void Jugador::cosecharTerreno(){
	ui fil = 0,col = 0;
	while (((fil < 1) || (fil > this->numero.filas)) &&
			  ((col < 1) || (this->numero.culumnas < col))){
				std::cout<<"Numero de Fila: ";
				std::cin>> fil;
				std::cout<<"Numero de Columna: ";
				std::cin>> col;
	}
	if(!(this->terrenoEnJuego[fil][col].estaVacia()) &&
		(this->terrenoEnJuego[fil][col].regoCorrectamente())){

		this->estado.creditos += this->terrenoEnJuego[fil][col].obtenerRentabilidad();
		this->terrenoEnJuego[fil][col].cambiarACosechado();
		std::cout<<"***** COSECHO CORRECTAMENTE *****"<<endl;
	}
	else{
		std::cout <<"***** NO SE PUEDE COSECHAR *****"<<std::endl;
	}
}

Terreno**Jugador::obtenerTerreno(){
	return this->terrenoEnJuego;

}

void Jugador::mostrarInfoSemilla(){
	/*Vale por info con punteros*/
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
}


void Jugador::finalizarTurno(){
	this->finTurno=true;
}

void Jugador::renovarTurno(){
	this->finTurno = false;
}

/******************** MUESTRA EL TERRENO ******************************/
void Jugador::mostrarTerreno(){
	ui fila = this->numero.filas;
	ui columna = this->numero.culumnas;

	cout<<"\tBienvenido a granjeros. "<<endl;
	for(ui i = 1;i < fila;i++){
		cout<<"     "<<i;
		for(ui j = 1;j < columna;j++){
			cout<<"| "<<this->terrenoEnJuego[i][j].mostrarTipo()<<"| ";
		}

		cout<<endl;
	}
	cout<<endl;
}
/* ESTOY AGREGANDO */

/************** hasta aca********************************/
void Jugador::actualizar(){
	ui fila = this->numero.filas;
	ui columna = this->numero.culumnas;
	for (ui i= 1; i< fila;i++){
		for (ui j=1; j< columna;j++){
			this->terrenoEnJuego[i][j].actualizando();
		}
	}
}

void Jugador::terrenosSembrados(){
	this->terrenos->iniciarCursor();
	while(this->terrenos->avanzarCursor()){
		this->terrenoEnJuego = this->terrenos->obtenerCursor();
		actualizar();
	}
}

void Jugador::restarCredito(int cant){
	this->estado.creditos -= cant;
}

ui Jugador::totalDeCredito(){
	return this->estado.creditos;
}

ui Jugador::totalDeAgua(){
	return this->estado.cantAgua;
}

Jugador::~Jugador() {
	//delete this->almacen;
	//delete this->mercado;
	// TODO Auto-generated destructor stub
}



