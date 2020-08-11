#include "Vertices.h"

Vertices::Vertices (){

    this -> vertice = " ";
}

Vertices::Vertices (string nombre){

    this -> vertice = nombre;
}

string Vertices::obtener_vertice(){

    return this->vertice;
}

void Vertices::asignar_vertice (string nombre){

    this -> vertice = nombre;
}

void Vertices::asignar_etiqueta (Dato_3 dato){

    etiqueta.agregarAlFinal(dato);
}

string Vertices::obtener_etiqueta_anterior (int posicion){

    return etiqueta.obtenerDato(posicion)->obtener_anterior();
}

int Vertices::obtener_etiqueta_costo_acumulado (int posicion){

    return etiqueta.obtenerDato(posicion)->obtener_costo_acumulado();
}

double Vertices::obtener_etiqueta_horas_acumuladas (int posicion){

    return etiqueta.obtenerDato(posicion)->obtener_horas_acumuladas();
}

int Vertices::obtener_tamanio_etiquetas (){

    return etiqueta.obtenerCantidadElementos();
}

void Vertices::vaciar_lista_etiquetas (){

    while (!etiqueta.vacia()){
        etiqueta.sacar(PRIMER_ELEMENTO);
    }

}

int Vertices::obtener_cantidad_de_impresiones (int posicion){

    return etiqueta.obtenerDato(posicion)->obtener_cantidad_de_impresiones();
}

void Vertices::aumentar_impresiones(int posocion){

    etiqueta.obtenerDato(posocion)->aumentar_cantidad_de_impresiones();
}
