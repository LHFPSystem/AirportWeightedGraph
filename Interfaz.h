#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "BST.h"
#include "Cargador.h"
#include <sstream>
#include <cstring>

class Interfaz{
	private:
		unsigned opcion;
		BST<string>* p_arbol;
		Lista <punteroVertice> vertices;
    	Lista <punteroVuelo> vuelos;
	public:
		Interfaz();
		~Interfaz();
		void set_p_arbol(BST<string>* p_arbol);
		void set_vertices(Lista <punteroVertice> vertices);
		void set_vuelos(Lista <punteroVuelo> vuelos);
		void menu();
		void consultar_aeropuerto();
		void ingresar_aeropuerto();
		void baja_aeropuerto();
		void mostrar_todos();
		void mostrar_arbol();
		void buscarVueloMasRapido();
		void buscarVueloMasBarato();
};

#endif //interfaz.h
