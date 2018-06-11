
#include "Juego.h"
#include "Jugador.h"
#include<iostream>
#include<fstream>
#include "Semilla.h"


Juego::Juego() {
	this->jugadores=new Lista<Jugador*>;
	this->semillas = new Lista<Semilla*>;
	this->cantJugadores = 0;
	this->turnosJuego=0;
	this->juegoTerminado = false;
	this->jugadorActual=NULL;
	this->posJugadorEnJugadores=1;
	this->dificultad = 0;
	agregarSemillas();
}


void Juego::agregarJugadores(ui cantidad){
	for(ui i=1; i<=cantidad; i++){
		Jugador *jugador=new Jugador(this->dificultad);
		this->jugadores->agregar(jugador);
		this->cantJugadores ++;
	}
}

/***************************************************/
void Juego::asignar(){
	ui N,M;
	switch(this->dificultad){
	case 1: N = 3, M = 2;
		    break;
	case 2: N = 4, M = 3;
			break;
	case 3: N = 5, M = 4;
			break;
	}
	this->turnosJuego =2*N*M;
}

void Juego::elegirDificultad(){
	ui dificultad;
	std::cout<<"Ingrese una dificultad para los jugador/es(solo numeros): "<<std::endl;
	std::cout<<"1-Facil"<<std::endl;
	std::cout<<"2-Normal"<<std::endl;
	std::cout<<"3-Dificil"<<std::endl;
	std::cout<<"Ingrese una opcion: ";
	std::cin>>dificultad;
	if(dificultad>3||dificultad==0){
		elegirDificultad();
	}
	this->dificultad = dificultad;
	asignar();
}
/***************************************************/

Jugador* Juego::obtenerJugador(){
	return this->jugadorActual;
}

// cambie aca
void Juego::contarTurnos(){

	this->turnosJuego--;
}

// cambie aca
bool Juego::finJuego(){
		if(this->turnosJuego == 0){
			this->juegoTerminado = true;
		}
		return this->juegoTerminado;
	}

// comienza acaaaaa *****************************************************

void Juego::comenzarTurno(){

	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		this->jugadorActual=this->jugadores->obtenerCursor();
		Jugar();
	}
	contarTurnos();

}

void Juego::Jugar(){
	while(!(this->jugadorActual->noFinalizado())){
		mostrarOpciones();
	}
	this->jugadorActual->renovarTurno();
}

ui Juego::opcionValida(){
	ui opcion;
	std::cout <<"Opcion: ";
	std::cin>> opcion;
	if (opcion <= 0 || opcion > 7){
		opcionValida();
	}
	return opcion;

}

ui Juego::posicionDeJugador(){
	if (this->jugadores->contarElementos() < this->posJugadorEnJugadores){
		this->posJugadorEnJugadores = 1;
	}
	return this->posJugadorEnJugadores;
}

void  Juego::menu(){
	std::cout<<"HAY "<<this->cantJugadores<<" JUGADORES JUGANDO. "<<std::endl;
	std::cout<<"El jugador "<<posicionDeJugador()
			<<" esta jugando. "<<" Tiene "<<this->jugadorActual->totalDeCredito()<<" monedas."<<std::endl;
	std::cout<<"Tiene "<<this->jugadorActual->totalDeAgua()<<" unidades de riego."<<endl;

	std::cout<<"Tiene "<< this->turnosJuego<<" turnos."<<endl;
	std::cout<<"******* MENU *******"<<std::endl;
	std::cout<<"1)SEMBRAR."<<std::endl;
	std::cout<<"2)REGAR."<<std::endl;
	std::cout<<"3)COSECHAR."<<std::endl;
	std::cout<<"4)COMPRAR."<<std::endl;
	std::cout<<"5)CAMBIAR TERRENO EN JUEGO."<<std::endl;
	std::cout<<"6)MOSTRAR TERRENO EN JUEGO."<<std::endl;
	std::cout<<"7)PASAR TURNO."<<std::endl;
}

/********************************** AGREGE ***********************************/
void Juego::mostrarSemillas(){
	ui i = 1;
	std::cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
	std::cout<<"----------------------------------------------- TABLA DE SEMILLAS --------------------------------------------"<<endl;
	std::cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;

	this->semillas->iniciarCursor();
	while (this->semillas->avanzarCursor()){
		Semilla* semilla = this->semillas->obtenerCursor();
		std::cout<<i<<")|Semilla: "<<semilla->obtenerTipo()<<" |Costo:  "<<semilla->precio()<<" |Turnos hasta Cosecha: "<<
			     semilla->turnosCosecha()<<" |Rentabilidad: "<<semilla->ganancia()<<
				 " |Tiempo Recuperacion: "<<semilla->turnosRecuperacion()<<
				 " |Agua necesaria: "<<semilla->cantidadAguaTurno()<<" | "<<endl;
		i++;
	}
}

Semilla* Juego::elegirSemilla(){
	mostrarSemillas();
	char opcion[] ="0";
	int cant = this->semillas->contarElementos();
	int opc = atoi(opcion);
	while ((opc < 1) || (opc >cant)){
		std::cout<<"OPCION: ";
		cin>>opcion;
		opc = atoi(opcion);
	}
	Semilla* semilla;
	semilla = this->semillas->obtener(opc);
	return semilla;
}

void Juego::mostrarOpciones(){
	this->jugadorActual->mostrarTerreno();

	menu();
	int opcionMenu = opcionValida();

	switch(opcionMenu){
	case 1:{Semilla* aSembrar = elegirSemilla();
			this->jugadorActual->sembrarTerreno(aSembrar);
			break;}
	case 2:
		this->jugadorActual->regarTerreno();
		break;
	case 3:
		this->jugadorActual->cosecharTerreno();
		break;
	case 4:
		this->jugadorActual->comprar();
		break;
	case 5:
		this->jugadorActual->obtenerTerrenoEnJuego(this->jugadorActual->terrenoValido());
		break;
	case 6:
		this->jugadorActual->mostrarTerreno();
		break;
	case 7:{
		this->posJugadorEnJugadores++;
		revisarEstados();
		this->jugadorActual->finalizarTurno();
		break;
		}
	}
	return;
}

ui Juego::obtenerTurnos(){
	return this->turnosJuego;
}

void Juego::revisarEstados(){
	this->jugadorActual->terrenosSembrados();
}

void Juego::agregarSemillas(){
	std::string rutaEntrada = "Datos/cultivos.txt";
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());
	while (! entrada.eof()) {

		Semilla* semilla = new Semilla();
		ui costo;
		ui tiempoCosecha;
		ui rentabilidad;
		ui tiempoRecup;
		ui aguaTurno;
		char tipo;

		entrada >> tipo;
		if (! entrada.eof()) {
			entrada >> costo;
			entrada >> tiempoCosecha;
			entrada >> rentabilidad;
			entrada >> tiempoRecup;
			entrada >> aguaTurno;
			semilla->iniciar(tipo,costo,tiempoCosecha,rentabilidad,tiempoRecup,aguaTurno);
			this->semillas->agregar(semilla);
		}
	}
}

Juego::~Juego() {
	delete this->jugadores;
}
