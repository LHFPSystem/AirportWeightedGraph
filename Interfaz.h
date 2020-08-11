#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "BST.h"
#include "Cargador.h"

class Interfaz{
	private:
		unsigned opcion;
		BST<string>* p_arbol;
	public:
		Interfaz(BST<string>* p_arbol);
		~Interfaz();
		void menu();
		void consultar_aeropuerto();
		void ingresar_aeropuerto();
		void baja_aeropuerto();
		void mostrar_todos();
		void mostrar_arbol();
};

#endif //interfaz.h