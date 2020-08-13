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

        //Constructores:

        //PRE: -.
        //POST: Construye un ojbeto de la clase Vuelos.
        Vuelos ();

        //PRE: -.
        //POST: Construye un ojbeto de la clase Vuelos.
        Vuelos (string origen, string destino, int costo, double horas);

        //PRE: -.
        //POST: Devuelve el atributo "origen".
        string obtener_origen();

        //PRE: -.
        //POST: Devuelve el atributo "destino".
        string obtener_destino();

        //PRE: -.
        //POST: Devuelve el atributo "costo".
        int obtener_costo();

        //PRE: -.
        //POST: Devuelve el atributo "horas".
        double obtener_horas();

};

#endif // VUELOS_H
