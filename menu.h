# ifndef DIJKSTRA_MENU_H
# define  DIJKSTRA_MENU_H

# incluye  " Graph.h "

 Men� de clase {
private:
    char opcion;
    Graph * vuelos;

public:
    Men� (Gr�fico y grafo);
    void  mostrarMenu ();
    bool  selectorDeOpciones ();
    void  buscarVueloMasRapido ();
    void  buscarVueloMasBarato ();

};


# endif  // DIJKSTRA_MENU_H
