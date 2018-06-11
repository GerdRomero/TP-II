/*
 * Juego.h
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "Jugador.h"
#include "Lista.h"
#include "Semilla.h"
typedef unsigned short int ui;
class Juego {
private:
	Lista<Jugador*> *jugadores;
	Lista<Semilla*>* semillas;
	Jugador *jugadorActual;
	ui posJugadorEnJugadores;
	ui cantJugadores;
	ui turnosJuego;
	ui dificultad;
	bool juegoTerminado;

public:
	Juego();
	/*pre: cantidad de jugadores valida
	 * post: agrega jugadores en lista*/
	void agregarJugadores(ui cantidad);
	/*pre:Debe haber minimo un jugador, o llamar antes a agregarJugadores()
	 * post:inicia cursor en lista jugadores, avanza y setea jugadorActual*/
	void comenzarTurno();
	/*post: devuelve mientras queden turnos para jugar*/
	bool finJuego();
	/**************************************/
	ui obtenerTurnos();
	void asignar();
	void elegirDificultad();
	virtual ~Juego();
private:
	Semilla* elegirSemilla();
	void mostrarSemillas();
	/*pre:Debe invocarse agregarJugadores() antes
	 * post: inicia el juego con jugadorActual junto a las subrutinas en private*/
	void Jugar();

	/*post:Descuenta turnos al juego y setea su fin si ya no quedan*/
	void contarTurnos();
	/*pre:Debe haberse llamado a agregarJugadores() y luego a comenzarTurno()
	 * post: muestra acciones posibles al jugador*/
	void mostrarOpciones();
	/*post: imprime opciones disponibles*/
	void menu();
	ui opcionValida();

	/*post: devuelve dificultad valida*/


	/*post:devuelve jugadorActual, solo para hacer pruebas*/
	Jugador* obtenerJugador();
	/* post: llama al metodo del JugadorActual terrenoSenbrados *
		 */
	void revisarEstados();

	ui posicionDeJugador();
	/* post : Abre el archivo Cultivos y lo carga a la Lista de Semillas*/
	void agregarSemillas();


};

#endif /* JUEGO_H_ */
