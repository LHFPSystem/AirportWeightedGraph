#include "Etiqueta.h"

Etiqueta::Etiqueta (string anterior, int costo_acumulado){

    this -> anterior = anterior;
    this -> costo_acumulado = costo_acumulado;
    this -> horas_acumuladas = HORAS_INICIALES;
    this -> cantidad_de_impresiones = IMPRESIONES_INICIALES;
}

Etiqueta::Etiqueta (string anterior, double horas_acumuladas){

    this -> anterior = anterior;
    this -> horas_acumuladas = horas_acumuladas;
    this -> costo_acumulado = COSTO_INICIAL;
    this -> cantidad_de_impresiones = IMPRESIONES_INICIALES;
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

int Etiqueta::obtener_cantidad_de_impresiones(){

    return this -> cantidad_de_impresiones;
}

void Etiqueta::aumentar_cantidad_de_impresiones (){

    this -> cantidad_de_impresiones ++;
}


