#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include "Vertices.h"
#include "Vuelos.h"

using namespace std;

const char BARATO = 'B';
const char RAPIDO = 'R';
const int VALOR_INICIAL_BASE = 100000;
const int COSTO_MINIMO_INICIAL = 1000000;
const int COSTO_INFINITO = 100000;
const int COSTO_EN_EL_ORIGEN = 0;
const double HORAS_MINIMAS_INICIAL = 1000000.0;
const double HORAS_INFINITAS = 100000.0;
const double HORAS_EN_EL_ORIGEN = 0.0;


class Dijkstra{

    private:

        string origen;
        string destino;
        char criterio;

    public:

        Dijkstra (string nombre_origen, string nombre_destino, char criterio);

        void calcular_caminos_minimos (Lista<Vertices*> &lista_vertices,Lista <Vuelos*> lista_vuelos);

        void calcular_costo_minimo (string vector_nombres[], int vector_costos[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos);

        int obtener_posicion (string nombre, string vector_nombres[], Lista<Vertices*> &lista);

        bool todos_visitados (bool vector_visitados[], Lista<Vertices*> &lista);

        void imprimir_por_costo (Lista<Vertices*> &lista_vertices,Lista <Vuelos*> lista_vuelos, string vector_nombres[]);

        void rellenar_vectores (string vector_nombres[], int vector_costos[], double vector_horas[], bool vector_visitados[], Lista<Vertices*> &lista);

        void llenar_lista_etiquetas_costos (Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos, int vector_costos[], string vector_nombres [], string* vertice_actual, string* destino_actual, int* costo_actual, int* posicion_destino, int* costo_total_actual, int posicion_actual);

        void nuevo_destino_actual_costo (Lista<Vertices*> &lista_vertices, string vector_nombres [], bool vector_visitados [], int vector_costos [], int* costo_minimo, string* vertice_actual, int* posicion_actual);

        void recorrer_etiquetas (Lista<Vertices*> &lista_vertices, string destino_actual, string* origen_actual, int* valor_actual);

        void rellenar_ruta_a_imprimir (Lista <Vuelos*> lista_vuelos, Lista <Vuelos*> &ruta_a_imprimir, string origen_actual, string destino_actual, int* costo_actual, double horas);

        void imprimir_camino_costo (Lista <Vuelos*> &ruta_a_imprimir);

        void chequear_caminos_faltantes (Lista<Vertices*> &lista_vertices, int* numero, bool* etiquetas_visitadas);

        void preparar_nuevo_recorrido (string* destino_actual, string* origen_actual, Lista <Vuelos*> &ruta_a_imprimir);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        void calcular_horas_minimas (string vector_nombres[], double vector_horas[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos);

        void llenar_lista_etiquetas_horas(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos, double vector_horas[], string vector_nombres [], string* vertice_actual, string* destino_actual, double* horas_actuales, int* posicion_destino, double* horas_totales_actuales, int posicion_actual);

        void nuevo_destino_actual_horas (Lista<Vertices*> &lista_vertices, string vector_nombres[], bool vector_visitados [], double vector_horas [], double* horas_minimas, string* vertice_actual, int* posicion_actual);

        void imprimir_por_horas(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> lista_vuelos, string vector_nombres[]);

        void imprimir_camino_horas (Lista <Vuelos*> &ruta_a_imprimir);
};


#endif // DIJKSTRA_H
