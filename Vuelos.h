#ifndef VUELOS_H
#define VUELOS_H

#include <string>
#include <iostream>
#include "Lista.h"

using namespace std;

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
/*
        void asignar_origen(string origen);
        void asignar_origen(string destino);
        void asignar_origen(string costo);
        void asignar_origen(string horas);
*/

};

#endif // VUELOS_H
