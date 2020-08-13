#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Cargador.h"
#include "Dijkstra.h"
#include <fstream>

typedef Vertices* punteroVertice;
typedef Vuelos* punteroVuelo;

class Interfaz{
	private:
		unsigned opcion;
		BST<string>* p_arbol;
        Lista <punteroVertice> vertices;
    	Lista <punteroVuelo> vuelos;
	public:

	    //Crea Interfaz.
		Interfaz();

		//Destruye Interfaz.
		~Interfaz();

        //PRE: El arbol debe estar creado.
		//POST: Actualiza el puntero al arbol.
		void ingresar_p_arbol(BST<string>* p_arbol);

        //PRE:El arbol debe estar creado y no vacio.
		//POST:Muestra en pantalla una lista con opciones
		void menu();

		//PRE: El arbol debe estar creado y no vacio.
		//POST:Pide en pantalla el codigo IATA lo busca en el arbol. Si la clave esta muestra los datos del aeropuerto sino imprime que no esta.
		void consultar_aeropuerto();

		//PRE:-.
		//POST:Pide en pantalla los datos del aeropuerto lo inserta en el arbol y imprime el arbol inorden.
		void ingresar_aeropuerto();

		//PRE:El arbol debe estar creado y no vacio
		//POST:Pide por pantalla el codigo IATA a dar de baja en el arbol si lo encuentro lo da de baja sino muestra por pantalla que no esta
		void baja_aeropuerto();

		//PRE:El arbol debe estar creado y no vacio
		//POST:LLama al metodo print_in_order.
		void mostrar_todos();

		//PRE: El arbol debe estar creado y no vacio.
		//POST:LLama al metodo print_width2 que imprime por nivel las claves del arbol
		void mostrar_arbol();

        //PRE: Las listas de vertices y vuelos tiene que estar correctametne cargadas.
        //POST: Llama al algoritmos de Dijkstra por el criterio de horas de vuelo.
        void buscarVueloMasRapido();

        //PRE: Las listas de vertices y vuelos tiene que estar correctametne cargadas.
        //POST: Llama al algoritmos de Dijkstra por el criterio del costo de los vuelos.
		void buscarVueloMasBarato();

		//PRE:-.
		//POST: Rellena las listas de vertices y vuelos con la informacion necesaria para que trabajen.
		void rellenar_listas();

		//PRE:-.
		//POST: Le ingresa un valor al atributo "Lista <punteroVertice> vertices"
        void set_vertices(Lista <punteroVertice> vertices);

        //PRE:-.
		//POST: Le ingresa un valor al atributo "Lista <punteroVuelo> vuelos".
		void set_vuelos(Lista <punteroVuelo> vuelos);
};

#endif //interfaz.h
