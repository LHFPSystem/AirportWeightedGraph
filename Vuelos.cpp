#include "Vuelos.h"

Vuelos::Vuelos (){

    this->origen = NOMBRE_GENERICO;
    this->destino = NOMBRE_GENERICO;
    this->costo = COSTO_BASE;
    this->horas = HORAS_BASE;
}

Vuelos::Vuelos (string origen, string destino, int costo, double horas){

    this->origen = origen;
    this->destino = destino;
    this->costo = costo;
    this->horas = horas;
}


string Vuelos::obtener_origen(){

    return origen;
}

string Vuelos::obtener_destino(){

    return destino;
}

int Vuelos::obtener_costo(){

    return costo;
}

double Vuelos::obtener_horas(){

    return horas;
}
