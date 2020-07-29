#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//
// Created by carolina on 3/6/20.
//

#ifndef ABB_BSTNODE_H
#define ABB_BSTNODE_H
#include "Aeropuerto.h"

template <class T>
class BSTNode
{
private:
    T data;
    Aeropuerto* p_aeropuerto;
    BSTNode<T>* left; //Left children
    BSTNode<T>* right; //Right children
    BSTNode<T>* parent;

public:
    BSTNode(T data, Aeropuerto* p_aeropuerto);
    T get_data();
    Aeropuerto* get_p_aeropuerto();
    void set_data(T data, Aeropuerto* p_aeropuerto);
    void set_right(BSTNode<T>* right, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left, BSTNode<T>* parent);
    void set_left(BSTNode<T>* left);
    void set_right(BSTNode<T>* right);
    void set_parent(BSTNode<T>* parent);
    BSTNode<T>* get_right();
    BSTNode<T>* get_left();
    BSTNode<T>* get_parent();
    bool isLeaf();
    bool rightChildOnly();
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

