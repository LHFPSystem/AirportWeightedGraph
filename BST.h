#include "BSTNode.h"
#include "Cola.h"
#include<iostream>

#ifndef ABB_BST_H
#define ABB_BST_H

template <class T>
class BST
{
private:
    // atributos
    BSTNode<T>* root;

    // methods
    BSTNode<T>* insert(BSTNode<T>* node, T data, Aeropuerto* p_aeropuerto);
    void print_width(BSTNode<T>* node, BSTNode<T> *p_espacio);
    void print_in_order(BSTNode<T> * node);
    BSTNode<T>* search(BSTNode<T>* node, T data);
    T find_min(BSTNode<T>* node);
    T find_max(BSTNode<T>* node);
    T successor(BSTNode<T>* node);
    T predecessor(BSTNode<T>* node);
    BSTNode<T>* remove(BSTNode<T>* node, T data);
    void delete_all(BSTNode<T>* node);

public:
    //metodos
    BST();

	// Crea un arbol vacio.
    BST(BSTNode<T>* p_espacio);
    
    // Agrega un nuevo nodo al ABB actual. 
    // Si es el árbol está vacío, el nodo insertado será la raíz
    void insert(T data, Aeropuerto* p_aeropuerto);

	// Imprime todas las claves segun el recorrido inorden.
    void print_in_order();

	//Imprime las claves segun el recorrido en anchura nivel por nivel
    void print_width(BSTNode<T> * p_espacio);

    // Busca un valor dado en la BST.Si la clave existe devuelve verdadero de lo contrario devuelve falso.
    bool search(T data);
    
    //Devuelve un puntero a un nodo del arbol llama al metodo buscar y le pasa la raiz del arbol
    BSTNode<T>* get_p_node(T data);

	// Encuentra el valor minima que existe en la BST.
    T find_min();

	// Encuentra el valor minima que existe en la BST.
    T find_max();
    
	//Encuentra el sucesor de un valor de datos dado.
    T successor(T data);

	//Encuentra el predecessor de un valor de datos dado.
    T predecessor(T data);

    //Elimina un dato dado de la BST.
    void remove(T data);

	//Devuelve la raiz del arbol.
    BSTNode<T>* get_root();
    
	//Devuelve verdadero si el arbol esta vacio.
	bool empty();

	//Borra todos los nodos de BST.
    void delete_all();
    ~BST<T>();

};

template <class T>
BST<T>::BST() {
    this->root = NULL;
}

template <class T>
BST<T>::BST(BSTNode<T>* p_espacio) {
    this->root = NULL;
    this->p_espacio=p_espacio;
}


template <class T>
BSTNode<T>* BST<T>::insert(BSTNode<T>* node, T data, Aeropuerto* p_aeropuerto) {

	if (node == NULL) {
        node = new BSTNode<T>(data, p_aeropuerto);
    }

    else if (data > node->get_data()) {
        node->set_right(insert(node->get_right(), data, p_aeropuerto), node);
    }

    else {
        node->set_left(insert(node->get_left(), data, p_aeropuerto), node);
    }
    return node;
}

template <class T>
void BST<T>::insert(T data, Aeropuerto* p_aeropuerto)
{	
	this->root = insert(this->root, data, p_aeropuerto);
}

template <class T>
void BST<T>::print_width(BSTNode<T>* p_espacio){
    this->print_width(this->root, p_espacio);
}

template <class T>
void BST<T>::print_width(BSTNode<T>* node, BSTNode<T>* p_espacio){
    Cola<BSTNode<T>*> cola, cola_aux;
    BSTNode<T>* nodo_aux;

    if(node!=NULL){
    	
        cola.insert(node);
        int cont=1;
        
        while(!(cola.cola_vacia()) && cont<=31){
            cola_aux.insert(nodo_aux=cola.pop());
            if(nodo_aux->get_left()!=NULL){
                cola.insert(nodo_aux->get_left());
            }else{
            	cola.insert(p_espacio);				
			}
            if(nodo_aux->get_right()!=NULL){
                cola.insert(nodo_aux->get_right());
            }else{
            	cola.insert(p_espacio);				
			}
			cont++;      
        }
        cola_aux.print_tree();
    }
}

template <class T>
void BST<T>::print_in_order(BSTNode<T>* node)
{
    if (node != NULL)
    {
        print_in_order(node->get_left());
        std::cout<<node->get_data()<<" ("<<(node->get_p_aeropuerto())->get_nombre()<<")"<<endl;
        print_in_order(node->get_right());
    }
}

template <class T>
void BST<T>::print_in_order()
{
    this->print_in_order(this->root);
}

template <class T>
BSTNode<T>* BST<T>::search(BSTNode<T>* node, T data)
{   // si el nodo que ingresa (raiz en successor) está vacio o es el mismo dato ingresado, retorna ese nodo, (raiz)
    if (node == NULL || node->get_data() == data)
        return node;

    if (data > node->get_data())
        return search(node->get_right(), data);

    return search(node->get_left(), data);
}

template <class T>
bool BST<T>::search(T data)
{
    BSTNode<T>* result = search(this->root, data);

    return result != NULL;
}

template <class T>
BSTNode<T>* BST<T>::get_p_node(T data)
{
    BSTNode<T>* result = search(this->root, data);

    return result;
}

template <class T>
T BST<T>::find_min(BSTNode<T>* node)
{
    if(node == NULL)
        return NULL;
    else if(node->get_left() == NULL)
        return node->get_data();
    else
        return find_min(node->get_left());
}

template <class T>
T BST<T>::find_min()
{
    return find_min(this->root);
}

template <class T>
T BST<T>::find_max(BSTNode<T>* node)
{
    if(node == NULL)
        return -1;
    else if(node->get_right() == NULL)
        return node->get_data();
    else
        return find_max(node->get_right());
}

template <class T>
T BST<T>::find_max()
{
    return find_max(this->root);
}

template <class T>
T BST<T>::successor(BSTNode<T>* node)
{   // si el nodo tiene hijo derecho, devuelve el minimo desde ese hijo
    if (node->get_right() != NULL)
    {
        return find_min(node->get_right());
    }
    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_data() < ancestor->get_data()) {
            successor = ancestor;
            ancestor = ancestor->get_left();
        }
        else
            ancestor = ancestor->get_right();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::successor(T data)
{
    BSTNode<T>* data_node = this->search(this->root, data);
    //Devuelve la clave. Si la clave no es encontrada, devuelve -1.
    
    if(data_node == NULL)
        return NULL;
                // este usa un puntero a nodo, por ende es el metodo privado
    else return successor(data_node);
}

template <class T>
T BST<T>::predecessor(BSTNode<T> * node)
{
    if (node->get_left() != NULL)
    {
        return find_max(node->get_left());
    }

    BSTNode<T>* successor = NULL;
    BSTNode<T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_data() > ancestor->get_data()) {
        	
            successor = ancestor; //Hasta ahora, este es el nodo mas profundo para el que el nodo actual está a la izquierda.
            ancestor = ancestor->get_right();
        }
        else
            ancestor = ancestor->get_left();
    }
    return successor->get_data();
}

template <class T>
T BST<T>::predecessor(T data)
{   // crea un puntero a nodo que tendra la direccion de un nodo con el dato buscado
    BSTNode<T> * data_node = this->search(this->root, data);
    // si no lo encuentra...
    if(data_node == NULL)
        return NULL;
    else return predecessor(data_node);
}

template <class T>
BSTNode<T> * BST<T>::remove(BSTNode<T>* node, T data)
{
    // The given node is not found in BST
    if (node == NULL)
        return NULL;

    if (node->get_data() == data)
    {
        if (node->isLeaf())
            delete node;
        else if (node->rightChildOnly())
        {
            //El unico hijo se conectara directamente al padre del nodo
            node->get_right()->set_parent(node->get_parent());
            // Nodo auxiliar
            BSTNode<T>* aux = node;
            node = node->get_right();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            //El unico hijo se conectará directamente al padre del nodo
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_left();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Encuentra sucesor o predecesor
            T successor_data = this->successor(data);

            // Reemplazar la clave del nodo con la clave del sucesor
            node->set_data(successor_data);

            // Eliminar la clave anterior del sucesor
            node->set_right(remove(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(remove(node->get_right(), data));

    else
        node->set_left(remove(node->get_left(), data));

    return node;
}

template <class T>
void BST<T>::remove(T data)
{
    this->root = remove(this->root, data);
}

template <class T>
BSTNode<T>* BST<T>::get_root(){
    return this->root;
}

template <class T>
bool BST<T>::empty()
{
    return this->root == NULL;
}


template <class T>
void BST<T>::delete_all(BSTNode<T>* node)
{
    if(node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node;
}

template <class T>
void BST<T>::delete_all()
{
    this->delete_all(this->root);
}

template <class T>
BST<T>::~BST<T>()
{
    this->delete_all();
}


#endif //ABB_BST_H
