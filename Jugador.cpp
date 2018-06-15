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
	this->almacen=new Almacen(2*(N+M));
	this->estado.creditos=2*N*M;
	this->estado.cantAgua = 0;
	this->estado.turnosRestantes=2*N*M;
	this->numero.filas = N+1;
	this->numero.culumnas = M+1;
	this->estado.AguaMAX = N*M;
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

void Jugador::venderCosecha(){
	ui opcionDestino, opcionCosecha;
	std::cout<<"QUE COSECHA DESEA VENDER :"<<endl;
	this->almacen->mostrarCosechas();
	std::cin>> opcionCosecha;

	std::cout<<"A DONDE DESEA VENDER SU COSECHA."<<
			"CADA DESTINO TIENE UN TIPO DE COSECHA Y COSTOS DIFERENTES : "<<endl;
	this->almacen->mostrarDestinos();
	cin>> opcionDestino;
	if (this->almacen->coincideCosechaDestino(opcionCosecha,opcionDestino)){
		ui ganacia;
		ui cobro = this->almacen->destinoElegido(opcionDestino);
		this->estado.creditos -= cobro;
	}
	else{
		std::cout<<"*** NO PUEDE VENDER LA COSECHA A ESE DESTINO **"<<endl;
	}
}


/* Comprar Terreno */
void Jugador::comprarTerreno(){
	ui costo = ((this->numero.filas) * (this->numero.culumnas))/2;
	if (this->estado.creditos > costo){
		this->agregarTerreno(this->numero.filas,this->numero.culumnas);
		this->estado.creditos -= costo;
		std::cout<<"** COMPRO EL TERRENO CON EXITO **"<<endl;
	}
	else{
		std::cout<<"** NO CUENTA CON SUFICIENTE CREDITO PARA COMPRAR UN TERRENO **"<<endl;
	}
	cout<<endl;
}

void Jugador::venderTerreno(){
	ui posicion = 0;
	ui costo = (((this->numero.filas) * (this->numero.culumnas))/2) - this->numero.culumnas;
	if(this->cantTerrenos > 1){
		while (posicion < 1 || posicion > this->cantTerrenos){
			std::cout<<"Tiene "<<this->cantTerrenos<<" terrenos. Cual desea vender."<<endl;
			std::cin>> posicion;
			this->terrenos->remover(posicion);
			this->estado.creditos -= costo;
		}
	}
	else{
		std::cout<<"** NO PUEDE VENDER UN TERRENO SI SOLO TIENE 1 **"<<endl;
	}
	apuntarTerreno();
	cout<<endl;
}

void Jugador::mostrarMenuCompras(){
	std::cout<<"1- COMPRAR TERRENO "<<std::endl;
	std::cout<<"2- VENDER TERRENO"<<std::endl;
	std::cout<<"3  VENDER COSECHA"<<std::endl;
	std::cout<<"4- COMPRAR ESPACIO DE ALMACEN "<<std::endl;
	std::cout<<"6- VOLVER AL MENU ANTERIOR "<<std::endl;
}

void Jugador::comprar(){
	mostrarMenuCompras();
	ui opcion=opcionValida(1,6);

	switch(opcion){
	case 1:{comprarTerreno();
			break;}
	case 2:{venderTerreno();
			break;}
	case 3:venderCosecha();
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

void Jugador::obtenerTerrenoEnJuego(ui posicionTerreno){
	this->terrenoEnJuego=this->terrenos->obtener(posicionTerreno);
}
ui Jugador::terrenoValido(){
	ui posTerreno = 0;
	while((posTerreno > this->cantTerrenos) || (posTerreno < 1)){
		std::cout<<"Tiene "<<this->cantTerrenos<<" terrenos. "<<std::endl;
		std::cout<<"A que terreno desea cambiar: "<<std::endl;
		std::cin>> posTerreno;
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
		std::cout<<"* LE QUEDAN "<<this->estado.cantAgua<<" UNIDADES DE RIEGO *"<<endl;
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
		this->almacen->agregarCosecha(this->terrenoEnJuego[fil][col].mostrarTipo());
		this->terrenoEnJuego[fil][col].cambiarACosechado();
		std::cout<<"** COSECHO CORRECTAMENTE Y SU COSECHA FUE GUARDADA EN EL ALMACEN **"<<endl;
	}
	else{
		std::cout <<"***** NO SE PUEDE COSECHAR *****"<<std::endl;
	}
}

Terreno**Jugador::obtenerTerreno(){
	return this->terrenoEnJuego;
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

ui Jugador::numeroDeTerrenos(){
	return this->cantTerrenos;
}

void Jugador::agregarAgua(ui agua){
	if (agua > this->estado.AguaMAX){
		agua = this->estado.AguaMAX;
	}
	this->estado.cantAgua = agua;
}

void Jugador::procesoDeAlmacen(Lista<Semilla*>* semillas){
	this->almacen->procesarSemillas(semillas);
}

void Jugador::mostrarAlmacen(){
	this->almacen->mostrarCosechas();
}

Jugador::~Jugador() {
	//delete this->almacen;
	//delete this->mercado;
	// TODO Auto-generated destructor stub
}



