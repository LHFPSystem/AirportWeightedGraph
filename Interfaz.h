#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "BST.h"
#include "Cargador.h"
# include  < sstream >
# include  < cstring >


class Interfaz{
	private:
		unsigned opcion;
		BST<string>* p_arbol;
	public:
		//Crea Interfaz.
		Interfaz();
		
		//Destruye Interfaz.
		~Interfaz();
		
		PRE:El arbol debe estar creado.
		POST://Actualiza el puntero al arbol.
		void set_p_arbol(BST<string>* p_arbol);
		
		//PRE:El arbol debe estar creado y no vacio.
		//POST:Muestra en pantalla una lista con opciones 
		Opcion 1: llama al metodo consultar_aeropuerto
		Opcion 2: llama al metodo ingresar_aeropuerto
		Opcion 3: llama al metodo baja_aeropuerto
		Opcion 4: llama al metodo mostrar_todos
		Opcion 5: llama al metodo mostar_arbol
		Opcion 6: finaliza el programa
		destruye el puntero al arbol.	 
		void menu();
		
		//PRE: El arbol debe estar creado y no vacio.
		//POST:Pide en pantalla el codigo IATA lo busca en el arbol.
		//Si la clave esta muestra los datos del aeropuerto sino imprime que no esta.
		void consultar_aeropuerto();
		
		//PRE: 
		//POST:Pide en pantalla los datos del aeropuerto lo inserta en el arbol y imprime el arbol inorden.
		void ingresar_aeropuerto();
		
		//PRE:El arbol debe estar creado y no vacio
		//POST:Pide por pantalla el codigo IATA a dar de baja en el arbol si lo encuentro lo da de baja sino muestra por pantalla que no esta
		void baja_aeropuerto();
		
		//PRE:El arbol debe estar creado y no vacio 
		//POST:LLama al metodo print_in_order.
		void mostrar_todos();
		
		//El arbol debe estar creado y no vacio.
		//POST:LLama al metodo print_width2 que imprime por nivel las claves del arbol
		void mostrar_arbol();
};

#endif //interfaz.h
