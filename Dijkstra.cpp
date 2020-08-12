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

    rellenar_vectores (vector_nombres, vector_costos, vector_horas, vector_visitados, lista_vertices);

    if (criterio == BARATO)
        calcular_costo_minimo(vector_nombres, vector_costos, vector_visitados, lista_vertices, lista_vuelos);

    if (criterio == RAPIDO)
        calcular_horas_minimas (vector_nombres, vector_horas, vector_visitados, lista_vertices, lista_vuelos);
}

void Dijkstra::rellenar_vectores (string vector_nombres[], int vector_costos[], double vector_horas[], bool vector_visitados[], Lista<Vertices*> &lista){

        for (int i = 0; i <lista.obtenerCantidadElementos(); i++){
        vector_nombres [i] = lista.obtenerDato(i)->obtener_vertice();
        vector_costos [i] = COSTO_INFINITO;
        vector_horas [i] = HORAS_INFINITAS;
        vector_visitados [i] = false;
    }
}


void Dijkstra::calcular_costo_minimo(string vector_nombres[], int vector_costos[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos){

    string destino_actual;
    string vertice_actual = origen;
    int posicion_actual = obtener_posicion (vertice_actual, vector_nombres, lista_vertices);
    int costo_actual;
    int posicion_destino;
    int costo_total_actual;
    int costo_minimo = COSTO_MINIMO_INICIAL;
    vector_costos [posicion_actual] = COSTO_EN_EL_ORIGEN;


    while (!todos_visitados (vector_visitados, lista_vertices)){

        llenar_lista_etiquetas_costos(lista_vertices, lista_vuelos, vector_costos, vector_nombres, &vertice_actual, &destino_actual, &costo_actual, &posicion_destino, &costo_total_actual, posicion_actual);

        vector_visitados[posicion_actual] = true;

        nuevo_destino_actual_costo (lista_vertices, vector_nombres, vector_visitados, vector_costos, &costo_minimo, &vertice_actual, &posicion_actual);
    }

    imprimir_por_costo(lista_vertices,lista_vuelos,vector_nombres);
}

void Dijkstra::nuevo_destino_actual_costo (Lista<Vertices*> &lista_vertices, string vector_nombres[], bool vector_visitados [], int vector_costos [], int* costo_minimo, string* vertice_actual, int* posicion_actual){

    for (int i = 0 ; i < lista_vertices.obtenerCantidadElementos() ; i++){
        if (vector_visitados [i] == false && vector_costos [i] < (*costo_minimo)){
                (*costo_minimo) = vector_costos [i];
                (*vertice_actual) = vector_nombres [i];
        }
    }
    (*posicion_actual) = obtener_posicion ((*vertice_actual), vector_nombres, lista_vertices);
    (*costo_minimo) = COSTO_MINIMO_INICIAL;
}

void Dijkstra::llenar_lista_etiquetas_costos(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos, int vector_costos[], string vector_nombres [], string* vertice_actual, string* destino_actual, int* costo_actual, int* posicion_destino, int* costo_total_actual, int posicion_actual){

    for (int i = 0; i<lista_vuelos.obtenerCantidadElementos(); i++){

        if ((*vertice_actual) == lista_vuelos.obtenerDato(i)->obtener_origen()){
            (*destino_actual) = lista_vuelos.obtenerDato(i)->obtener_destino();
            (*costo_actual) = lista_vuelos.obtenerDato(i)->obtener_costo();
            (*posicion_destino) = obtener_posicion ((*destino_actual), vector_nombres, lista_vertices);
            (*costo_total_actual) = (*costo_actual) + vector_costos [posicion_actual];

            if ((*costo_total_actual) == vector_costos [(*posicion_destino)]){
                Etiqueta* dato_etiqueta = new Etiqueta((*vertice_actual), (*costo_total_actual));
                lista_vertices.obtenerDato((*posicion_destino))->asignar_etiqueta(dato_etiqueta);
                cout << dato_etiqueta << " esta memoria es de una etiqueta " << endl << endl;
            }
            if ((*costo_total_actual) < vector_costos [(*posicion_destino)]){
                vector_costos [(*posicion_destino)] = (*costo_total_actual);
                lista_vertices.obtenerDato((*posicion_destino))->vaciar_lista_etiquetas ();
                Etiqueta* dato_etiqueta = new Etiqueta((*vertice_actual), (*costo_total_actual));
                lista_vertices.obtenerDato((*posicion_destino))->asignar_etiqueta(dato_etiqueta);
                cout << dato_etiqueta << " esta memoria es de una etiqueta " << endl << endl;
            }

        }
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



void Dijkstra::imprimir_por_costo(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> lista_vuelos, string vector_nombres[]){

    string destino_actual = destino;
    string origen_actual;
    int costo_actual;
    double horas = HORAS_INICIALES;

    int posicion_destino = obtener_posicion (destino_actual, vector_nombres, lista_vertices);
    Lista <Vuelos*> ruta_a_imprimir;

    int valor_actual;
    bool etiquetas_visitadas = false;
    int impresiones;

    if (lista_vertices.obtenerDato(posicion_destino)->obtener_tamanio_etiquetas () == 0){
        cout << "Lamentablemente no hay ninguna rura que conecte " << origen << " con " << destino << endl;

    }else{

        while (!etiquetas_visitadas){

            while (origen_actual != origen){

                    valor_actual = VALOR_INICIAL_BASE;

                    recorrer_etiquetas (lista_vertices, destino_actual, &origen_actual, &valor_actual);

                    //rellenar_ruta_a_imprimir (lista_vuelos, ruta_a_imprimir, origen_actual, destino_actual, &costo_actual, horas);
                    for ( int i = 0; i < lista_vuelos.obtenerCantidadElementos() ; i++){

                        if (lista_vuelos.obtenerDato(i)->obtener_origen() == origen_actual && lista_vuelos.obtenerDato(i)->obtener_destino() == destino_actual){
                        costo_actual = lista_vuelos.obtenerDato(i)->obtener_costo();
                        Vuelos* dato = new Vuelos(origen_actual, destino_actual, costo_actual, horas);
                        ruta_a_imprimir.agregarAlPrincipio(dato);
                        cout << dato << " esta memoria es de ruta a imprimir " << endl << endl;
                        }
                    }
                    destino_actual = origen_actual;
            }

            imprimir_camino_costo (ruta_a_imprimir);

            chequear_caminos_faltantes (lista_vertices, &impresiones, &etiquetas_visitadas);

            preparar_nuevo_recorrido ( &destino_actual, &origen_actual, ruta_a_imprimir);
        }
    }
}

void Dijkstra::recorrer_etiquetas (Lista<Vertices*> &lista_vertices, string destino_actual, string* origen_actual, int* valor_actual){

    for (int i = 0; i<lista_vertices.obtenerCantidadElementos(); i++){

        if (lista_vertices.obtenerDato(i)->obtener_vertice() == destino_actual && lista_vertices.obtenerDato(i)->obtener_tamanio_etiquetas () == 1)
            (*origen_actual) = lista_vertices.obtenerDato(i)->obtener_etiqueta_anterior (0);

        if (lista_vertices.obtenerDato(i)->obtener_vertice() == destino_actual && lista_vertices.obtenerDato(i)->obtener_tamanio_etiquetas () > 1){

            for (int j = 0; j< lista_vertices.obtenerDato(i)->obtener_tamanio_etiquetas(); j++){

                if ((*valor_actual) > lista_vertices.obtenerDato(i)->obtener_cantidad_de_impresiones (j)){
                    (*valor_actual) = lista_vertices.obtenerDato(i)->obtener_cantidad_de_impresiones (j);
                    (*origen_actual) = lista_vertices.obtenerDato(i)->obtener_etiqueta_anterior (j);
                }
            }
            for (int k = 0; k<lista_vertices.obtenerCantidadElementos(); k++){
                for (int l = 0; l<lista_vertices.obtenerDato(k)->obtener_tamanio_etiquetas(); l++){
                    if (lista_vertices.obtenerDato(k)->obtener_vertice() == destino_actual && lista_vertices.obtenerDato(i)->obtener_etiqueta_anterior (l) == (*origen_actual))
                        lista_vertices.obtenerDato(k)->aumentar_impresiones(l);
                }
            }
        }
    }
}

void Dijkstra::rellenar_ruta_a_imprimir (Lista <Vuelos*> lista_vuelos, Lista <Vuelos*> &ruta_a_imprimir, string origen_actual, string destino_actual, int* costo_actual, double horas){

    for (int i = 0; i < lista_vuelos.obtenerCantidadElementos() ; i++){

        if (lista_vuelos.obtenerDato(i)->obtener_origen() == origen_actual && lista_vuelos.obtenerDato(i)->obtener_destino() == destino_actual){
            (*costo_actual) = lista_vuelos.obtenerDato(i)->obtener_costo();
            Vuelos* dato = new Vuelos(origen_actual, destino_actual, (*costo_actual), horas);
            ruta_a_imprimir.agregarAlPrincipio(dato);
            cout << "entre" << endl << endl;
        }
    }
}

void Dijkstra::imprimir_camino_costo (Lista <Vuelos*> &ruta_a_imprimir){

    int coste_acumulado = COSTO_INICIAL;
    cout << "Un posible camino para ir de " << origen << " a " << destino << " seria:" << endl << endl;
    for (int j = 0; j<ruta_a_imprimir.obtenerCantidadElementos() ; j++){
        cout << "Ir de " << ruta_a_imprimir.obtenerDato(j)->obtener_origen();
        cout << " a " << ruta_a_imprimir.obtenerDato(j)->obtener_destino() << endl;
        cout << "Con un coste de: " << ruta_a_imprimir.obtenerDato(j)->obtener_costo() << " pesos." << endl << endl;
        coste_acumulado = coste_acumulado + ruta_a_imprimir.obtenerDato(j)->obtener_costo();
    }
    cout << "Y asi llegaria a destino, habiendo gastado un total de: " << coste_acumulado << " pesos." << endl << endl << endl << endl ;
}

void Dijkstra::chequear_caminos_faltantes (Lista<Vertices*> &lista_vertices, int* impresiones, bool* etiquetas_visitadas){

    (*etiquetas_visitadas) = true;

    for (int i = 0; i<lista_vertices.obtenerCantidadElementos(); i++){
        if (lista_vertices.obtenerDato(i)->obtener_tamanio_etiquetas() > 1){
            (*impresiones) = lista_vertices.obtenerDato(i)->obtener_cantidad_de_impresiones (0);
            for (int j = 0; j<lista_vertices.obtenerDato(i)->obtener_tamanio_etiquetas(); j++){
                if ((*impresiones) != lista_vertices.obtenerDato(i)->obtener_cantidad_de_impresiones (j))
                    (*etiquetas_visitadas) = false;
            }
        }
    }
}

void Dijkstra::preparar_nuevo_recorrido (string* destino_actual, string* origen_actual, Lista <Vuelos*> &ruta_a_imprimir){

    (*destino_actual) = destino;
    (*origen_actual) = NOMBRE_GENERICO;
    while (!ruta_a_imprimir.vacia()){
        ruta_a_imprimir.sacar(PRIMER_ELEMENTO);
    }
}


//------------------------------------------------------------------------------------------------------------------------------

void Dijkstra::calcular_horas_minimas (string vector_nombres[], double vector_horas[], bool vector_visitados[], Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos){

    string destino_actual;
    string vertice_actual = origen;
    int posicion_actual = obtener_posicion (vertice_actual, vector_nombres, lista_vertices);
    double horas_actuales;
    int posicion_destino;
    double horas_totales_actuales;
    double horas_minimas = HORAS_MINIMAS_INICIAL;
    vector_horas [posicion_actual] = HORAS_EN_EL_ORIGEN;


    while (!todos_visitados (vector_visitados, lista_vertices)){

        llenar_lista_etiquetas_horas(lista_vertices, lista_vuelos, vector_horas, vector_nombres, &vertice_actual, &destino_actual, &horas_actuales, &posicion_destino, &horas_totales_actuales, posicion_actual);

        vector_visitados[posicion_actual] = true;

        nuevo_destino_actual_horas (lista_vertices, vector_nombres, vector_visitados, vector_horas, &horas_minimas, &vertice_actual, &posicion_actual);
    }

    imprimir_por_horas(lista_vertices, lista_vuelos, vector_nombres);
}

void Dijkstra::llenar_lista_etiquetas_horas(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> &lista_vuelos, double vector_horas[], string vector_nombres [], string* vertice_actual, string* destino_actual, double* horas_actuales, int* posicion_destino, double* horas_totales_actuales, int posicion_actual){

    for (int i = 0; i<lista_vuelos.obtenerCantidadElementos(); i++){

        if ((*vertice_actual) == lista_vuelos.obtenerDato(i)->obtener_origen()){
            (*destino_actual) = lista_vuelos.obtenerDato(i)->obtener_destino();
            (*horas_actuales) = lista_vuelos.obtenerDato(i)->obtener_horas();
            (*posicion_destino) = obtener_posicion ((*destino_actual), vector_nombres, lista_vertices);
            (*horas_totales_actuales) = (*horas_actuales) + vector_horas [posicion_actual];

            if ((*horas_totales_actuales) == vector_horas [(*posicion_destino)]){
                Etiqueta* dato_etiqueta = new Etiqueta((*vertice_actual), (*horas_totales_actuales));
                lista_vertices.obtenerDato((*posicion_destino))->asignar_etiqueta(dato_etiqueta);
            }
            if ((*horas_totales_actuales) < vector_horas [(*posicion_destino)]){
                vector_horas [(*posicion_destino)] = (*horas_totales_actuales);
                lista_vertices.obtenerDato((*posicion_destino))->vaciar_lista_etiquetas ();
                Etiqueta* dato_etiqueta = new Etiqueta((*vertice_actual), (*horas_totales_actuales));
                lista_vertices.obtenerDato((*posicion_destino))->asignar_etiqueta(dato_etiqueta);
            }

        }
    }

}

void Dijkstra::nuevo_destino_actual_horas (Lista<Vertices*> &lista_vertices, string vector_nombres[], bool vector_visitados [], double vector_horas [], double* horas_minimas, string* vertice_actual, int* posicion_actual){

    for (int i = 0 ; i < lista_vertices.obtenerCantidadElementos() ; i++){
        if (vector_visitados [i] == false && vector_horas [i] < (*horas_minimas)){
                (*horas_minimas) = vector_horas [i];
                (*vertice_actual) = vector_nombres [i];
        }
    }
    (*posicion_actual) = obtener_posicion ((*vertice_actual), vector_nombres, lista_vertices);
    (*horas_minimas) = HORAS_MINIMAS_INICIAL;



}

void Dijkstra::imprimir_por_horas(Lista<Vertices*> &lista_vertices, Lista <Vuelos*> lista_vuelos, string vector_nombres[]){

    string destino_actual = destino;
    string origen_actual;
    double horas_actuales;
    int costo = 0;

    int posicion_destino = obtener_posicion (destino_actual, vector_nombres, lista_vertices);
    Lista <Vuelos*> ruta_a_imprimir;

    int valor_actual;
    bool etiquetas_visitadas = false;
    int impresiones;

    if (lista_vertices.obtenerDato(posicion_destino)->obtener_tamanio_etiquetas () == 0){
        cout << "Lamentablemente no hay ninguna rura que conecte " << origen << " con " << destino << endl;

    }else{

        while (!etiquetas_visitadas){

            while (origen_actual != origen){

                    valor_actual = VALOR_INICIAL_BASE;

                    recorrer_etiquetas (lista_vertices, destino_actual, &origen_actual, &valor_actual);

                    //rellenar_ruta_a_imprimir (lista_vuelos, ruta_a_imprimir, origen_actual, destino_actual, &costo_actual, horas);
                    for ( int i = 0; i < lista_vuelos.obtenerCantidadElementos() ; i++){

                        if (lista_vuelos.obtenerDato(i)->obtener_origen() == origen_actual && lista_vuelos.obtenerDato(i)->obtener_destino() == destino_actual){
                        horas_actuales = lista_vuelos.obtenerDato(i)->obtener_horas();
                        Vuelos* dato = new Vuelos(origen_actual, destino_actual, costo, horas_actuales);
                        ruta_a_imprimir.agregarAlPrincipio(dato);
                        }
                    }
                    destino_actual = origen_actual;
            }

            imprimir_camino_horas (ruta_a_imprimir);

            chequear_caminos_faltantes (lista_vertices, &impresiones, &etiquetas_visitadas);

            preparar_nuevo_recorrido ( &destino_actual, &origen_actual, ruta_a_imprimir);
        }
    }
}

void Dijkstra::imprimir_camino_horas (Lista <Vuelos*> &ruta_a_imprimir){

    double horas_acumuladas = HORAS_INICIALES;
    cout << "Un posible camino para ir de " << origen << " a " << destino << " seria:" << endl << endl;
    for (int j = 0; j<ruta_a_imprimir.obtenerCantidadElementos() ; j++){
        cout << "Ir de " << ruta_a_imprimir.obtenerDato(j)->obtener_origen();
        cout << " a " << ruta_a_imprimir.obtenerDato(j)->obtener_destino() << endl;
        cout << "Con un coste de: " << ruta_a_imprimir.obtenerDato(j)->obtener_horas() <<" horas."<< endl << endl;
        horas_acumuladas = horas_acumuladas + ruta_a_imprimir.obtenerDato(j)->obtener_horas();
    }
    cout << "Y asi llegaria a destino, habiendo gastado un total de: " << horas_acumuladas << " horas." << endl << endl << endl << endl ;
}




