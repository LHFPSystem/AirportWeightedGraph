#include <iostream>
#include <fstream>
#include "Vertices.h"
#include "Vuelos.h"


using namespace std;

typedef Vertices* Dato;
typedef Vuelos* Dato_2;

const string RUTA_VUELOS = "vuelos.txt";

int main()
{
    Lista <Dato> vertices;
    Lista <Dato_2> vuelos;
    ifstream archivo_vuelos (RUTA_VUELOS);
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
/*
    for (int i=0; i<vertices.obtenerCantidadElementos(); i++){
        cout << vertices.obtenerDato(i)->obtener_vertice() << endl << endl;
    }
    for (int j=0; j<vuelos.obtenerCantidadElementos(); j++){
        cout << vuelos.obtenerDato(j)->obtener_origen() << endl;
        cout << vuelos.obtenerDato(j)->obtener_destino() <<  endl;
        cout << vuelos.obtenerDato(j)->obtener_costo() << endl;
        cout << vuelos.obtenerDato(j)->obtener_horas() << endl << endl;
    }
*/
}
