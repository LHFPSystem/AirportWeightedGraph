#include "Graph.h"
#include <iostream>


Graph::Graph(int vertices) {

    listaAristasCosto = new list<pair<int, int>>[vertices];
    listaAristasHoras = new list<pair<double,double>>[vertices];
    this->INF=0;
    this->vertices = vertices;

}

bool Graph::agregarArista(int origen, int destino,int costo, double horas){

    listaAristasCosto[origen].push_back(make_pair(destino, costo));
    listaAristasCosto[destino].push_back(make_pair(origen, costo));
    listaAristasHoras[origen].push_back(make_pair(destino, horas));
    listaAristasHoras[destino].push_back(make_pair(origen, horas));
    this->INF += costo*10;
    this->DINF += horas*5;

}

void Graph::encontrarSenderoMasBarato(int origen,int destino)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, int> > setds;

    // Armo un vector con la distancia de todos los nodos
    // y pongo la distancia como infinito
    vector<int> dist(vertices, INF);
    int parent[vertices];
    parent[origen] = -1;


    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, origen));
    dist[origen] = 0;

    /* Looping till all shortest distance are finalized
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = listaAristasCosto[u].begin(); i != listaAristasCosto[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
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
    // Create a set to store vertices that are being
    // prerocessed
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

    /* Looping till all shortest distance are finalized
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<double, double> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<double, double> >::iterator i;
        for (i = listaAristasHoras[u].begin(); i != listaAristasHoras[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            double weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != DINF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
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

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    imprimirRecorrido(parent, parent[j]);

    printf("%d ", j);
}


int Graph::imprimirResultado(vector<int> dist,int parent[],int origen,int destino)
{
    printf("\nVertice\t Distancia\tSendero");
    printf("\n%d -> %d \t %d\t\t%d ",
           origen, destino, dist[destino], origen);
    imprimirRecorrido(parent,destino);

}

int Graph::imprimirResultadoHoras(double dist,int parent[],int origen,int destino)
{

    printf("\nVertice\t Distancia\tSendero");
    printf("\n%d -> %d \t %f\t%d ",
           origen, destino, dist, origen);

    imprimirRecorrido(parent,destino);

}