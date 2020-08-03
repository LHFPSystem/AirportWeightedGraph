#include "Dijkstra.h"

Dijkstra::Dijkstra (string nombre_origen, string nombre_destino, char criterio){

    this -> origen = nombre_origen;
    this -> destino = nombre_destino;
    this -> criterio = criterio;
}

void Dijkstra::calcular_caminos_minimos(Lista<Vertices*> &lista_vertices,Lista <Vuelos*> lista_vuelos){

    string vector_nombres [lista_vertices.obtenerCantidadElementos()];
    int vector_costos [lista_vertices.obtenerCantidadElementos()];
    double vector_horas [lista_vertices.obtenerCantidadElementos()];
    bool vector_visitados [lista_vertices.obtenerCantidadElementos()];

////rellenar_vectores (vector_nombres, vector_costos, vector_horas, vector_visitados, Lista<Vertices*> &lista);
    for (int i = 0; i <lista_vertices.obtenerCantidadElementos(); i++){
        vector_nombres [i] = lista_vertices.obtenerDato(i)->obtener_vertice();
        vector_costos [i] = 1000;
        vector_horas [i] = 1000.1;
        vector_visitados [i] = false;
    }

 /*
    for (int i=0; i<lista.obtenerCantidadElementos(); i++){
        cout << vector_nombres [i] << endl;
        cout << vector_costos [i] <<  endl;
        cout << vector_horas [i] << endl;
        cout << vector_visitados [i] << endl << endl;
    }
*/

/////////////////////////////////////////////////////////////////////////////////////////////

    if (criterio == 'B')
        calcular_costo_minimo(vector_nombres, vector_costos, vector_visitados, lista_vertices, lista_vuelos);

    //if (criterio == 'R')
        //calcular_horas_minimas;


}

//void Dijkstra::rellenar_vectores (vector_nombres[], vector_costos[], vector_horas[], vector_visitados[], Lista<Vertices*> &lista){


void Dijkstra::calcular_costo_minimo(string vector_nombres[], int vector_costos[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos){

    string vertice_actual = origen;
    int posicion_actual = obtener_posicion (vertice_actual, vector_nombres, lista_vertices);
    vector_costos [posicion_actual] = 0;

    string destino_actual;
    int costo_actual;

    int posicion_destino;

    int costo_total_actual;

    int costo_minimo = 10000;

    string proximo_vertice;

    while (todos_visitados (vector_visitados, lista_vertices) == false){

        for (int i = 0; i<lista_vuelos.obtenerCantidadElementos(); i++){

                if (vertice_actual == lista_vuelos.obtenerDato(i)->obtener_origen()){

                    destino_actual = lista_vuelos.obtenerDato(i)->obtener_destino();
                    costo_actual = lista_vuelos.obtenerDato(i)->obtener_costo();
                    posicion_destino = obtener_posicion (destino_actual, vector_nombres, lista_vertices);
                    costo_total_actual = costo_actual + vector_costos [posicion_actual];

                    if (costo_total_actual < vector_costos [posicion_destino]){
                        vector_costos [posicion_destino] = costo_total_actual;
                        Etiqueta* dato_etiqueta = new Etiqueta(vertice_actual, costo_total_actual);
                        lista_vertices.obtenerDato(posicion_destino)->asignar_etiqueta(dato_etiqueta);
                    }
                    if (costo_total_actual == vector_costos [posicion_destino]){
                        Etiqueta* dato_etiqueta = new Etiqueta(vertice_actual, costo_total_actual);
                        lista_vertices.obtenerDato(posicion_destino)->asignar_etiqueta(dato_etiqueta);
                    }
                }
        }
        vector_visitados[posicion_actual] = true;
        for (int i = 0 ; i < lista_vertices.obtenerCantidadElementos() ; i++){
            if (vector_visitados [i] == false && vector_costos [i] < costo_minimo){
                costo_minimo = vector_costos [i];
                proximo_vertice = vector_nombres [i];
            }
        }
        vertice_actual = proximo_vertice;
        posicion_actual = obtener_posicion (vertice_actual, vector_nombres, lista_vertices);
    }
}


int Dijkstra::obtener_posicion (string nombre, string vector_nombres[], Lista<Vertices*> &lista){

    for (int i = 0; i<lista.obtenerCantidadElementos(); i++){
        if (vector_nombres[i] == nombre)
            return i;
    }
}

bool Dijkstra::todos_visitados (bool vector_visitados[], Lista<Vertices*> &lista){

    bool estan_visitados = true;
    for (int i = 0; i<lista.obtenerCantidadElementos(); i++){
        if (vector_visitados[i] == false)
        estan_visitados = false;
    }
    return estan_visitados;
}
