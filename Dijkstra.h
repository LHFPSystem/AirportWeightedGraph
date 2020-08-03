#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include "Vertices.h"
#include "Vuelos.h"

using namespace std;

class Dijkstra{

    private:

        string origen;
        string destino;
        char criterio;

    public:

        Dijkstra (string nombre_origen, string nombre_destino, char criterio);

        /*string obtener_origen();
        string obtener_destino();
        char obtener_criterio();
        */
        void calcular_caminos_minimos(Lista<Vertices*> &lista_vertices,Lista <Vuelos*> lista_vuelos);

        void calcular_costo_minimo(string vector_nombres[], int vector_costos[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos);

        int obtener_posicion (string nombre, string vector_nombres[], Lista<Vertices*> &lista);

        bool todos_visitados (bool vector_visitados[], Lista<Vertices*> &lista);
};


#endif // DIJKSTRA_H
