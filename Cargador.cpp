#include <fstream>
#include "Cargador.h"

// Constructor
Cargador::Cargador(){
}

Cargador::~Cargador(){
}

void Cargador::cargar_datos() {
    ifstream archivo("aeropuertos.txt");

    if (archivo.fail()){
    	cout << "Error, no se pudo abrir el archivo: " <<"aeropuertos.txt"<< endl;
    }else{    	  
		while (archivo >> iata) {
            archivo >> nombre;
            archivo >> ciudad;
            archivo >> pais;
            archivo >> superficie;
            archivo >> terminales;
            archivo >> d_nacionales;
            archivo >> d_internacionales;
            // En este punto se instancia un aeropuerto
            p_aeropuerto=new Aeropuerto(iata,nombre,ciudad,pais,superficie,terminales,d_nacionales,d_internacionales);

            p_arbol->insert(p_aeropuerto, (p_aeropuerto->get_iata()));
        }         
        archivo.close();
        p_arbol->print_in_order();
        delete p_aeropuerto;
    }
}
