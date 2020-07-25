#ifndef DIJKSTRA_MENU_H
#define DIJKSTRA_MENU_H

#include "Graph.h"

class Menu{
private:
    char opcion;
    Graph *vuelos;

public:
    Menu(Graph& grafo);
    void mostrarMenu();
    bool selectorDeOpciones();
    void buscarVueloMasRapido();
    void buscarVueloMasBarato();

};


#endif //DIJKSTRA_MENU_H

