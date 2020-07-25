#include "Graph.h"
#include "Menu.h"
#include <iostream>
using namespace std;

int main(){



    Graph g(9);
    g.agregarArista(0,1,4,4);
    g.agregarArista(0,1,4,4);
    g.agregarArista(0, 7, 8,8);
    g.agregarArista(1, 2, 8,8);
    g.agregarArista(1, 7, 11,8);
    g.agregarArista(2, 3, 7,8);
    g.agregarArista(2, 8, 2,8);
    g.agregarArista(2, 5, 4,8);
    g.agregarArista( 3, 4, 9,8);
    g.agregarArista( 3, 5, 14,14);
    g.agregarArista(4, 5, 10,5);
    g.agregarArista(5, 6, 2,4);
    g.agregarArista(6, 7, 1,2.3);
    g.agregarArista(6, 8, 6,3);
    g.agregarArista(7, 8, 7,14.5);

    Menu menu(g);
    menu.mostrarMenu();
    while(menu.selectorDeOpciones()){
        menu.mostrarMenu();
    }


    g.encontrarSenderoMasBarato(1,5);
    g.encontrarSenderoMasRapido(1,8);


    return 0;
}