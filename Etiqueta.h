#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <string>

const int IMPRESIONES_INICIALES = 0;
const int COSTO_INICIAL = 0;
const double HORAS_INICIALES = 0.0;

using namespace std;

class Etiqueta{

    private:

        int costo_acumulado;
        double horas_acumuladas;
        string anterior;
        int cantidad_de_impresiones;

    public:

        // Constructores:

        //PRE: -.
        //POST: Construye un objeto de la clase Etiqueta.
        Etiqueta (string anterior, int costo_acumulado);

        //PRE: -.
        //POST: Construye un objeto de la clase Etiqueta.
        Etiqueta (string anterior, double horas_acumuladas);

        //PRE: -.
        //POST: Devuelve el atributo "anterior".
        string obtener_anterior();

        //PRE: -.
        //POST: Devuelve el atributo "costo_acumulado".
        int obtener_costo_acumulado ();

        //PRE: -.
        //POST: Devuelve el atributo "horas_acumuladas".
        double obtener_horas_acumuladas ();

        //PRE:
        //POST: Devuelve el atributo "cantidad_de_impresiones".
        int obtener_cantidad_de_impresiones();

        //PRE: -.
        //POST: Aumenta en 1 el atributo "cantidadad_de_impresiones".
        void aumentar_cantidad_de_impresiones ();
};

#endif // ETIQUETA_H
