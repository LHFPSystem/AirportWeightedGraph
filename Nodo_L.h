#ifndef TP_FINAL_NODO_H
#define TP_FINAL_NODO_H
#include <iostream>

using namespace std;

template <typename Tipo>
class Nodo_L {

private:
    Tipo dato;
    Nodo_L* pSig;

public:

    // PRE: -
    // POST: Construye un nodo con el dato recibido
    Nodo_L(Tipo datoExterno);

    // PRE: -
    // POST: Le asigna pSigExterno a pSig
    void asignarSiguiente(Nodo_L* pSigExterno);

    // PRE: -
    // POST: Le asigna datoExterno a dato
    void asignarDato(Tipo datoExterno);

    // PRE: -
    // POST: Devuelve dato
    Tipo obtenerDato();

    // PRE: -
    // POST: Devuelve pSig
    Nodo_L* obtenerSiguiente();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Tipo>
Nodo_L<Tipo>:: Nodo_L(Tipo datoExterno) {
    dato = datoExterno;
    pSig = 0;
}

// <-------------------- Asignaciones
template <typename Tipo>
void Nodo_L<Tipo>:: asignarSiguiente(Nodo_L<Tipo>* pSigExterno) {
    pSig = pSigExterno;
}

template <typename Tipo>
Nodo_L<Tipo>* Nodo_L<Tipo>:: obtenerSiguiente() {
    return pSig;
}
// -------------------->

// <-------------------- Obtenciones
template <typename Tipo>
void Nodo_L<Tipo>:: asignarDato(Tipo datoExterno) {
    dato = datoExterno;
}

template <typename Tipo>
Tipo Nodo_L<Tipo>:: obtenerDato() {
    return dato;
}
// -------------------->
#endif //TP_FINAL_NODO_H
