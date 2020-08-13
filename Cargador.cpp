#include <fstream>
#include "Cargador.h"

// Constructor
Cargador::Cargador(){
	p_arbol=new BST<string>;
}

Cargador::~Cargador(){
}

void Cargador::cargar_datos() {
    ifstream archivo("aeropuertos.txt");

    if (archivo.fail()){
    	cout << "Error, no se pudo abrir el archivo: " <<"aeropuertos.txt"<< endl;
    }else{    	  
		while (archivo >> iata){
            archivo >> nombre;
            archivo >> ciudad;
            archivo >> pais;
            archivo >> superficie;
            archivo >> terminales;
            archivo >> d_nacionales;
            archivo >> d_internacionales;
            p_aeropuerto=new Aeropuerto(iata,nombre,ciudad,pais,superficie,terminales,d_nacionales,d_internacionales);            
            p_arbol->insert((p_aeropuerto->get_iata()), p_aeropuerto);
        }
        archivo.close();
        delete p_aeropuerto;
    }
}

BST<string>* Cargador::obtener_p_arbol(){
	return p_arbol;
}
