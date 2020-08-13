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

        //Constructores:

        //PRE: -.
        //POST: Construye un ojbeto de la clase Vertices.
        Vertices ();

        //PRE: -.
        //POST: Construye un ojbeto de la clase Vertices.
        Vertices (string nombre);


        //PRE: -.
        //POST: Devuelve el atributo "vertice".
        string obtener_vertice();

        //PRE: .-
        //POST: Le asigna un valor al atributo "vertice"
        void asignar_vertice (string nombre);

        //PRE: -.
        //POST: Crea una nueva etiqueta en la lista de etiquetas.
        void asignar_etiqueta (Dato_3 dato);

        //PRE: -.
        //POST: Devuelve el tamanio de la lista de etiquetas.
        int obtener_tamanio_etiquetas ();

        //PRE: -.
        //POST: Devuelve el atributo "anterior" de la lista de etiquetas.
        string obtener_etiqueta_anterior (int posicion);

        //PRE: -.
        //POST: Devuelve el atributo "costo_acumulado". de la lista de etiquetas.
        int obtener_etiqueta_costo_acumulado (int posicion);

        //PRE: -.
        //POST: Devuelve el atributo "horas_acumuladas" de la lista de etiquetas.
        double obtener_etiqueta_horas_acumuladas (int posicion);

        //PRE: -.
        //POST: Devuelve el atributo "horas_acumuladas" de la lista de etiquetas.
        int obtener_cantidad_de_impresiones (int posicion);

        //PRE: -.
        //POST: vacia la lista de etiquetas.
        void vaciar_lista_etiquetas ();

        //PRE: -.
        //POST: Aumenta en uno el atributo "cantidad_de_impresiones".
        void aumentar_impresiones(int posocion);
};

#endif // VERTICES_H
