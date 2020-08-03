#include "Etiqueta.h"

Etiqueta::Etiqueta (string anterior, int costo_acumulado){

    this -> anterior = anterior;
    this -> costo_acumulado = costo_acumulado;
    this -> horas_acumuladas = 0.0;
}

Etiqueta::Etiqueta (string anterior, double horas_acumuladas){

    this -> anterior = anterior;
    this -> horas_acumuladas = horas_acumuladas;
    this -> costo_acumulado = 0;
}

string Etiqueta::obtener_anterior(){

    return this -> anterior;
}

int Etiqueta::obtener_costo_acumulado (){

    return this -> costo_acumulado;
}

double Etiqueta::obtener_horas_acumuladas (){

    return this -> horas_acumuladas;
}


