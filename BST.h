//
// Created by carolina on 3/6/20.
//

#include "Cola.h"
#include<iostream>

#ifndef ABB_BST_H
#define ABB_BST_H

template <class T>
class BST
{
private:
    // attributes
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
    //methods
    BST();

    // Creates an empty tree
    BST(BSTNode<T>* p_espacio);
    
    // Agrega un nuevo nodo al ABB actual. 
    // Si es el árbol está vacío, el nodo insertado será la raíz
    void insert(T data, Aeropuerto* p_aeropuerto);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void print_in_order();

    void print_width(BSTNode<T> * p_espacio);

    // Finds a given value in the BST. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool search(T data);
    
    BSTNode<T>* get_p_node(T data);

    // Finds the minimum value that exist in the BST.
    T find_min();

    // Finds the maximum value that exist in the BST.
    T find_max();

    // Finds the successor of a given data value.
    T successor(T data);

    // Finds the predecessor of a given data value.
    T predecessor(T data);

    // Removes a given data from the BST
    void remove(T data);

    BSTNode<T>* get_root();
    
    bool empty();

    // Deletes all the nodes in the BST
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

// ¿No hay que hacer aca una eliminacion, en bucle, de cada objeto en el heap al cual apuntan los punteros de los nodos del arbol?

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
    // Return the key. If the key is not found or successor is not found, return -1
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
            successor = ancestor; // so far this is the deepest node for which current node is in left
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
            // The only child will be connected to the parent's of node directly
            node->get_right()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_right();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<T>* aux = node;
            node = node->get_left();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->successor(data);

            // Replace node's key with successor's key
            node->set_data(successor_data);

            // Delete the old successor's key
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
