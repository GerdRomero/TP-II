#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Lista.h"
#include "Semilla.h"
#include "Terreno.h"
#include "Almacen.h"
typedef unsigned short int ui;


struct Capacidad{
	ui filas;
	ui culumnas;
};

class Jugador {
private:
	struct estadoJugador{
	ui creditos;
	ui cantAgua;
	ui AguaMAX;
	int turnosRestantes;
	}estado;

	Semilla *aSembrar;
	Lista<Terreno**> *terrenos;
	Almacen *almacen;
	Terreno **terrenoEnJuego;
	//Almacen *almacen;
	//Mercado *mercado;
	ui dificultad;
	ui cantTerrenos;
	ui posicionTerrenoEnJuego;
	ui pos[];
	Capacidad numero;
	bool finTurno;
public:
	/*pre: dificultad valida, pedida en clase Juego
	 * post: crea objeto y llama a subrutinas cargarDatos()
	 *  y cargarDificJugador()*/
	Jugador(ui dificultad);
	/*post:opciones de compra, clase Mercado*/
	void comprar();
	/*pre:numero de terreno valido en lista terrenos
	 * post:cambia la posicion en lista terrenos para setear terrenoEnJuego*/
	void obtenerTerrenoEnJuego(ui posicionTerreno);
	/*post: cambia finTurno para cambiar al jugador en clase juego*/
	void finalizarTurno();
	/*post: regresa atributo finTurno, false:continua jugando
	 *  el mismo jugador en clase Juego*/
	bool noFinalizado();
	/*pre: datos validos ui
	  post:crea terreno y agrega en lista terrenos */
	void agregarTerreno(ui fila, ui col);
	/*pre: datos validos ui, aSembrar debe estar seteado desde elegirSemilla()
	 * post: siembra en terrenoEnJuego */
	void sembrarTerreno(Semilla* elegida);
	/*pre: datos validos ui
		 * post: riega en terrenoEnJuego cambiando estados en Terreno */
	void regarTerreno();
	/*pre: datos validos ui
		 * post: cosecha en terrenoEnJuego, cambiando estados en Terreno */
	void cosecharTerreno();
	/*post: devuelve un numero de terreno valido en lista terrenos*/
	ui terrenoValido();

	int verCreditos(){
		return this->estado.creditos;
	};
	int verCantAgua(){
		return this->estado.cantAgua;
	}
	int verTurnos(){
		return this->estado.turnosRestantes;
	}

	void restarCredito(int cant);
	void mostrarTerreno();

	void terrenosSembrados();

	void renovarTurno();
	ui totalDeCredito();
	ui totalDeAgua();
	ui numeroDeTerrenos();
	void agregarAgua(ui agua);
	void procesoDeAlmacen(Lista<Semilla*>* semillas);
	void mostrarAlmacen();
	virtual ~Jugador();
private:
	void actualizar();
	void apuntarTerreno();
	void comprarrTerreno();
	void agregando(std::string linea);
	/*post:leé un archivo de cultivos, crea una lista y setea en tipos de semillas a usar
	 * (subrutinas datosLista() y cargarCultivosJugador()*/

	void cargarDatos();
	ui filaTerreno();
	ui columnaTerreno();
	/*post:
	 * imprime info de los cultivos*/
	void mostrarInfo();
	/*pre: valores del menu a utilizar
	 * post: devuelve un valor valido entre min y max*/
	ui opcionValida(ui min, ui max);
	/* pre: cantTerreno debe ser mayor a 1.
	   post: cotiza,remueve y agrega creditos al jugador*/
	void venderTerreno();

	void comprarSemillas();
	/*pre: tipo de semilla existente en los cultivos del jugador
	 * post: setea en jugador el cultivo *aSembrar con el tipo de cultivo selleccionado */
	void elegirSemilla(ui opcion);
	void comprarTerreno();
	void comprarCapacAlmacen();
	/*pre: el costo de alguna compra del menu
	 * post: verifica si el jugador tiene creditos suficientes para esa compra*/
	bool hayCreditos(ui costoCompra);
	void mostrarMenuCompras();
	/*pre:Se llama luego de invocar al contructor, recibe una linea de texto
	 * y una referencia a una lista
	 * post:En la lista referenciada carga los datos de la linea de texto*/

	void cargarDificJugador(ui dificultad);
	void agregarCultivos(char tipo, ui cant);
	char semillaValida(ui opcion);
	void filaColValido();
	void verificarDimensionTerreno();

/*post: devuelve terrenoActual(el que esta usando el jugador de la lista de terrenos
 * , solo para hacer pruebas)*/
	Terreno** obtenerTerreno();

	void venderCosecha();
};

#endif /* JUGADOR_H_ */
