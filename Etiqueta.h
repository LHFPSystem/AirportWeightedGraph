#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <string>

using namespace std;

class Etiqueta{

    private:

        int costo_acumulado;
        double horas_acumuladas;
        string anterior;

    public:

        Etiqueta (string anterior, int costo_acumulado);

        Etiqueta (string anterior, double horas_acumuladas);

        string obtener_anterior();
        int obtener_costo_acumulado ();
        double obtener_horas_acumuladas ();




};

#endif // ETIQUETA_H
