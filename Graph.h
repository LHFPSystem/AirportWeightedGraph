#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <string>
#include <list>
#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int vertices;
    int INF;
    double DINF;
    list<pair<int, int>> *listaAristasCosto;
    list<pair<double, double>> *listaAristasHoras;


public:
    Graph(int vertices);

    void agregarArista(int origen, int destino,int costo,double horas);
    void encontrarSenderoMasBarato(int origen,int destino);
    void encontrarSenderoMasRapido(int origen,int destino);
    void imprimirResultado(vector<int> dist,int parent[],int origen,int destino);
    void imprimirResultadoHoras(double dist,int parent[],int origen,int destino);
    void imprimirRecorrido(int parent[], int j);



};

#endif //DIJKSTRA_GRAPH_H
