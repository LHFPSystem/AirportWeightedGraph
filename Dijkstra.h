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

        //Constructor:

        //PRE: -.
        //POST: Construye un objeto de la clase Dijkstra.
        Dijkstra (string nombre_origen, string nombre_destino, char criterio);

        //PRE: Las listas deben contener informacion.
        //POST: Llama al procesamiento de del algoritmo de Dijkstra correspondiente segun el atributo "criterio".
        void calcular_caminos_minimos (Lista<Vertices*> &lista_vertices,Lista <Vuelos*> lista_vuelos);

        //PRE:  El vector_nombres debe haberse llenado correctamente con la informacion de la lista correspondiente.
        //POST: Devuelve un entero que relaciona la posicion de los codigos IATA con la posicion de los vectores.
        int obtener_posicion (string nombre, string vector_nombres[], Lista<Vertices*> &lista);

        //PRE: -.
        //POST: Devuelve si ya se visitaron todos los vertices del grafo.
        bool todos_visitados (bool vector_visitados[], Lista<Vertices*> &lista);

        //PRE: La lista no debe tener elementos repetidos.
        //POST: Rellena los vectores con sus "valores inicales" correspondientes.
        void rellenar_vectores (string vector_nombres[], int vector_costos[], double vector_horas[], bool vector_visitados[], Lista<Vertices*> &lista);

        //PRE: Que las listas de etiquetas esten bien cargadas.
        //POST: Procesa las etiquetas de la lista de vertices.
        void recorrer_etiquetas (Lista<Vertices*> &lista_vertices, string destino_actual, string* origen_actual, int* valor_actual);

        //PRE: Que exista una lista "ruta_a_imprimir"
        //POST: Rellena en orden el camino mininmo ha imprimir.
        void rellenar_ruta_a_imprimir (Lista <Vuelos*> lista_vuelos, Lista <Vuelos*> &ruta_a_imprimir, string origen_actual, string destino_actual, int* costo_actual, double horas);

        //PRE: Que las listas de etiquetas esten bien cargadas.
        //POST: Se fija si todos los caminos minimos fueron procesados.
        void chequear_caminos_faltantes (Lista<Vertices*> &lista_vertices, int* numero, bool* etiquetas_visitadas);

        //PRE: -.
        //POST: Prepara las condiciones para poder procesar un nuevo camino minimo.
        void preparar_nuevo_recorrido (string* destino_actual, string* origen_actual, Lista <Vuelos*> &ruta_a_imprimir);

//--------------------------- Metodos especificos por costo ----------------------------------------------------------------------------------------------------------------------------

        //PRE: Los vectores y las listas deben estar correctamente cargados con sus "valores inicales".
        //POST: Calcula los caminos minimos desde el origen al destino seleccionados dependiendo del coste de los viajes.
        void calcular_costo_minimo (string vector_nombres[], int vector_costos[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos);

        //PRE: Las listas de etiquetas de los vertices deben estar correctamente cargadas.
        //POST: Imprime por pantalla todos los posibles caminos minimos calculados por costo que existen entre el origen y el destino.
        void imprimir_por_costo (Lista<Vertices*> &lista_vertices,Lista <Vuelos*> lista_vuelos, string vector_nombres[]);

        //PRE: la lista de vertices no debe tener elementos repetidos.
        //POST: Completa la lista de etiquetas de todos los vertices.
        void llenar_lista_etiquetas_costos (Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos, int vector_costos[], string vector_nombres [], string* vertice_actual, string* destino_actual, int* costo_actual, int* posicion_destino, int* costo_total_actual, int posicion_actual);

        //PRE: -.
        //POST: Elige el nuevo vertice a procesar en el algoritmo de Dijkstra.
        void nuevo_destino_actual_costo (Lista<Vertices*> &lista_vertices, string vector_nombres [], bool vector_visitados [], int vector_costos [], int* costo_minimo, string* vertice_actual, int* posicion_actual);

        //PRE: Que la lista "ruta_a_imprimir" este bien cargada.
        //POST: Imprime por pantalla todos los caminos minimos que calculo mediante el costo y el costo de cada uno de los viajes individualmente.
        void imprimir_camino_costo (Lista <Vuelos*> &ruta_a_imprimir);

//--------------------------- Metodos especificos por horas ----------------------------------------------------------------------------------------------------------------------------

        //PRE: Los vectores y las listas deben estar correctamente cargados con sus "valores inicales".
        //POST: Calcula los caminos minimos desde el origen al destino seleccionados dependiendo de las horas de los viajes.
        void calcular_horas_minimas (string vector_nombres[], double vector_horas[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos);

        //PRE: la lista de vertices no debe tener elementos repetidos.
        //POST: Completa la lista de etiquetas de todos los vertices.
        void llenar_lista_etiquetas_horas(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos, double vector_horas[], string vector_nombres [], string* vertice_actual, string* destino_actual, double* horas_actuales, int* posicion_destino, double* horas_totales_actuales, int posicion_actual);

        //PRE: -.
        //POST: Elige el nuevo vertice a procesar en el algoritmo de Dijkstra.
        void nuevo_destino_actual_horas (Lista<Vertices*> &lista_vertices, string vector_nombres[], bool vector_visitados [], double vector_horas [], double* horas_minimas, string* vertice_actual, int* posicion_actual);

        //PRE: Las listas de etiquetas de los vertices deben estar correctamente cargadas.
        //POST: Imprime por pantalla todos los posibles caminos minimos calculados por las horas de viaje que existen entre el origen y el destino.
        void imprimir_por_horas(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> lista_vuelos, string vector_nombres[]);

        //PRE: Que la lista "ruta_a_imprimir" este bien cargada.
        //POST: Imprime por pantalla todos los caminos minimos que calculo mediante las horas de viaje y las horas de viaje de cada uno de los viajes individualmente.
        void imprimir_camino_horas (Lista <Vuelos*> &ruta_a_imprimir);
};


#endif // DIJKSTRA_H
