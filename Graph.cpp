#include "Graph.h"
#include <iostream>


Graph::Graph(int vertices) {

    listaAristasCosto = new list<pair<int, int>>[vertices];
    listaAristasHoras = new list<pair<double,double>>[vertices];
    this->INF=0;
    this->vertices = vertices;

}

void Graph::agregarArista(int origen, int destino,int costo, double horas){

    listaAristasCosto[origen].push_back(make_pair(destino, costo));
    listaAristasCosto[destino].push_back(make_pair(origen, costo));
    listaAristasHoras[origen].push_back(make_pair(destino, horas));
    listaAristasHoras[destino].push_back(make_pair(origen, horas));
    this->INF += costo*10;
    this->DINF += horas*5;

}

void Graph::encontrarSenderoMasBarato(int origen,int destino)
{
    //Creamos un set para procesar los vertices.
    set< pair<int, int> > setds;

    // Armo un vector con la distancia de todos los nodos
    // y pongo la distancia como infinito
    vector<int> dist(vertices, INF);
    int parent[vertices];
    parent[origen] = -1;


    // Agregamos el comienzo en el set y seteamos la distancia como cero.
    setds.insert(make_pair(0, origen));
    dist[origen] = 0;

    // Buscamos las distancias de todos los vertices hasta que el set quede vacio.
    while (!setds.empty())
    {
        // Borramos el primer vertice del set ya que es la distancia mas corta.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;

        //Con i obtenemos todos los vertices adyacentes
        list< pair<int, int> >::iterator i;
        for (i = listaAristasCosto[u].begin(); i != listaAristasCosto[u].end(); ++i)
        {
            //Obtenemos nombre del vertice y su costo
            int v = (*i).first;
            int weight = (*i).second;

            //  si hay una arista mas corta de u a v.
            if (dist[v] > dist[u] + weight)
            {
                // Si la distancia no es infinito, ya fue procesada por nuestro proceso, asi que la quitamos del set
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Agregamos la nueva distancia
                dist[v] = dist[u] + weight;

                parent[v] = u;

                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    imprimirResultado(dist,parent,origen,destino);

}

void Graph::encontrarSenderoMasRapido(int origen,int destino)
{
    //Creamos un set para procesar los vertices.
    set< pair<double, double> > setds;

    // Armo un vector con la distancia de todos los nodos
    // y pongo la distancia como infinito
    vector<double> dist(vertices, DINF);

    //Creamos el recorrido
    int parent[vertices];
    //Seteamos en -1 para demostrar que es el origen
    parent[origen] = -1;

    //Insertamos el origen en el set y lo ponemos como cero
    setds.insert(make_pair(0, origen));
    dist[origen] = 0;

    // Buscamos las distancias de todos los vertices hasta que el set quede vacio.
    while (!setds.empty())
    {
        // Borramos el primer vertice del set ya que es la distancia mas corta.
        pair<double, double> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;

        //Con i obtenemos todos los vertices adyacentes
        list< pair<double, double> >::iterator i;
        for (i = listaAristasHoras[u].begin(); i != listaAristasHoras[u].end(); ++i)
        {
            //Obtenemos nombre del vertice y su costo
            int v = (*i).first;
            double weight = (*i).second;

            //  si hay una arista mas corta de u a v.
            if (dist[v] > dist[u] + weight)
            {
                // Si la distancia no es infinito, ya fue procesada por nuestro proceso, asi que la quitamos del set
                if (dist[v] != DINF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Agregamos la nueva distancia
                dist[v] = dist[u] + weight;

                parent[v] = u;

                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    imprimirResultadoHoras(dist[destino],parent,origen,destino);

}

void Graph::imprimirRecorrido(int parent[], int j)
{

    // Si J es el comienzo
    if (parent[j] == - 1)
        return;

    imprimirRecorrido(parent, parent[j]);

    printf("%d ", j);
}


void Graph::imprimirResultado(vector<int> dist,int parent[],int origen,int destino)
{
    printf("\nVertice\t Distancia\tSendero");
    printf("\n%d -> %d \t %d\t\t%d ",
           origen, destino, dist[destino], origen);
    imprimirRecorrido(parent,destino);

}

void Graph::imprimirResultadoHoras(double dist,int parent[],int origen,int destino)
{

    printf("\nVertice\t Distancia\tSendero");
    printf("\n%d -> %d \t %f\t%d ",
           origen, destino, dist, origen);

    imprimirRecorrido(parent,destino);

}