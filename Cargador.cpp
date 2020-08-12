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
    Lista <punteroVertice> vertices;
    Lista <punteroVuelo> vuelos;
    ifstream archivo_vuelos ("vuelos.txt");
    string origen;
    string destino;
    string costo;
    string horas;

    if (!archivo_vuelos.fail()){
        while(!archivo_vuelos.eof()){
                archivo_vuelos >> origen;
                archivo_vuelos >> destino;
                archivo_vuelos >> costo;
                archivo_vuelos >> horas;

                Vertices* dato = new Vertices(origen);
                Vuelos* dato_2 = new Vuelos(origen, destino, atoi(costo.c_str()), atof(horas.c_str()));

                vuelos.agregarAlFinal(dato_2);
                vertices.agregarAlFinal(dato);
        }
    }
        for (int i=0; i<vertices.obtenerCantidadElementos(); i++){
            for (int j = i+1 ; j<vertices.obtenerCantidadElementos() ; j++){
                if (vertices.obtenerDato(i)->obtener_vertice() == vertices.obtenerDato(j)->obtener_vertice())
                    vertices.sacar(j);
            }
    }
}

BST<string>* Cargador::get_p_arbol(){
	return p_arbol;
}
