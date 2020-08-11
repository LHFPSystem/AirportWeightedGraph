#ifndef VERTICES_H
#define VERTICES_H

#include <string>
#include <iostream>
#include "Lista.h"
#include "Etiqueta.h"

using namespace std;

const int PRIMER_ELEMENTO = 0;

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
        int obtener_tamanio_etiquetas ();
        string obtener_etiqueta_anterior (int posicion);
        int obtener_etiqueta_costo_acumulado (int posicion);
        double obtener_etiqueta_horas_acumuladas (int posicion);
        void vaciar_lista_etiquetas ();
        int obtener_cantidad_de_impresiones (int posicion);
        void aumentar_impresiones(int posocion);
};

#endif // VERTICES_H
