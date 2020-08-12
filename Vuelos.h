#ifndef VUELOS_H
#define VUELOS_H

#include <string>
#include <iostream>
#include "Lista.h"

using namespace std;

const int COSTO_BASE = 0;
const double HORAS_BASE = 0.0;
const string NOMBRE_GENERICO = "ZZZ";



class Vuelos{

    private:

        string origen;
        string destino;
        int costo;
        double horas;

    public:

        Vuelos ();

        Vuelos (string origen, string destino, int costo, double horas);


        string obtener_origen();
        string obtener_destino();
        int obtener_costo();
        double obtener_horas();

};

#endif // VUELOS_H
