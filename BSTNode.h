
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>



#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H
#include "Aeropuerto.h"

template <class T>
class BSTNode
{
private:
    T data;
    Aeropuerto* p_aeropuerto;
    BSTNode<T>* left; //Hijo izquierdo
    BSTNode<T>* right; //Hijo derecho
    BSTNode<T>* parent;

public:
	//POST: Crea un nodo seteando los atributos.
    BSTNode(T data, Aeropuerto* p_aeropuerto);
    
    //PRE:
    //POST:Devuelve el dato.
    T get_data();
    
	//PRE:
    //POST:Devuelve un puntero a aeropuerto.
    Aeropuerto* get_p_aeropuerto();
    
    //PRE:
    //POST:Setea el dato y aeropuerto.
    void set_data(T data, Aeropuerto* p_aeropuerto);
    
    //PRE:
    //POST:Setea el dato.
    void set_data(T data);
    
    //PRE:
    //POST:Setea el hijo derecho y el padre.
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);
    
    //PRE:
    //POST:Setea el hijo izquierdo y el padre.
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);
    
    //PRE:
    //POST:Setea el hijo izquierdo.
    void set_left(BSTNode<T>* left);
    
    //PRE:
    //POST:Setea el hijo derecho.
    void set_right(BSTNode<T>* right);
    
     //PRE:
    //POST:Setea el padre.
    void set_parent(BSTNode<T>* parent);
    
    //PRE:
    //POST:Devuelve un puntero a nodo derecho.
    BSTNode<T>* get_right();
    
    //PRE:
    //POST:Devuelve un puntero a nodo izquierdo.
    BSTNode<T>* get_left();
    
    //PRE:
    //POST:Devuelve un puntero al nodo padre
    BSTNode<T>* get_parent();
    
    //PRE:
    //POST:Si es hoja (no tiene hijos) devuelve true sino falso
    bool isLeaf();
    
    //PRE:
    //POST:Si tiene solo hijo a la derecha devuelve true sino falso
    bool rightChildOnly();
    
    //PRE:
    //POST:Si tiene solo hijo a la izquierdo devuelve true sino falso
    bool leftChildOnly();
};

template <class T>
BSTNode<T>::BSTNode(T data, Aeropuerto* p_aeropuerto)
{
    this->data = data;
    this->p_aeropuerto=p_aeropuerto;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

template <class T>
T BSTNode<T>::get_data()
{
    return this->data;
}

template <class T>
Aeropuerto* BSTNode<T>::get_p_aeropuerto()
{
    return this->p_aeropuerto;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right, BSTNode<T>* parent){
    this->right = right;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_right(BSTNode<T>* right){
    this->right = right;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left, BSTNode<T>* parent){
    this->left = left;
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_left(BSTNode<T>* left){
    this->left = left;
}

template <class T>
void BSTNode<T>::set_parent(BSTNode<T> *parent) {
    this->parent = parent;
}

template <class T>
void BSTNode<T>::set_data(T data, Aeropuerto* p_aeropuerto) {
    this->data = data;
    this->p_aeropuerto=p_aeropuerto;
}

template <class T>
void BSTNode<T>::set_data(T data) {
    this->data = data;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_right()
{
    return this->right;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_left()
{
    return this->left;
}

template <class T>
BSTNode<T>* BSTNode<T>::get_parent()
{
    return this->parent;
}

template <class T>
bool BSTNode<T>::isLeaf() {
    return (this->get_left() == NULL && this->get_right() == NULL);
}

template <class T>
bool BSTNode<T>::rightChildOnly() {
    return (this->get_left() == NULL && this->get_right() != NULL);
}

template <class T>
bool BSTNode<T>::leftChildOnly() {
    return (this->get_left() != NULL && this->get_right() == NULL);
}

#endif //ABB_BSTNODE_H
