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

        Etiqueta (string anterior, int costo_acumulado);

        Etiqueta (string anterior, double horas_acumuladas);

        string obtener_anterior();
        int obtener_costo_acumulado ();
        double obtener_horas_acumuladas ();
        int obtener_cantidad_de_impresiones();

        void aumentar_cantidad_de_impresiones ();



};

#endif // ETIQUETA_H
