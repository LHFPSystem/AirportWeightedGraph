#ifndef CARGADOR_H
#define CARGADOR_H
#include "Aeropuerto.h"
#include "BST.h"
#include "BSTNode.h"
#include <sstream>
#include <cstring>

using namespace std;

class Cargador{
	private:
		string iata;
		string nombre;
		string ciudad;
		string pais;
		double superficie;
		int terminales;
		int d_nacionales;
		int d_internacionales;
		
		Aeropuerto* p_aeropuerto;
		BST<string>* p_arbol;


	public:
		//Constructor
		//PRE: ninguna
		//POST: crea un objeto diseñado para cargar informacion desde un archivo de texto
		Cargador();

		//Destructor
		//PRE: Carga creada
		//POST:  destruye un ojeto de tipo carga
		~Cargador();

		void cargar_datos();
		
		BST<string>* get_p_arbol();

};


#endif

