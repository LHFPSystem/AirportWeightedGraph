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
