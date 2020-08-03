#ifndef VERTICES_H
#define VERTICES_H

#include <string>
#include <iostream>
#include "Lista.h"
#include "Etiqueta.h"

using namespace std;

typedef Etiqueta* Dato_3;

class Vertices{

    private:

        string vertice;
        Lista < Dato_3 > etiqueta;

    public:

        Vertices ();

        Vertices (string nombre);

        string obtener_vertice();
        void asignar_vertice (string nombre);
        void asignar_etiqueta (Dato_3 dato);

        string obtener_etiqueta_anterior (int posicion);
        int obtener_etiqueta_costo_acumulado (int posicion);
        double obtener_etiqueta_horas_acumuladas (int posicion);
};

#endif // VERTICES_H
