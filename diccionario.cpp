#include<iostream>
#include<iostream>

#include "aeropuerto.h"

#include "BSTNode.h"
#include "BST.h"
#include "aeropuerto.h"

using namespace std;

void Diccionario::Diccionario(BST<Aeropuerto,string> &diccionario){
    Aeropuerto *aeropuerto;
    string registro;
    double superficie;
    int entero;
    BSTNode<Aeropuerto,string>* node;
    string clave;
    
    

    ifstream arch("aeropuerto.txt");

    while(!arch.eof()){

        aeropuerto = new Aeropuerto;

        //Carga Codigo IATA
        arch>>registro;
        clave=registro;
        aeropuerto->cargarCodigoIATA(registro);
        node->clave=registro;

        //Carga Nombre
        arch>>registro;
        aeropuerto->cargarNombre(registro);
        node->Dato->nombre=aeropuerto->get_nombre();

        //Carga Ciudad
        arch>>registro;
        aeropuerto->cargarCiudad(registro);
        node->Dato->nombre=aeropuerto->get_ciudad();

        //Carga Pais
        arch>>registro;
        aeropuerto->cargarPais(registro);
        node->Dato->nombre=aeropuerto->get_pais();

        //Carga Superficie
        arch>>registro;
        superficie=atof(registro.c_str());
        aeropuerto->cargarSuperficie(superficie);
        node->Dato->nombre=aeropuerto->get_superficie();

        //Carga Terminales
        arch>>registro;
        entero=atoi(registro.c_str());
        aeropuerto->cargarCantidadTerminales(entero);
        node->Dato->nombre=aeropuerto->get_terminales();

        //Carga Destino Nacionales
        arch>>registro;
        entero=atoi(registro.c_str());
        aeropuerto->cargarDestinosNacionales(entero);
        node->Dato->nombre=aeropuerto->get_d_nacionales();

        //Carga Destino Nacionales
        arch>>registro;
        entero=atoi(registro.c_str());
        aeropuerto->cargarDestinoInternacionales(entero);
        node->Dato->nombre=aeropuerto->get_d_internacionales();

        bst->insert(aeropuerto,clave);
        
        
    }
    arch.close();
    
    void Diccionario::agregarclave(BSTNode<Aeropuerto,string>* node){
    	string clave;
    	cin>>clave;
    	node->clave=clave;
	}
    
    
    
    
    void Diccionario::agregaraeropuerto()
    {
    	string aeropuerto;
    	cin>>aeropuerto;
    	node->Dato->nombre=aeropuerto;
    	
	}
    
    void Diccionario::borraraeropuerto(BST<Aeropuerto,clave>* bst,BSTNode<Aeropuerto,string>* node){
    	cout<<"Ingrese la clave del aeropuerto"<<endl;
    	cin>>clave;
    	bst-> remove(clave);
	}
	
    void Diccionario::mostrarenorden(BST<Aeropuerto,clave>* bst){
    	bst->print_in_order();
	}
    void Diccionario::mostrarenancho(BST<Aeropuerto,clave>* bst){
    	
	}

    
    
    
    
    
}


