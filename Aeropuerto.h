#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <iostream>
#include <string>

using namespace std;

class Aeropuerto{
	private:
		// atributos correspondientes a caracteristicas de un aeropuerto
		string iata;
		string nombre;
		string ciudad;
		string pais;
		double superficie;
		int terminales;
		int d_nacionales;
		int d_internacionales;

	public:
		//Constructor
		//PRE: ninguna
		//POST: crea un objeto diseñado para almacenar informacion de un aeropuerto
		Aeropuerto();

		//Constructor
		//PRE: recibir por parametro todos los atributos que constituyen el objeto
		//POST: crea un objeto diseñado para almacenar informacion de un aeropuerto
		Aeropuerto(string iata, string nombre, string ciudad, string pais, double superficie, int terminales, int d_nacionales, int d_internacionales);

		//Destructor
		//PRE: Carga creada
		//POST:  destruye un ojeto de tipo Aeropuerto
		~Aeropuerto();

		//setea todos los atributos que configuran el objeto Aeropuerto
		//PRE: recibir por parametro todos los atributos que constituyen el objeto
		//POST: setea un objeto diseñado para almacenar informacion de un aeropuerto
		void setea_todo(string iata, string nombre, string ciudad, string pais, double superficie, int terminales, int d_nacionales, int d_internacionales);

		//Devuelve un string con el codigo iata
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un string correspondiente al codigo iata del aeropuerto
		string get_iata();

		//Devuelve un string con el nombre del aeropuerto
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un string correspondiente al nombre del aeropuerto
		string get_nombre();

		//Devuelve un string con la ciudad
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un string correspondiente a la ciudad en que está emplazada el aeropuerto
		string get_ciudad();

		//Devuelve un string con el pais
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un string correspondiente al pais del aeropuerto
		string get_pais();

		//Devuelve un double con la superficie
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un double con la informacion de la superficie que ocupa el aeropuerto
		double get_superficie();

		//Devuelve un int con el numero de terminales
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un int con la cantidad de terminales que posee el aeropuerto
		int get_terminales();

		//Devuelve un int con el numero de destinos nacionales
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un int con la cantidad de destinos nacionales que posee el aeropuerto
		int get_d_nacionales();

		//Devuelve un int con el numero de destinos internacionales
		//PRE: creacion de un objeto Aeropuerto (y carga de todos sus atributos)
		//POST: devuelve un int con la cantidad de destinos internacionales que posee el aeropuerto
		int get_d_internacionales();

		void mostrar_atributos();
		
};

#endif

