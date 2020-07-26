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
    set< pair<int, int> > setDistancia;

    // Armo un vector con la distancia de todos los nodos
    // y pongo la distancia como infinito
    vector<int> distancias(vertices, INF);
    int sendero[vertices];
    sendero[origen] = -1;


    // Agregamos el comienzo en el set y seteamos la distancia como cero.
    setDistancia.insert(make_pair(0, origen));
    distancias[origen] = 0;

    // Buscamos las distancias de todos los vertices hasta que el set quede vacio.
    while (!setDistancia.empty())
    {
        // Borramos el primer vertice del set ya que es la distancia mas corta.
        pair<int, int> tmp = *(setDistancia.begin());
        setDistancia.erase(setDistancia.begin());

        int u = tmp.second;

        //Con i obtenemos todos los vertices adyacentes
        list< pair<int, int> >::iterator i;
        for (i = listaAristasCosto[u].begin(); i != listaAristasCosto[u].end(); ++i)
        {
            //Obtenemos nombre del vertice y su costo
            int v = (*i).first;
            int weight = (*i).second;

            //  si hay una arista mas corta de u a v.
            if (distancias[v] > distancias[u] + weight)
            {
                // Si la distancia no es infinito, ya fue procesada por nuestro proceso, asi que la quitamos del set
                if (distancias[v] != INF)
                    setDistancia.erase(setDistancia.find(make_pair(distancias[v], v)));

                // Agregamos la nueva distancia
                distancias[v] = distancias[u] + weight;

                sendero[v] = u;

                setDistancia.insert(make_pair(distancias[v], v));
            }
        }
    }

    imprimirResultado(distancias,sendero,origen,destino);

}

void Graph::encontrarSenderoMasRapido(int origen,int destino)
{
    //Creamos un set para procesar los vertices.
    set< pair<double, double> > setDistancia;

    // Armo un vector con la distancia de todos los nodos
    // y pongo la distancia como infinito
    vector<double> distancias(vertices, DINF);

    //Creamos el recorrido
    int sendero[vertices];
    //Seteamos en -1 para demostrar que es el origen
    sendero[origen] = -1;

    //Insertamos el origen en el set y lo ponemos como cero
    setDistancia.insert(make_pair(0, origen));
    distancias[origen] = 0;

    // Buscamos las distancias de todos los vertices hasta que el set quede vacio.
    while (!setDistancia.empty())
    {
        // Borramos el primer vertice del set ya que es la distancia mas corta.
        pair<double, double> tmp = *(setDistancia.begin());
        setDistancia.erase(setDistancia.begin());

        int u = tmp.second;

        //Con i obtenemos todos los vertices adyacentes
        list< pair<double, double> >::iterator i;
        for (i = listaAristasHoras[u].begin(); i != listaAristasHoras[u].end(); ++i)
        {
            //Obtenemos nombre del vertice y su costo
            int v = (*i).first;
            double weight = (*i).second;

            //  si hay una arista mas corta de u a v.
            if (distancias[v] > distancias[u] + weight)
            {
                // Si la distancia no es infinito, ya fue procesada por nuestro proceso, asi que la quitamos del set
                if (distancias[v] != DINF)
                    setDistancia.erase(setDistancia.find(make_pair(distancias[v], v)));

                // Agregamos la nueva distancia
                distancias[v] = distancias[u] + weight;

                sendero[v] = u;

                setDistancia.insert(make_pair(distancias[v], v));
            }
        }
    }

    imprimirResultadoHoras(distancias[destino],sendero,origen,destino);

}

void Graph::imprimirRecorrido(int sendero[], int j)
{

    // Si J es el comienzo
    if (sendero[j] == - 1)
        return;

    imprimirRecorrido(sendero, sendero[j]);

    printf("%d ", j);
}


void Graph::imprimirResultado(vector<int> distancia,int sendero[],int origen,int destino)
{
    printf("\nVertice\t Distancia\tSendero");
    printf("\n%d -> %d \t %d\t\t%d ",
           origen, destino, distancia[destino], origen);
    imprimirRecorrido(sendero,destino);

}

void Graph::imprimirResultadoHoras(double distancia,int sendero[],int origen,int destino)
{

    printf("\nVertice\t Distancia\tSendero");
    printf("\n%d -> %d \t %f\t%d ",
           origen, destino, distancia, origen);

    imprimirRecorrido(sendero,destino);

}