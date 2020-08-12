#include <iostream>
#include <fstream>
#include "Vertices.h"
#include "Vuelos.h"
#include "Dijkstra.h"

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

                Vertices* dato =  new Vertices(origen);
                Vuelos* dato_2 =  new Vuelos(origen, destino, atoi(costo.c_str()), atof(horas.c_str()));
                //cout << dato << " esta memoria es de un vertice " << endl << endl;
                //cout << dato_2 <<" esta memoria es de un vuelo " << endl << endl;
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

    Dijkstra dijkstra ("LMS", "OPL", 'B');
    dijkstra.calcular_caminos_minimos(vertices,vuelos);
    cout << "hola" << endl << endl;
    return 0;
}
