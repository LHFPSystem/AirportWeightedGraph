
#include<string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include"aeropuerto.h"

using namespace std;


# ifndef ABB_BSTNODE_H
# define  ABB_BSTNODE_H


template <class  Aeropuerto,class T>
class  BSTNode
{
private:
  	Aeropuerto* Datos;
    T clave;
    BSTNode <Aeropuerto,T> * left; 
    BSTNode <Aeropuerto,T> * right; 
    BSTNode <Aeropuerto,T> * parent;

public:
	
    BSTNode (Aeropuerto* datos,T clave); 
    
    
    T get_clave();
    Aeropuerto* get_data ();
    void  set_clave (T clave);
    void  set_right (BSTNode <Aeropuerto,T> * right, BSTNode <Aeropuerto,T> * parent);
    void  set_left (BSTNode <Aeropuerto,T> * left, BSTNode <Aeropuerto,T> * parent);
    void  set_left (BSTNode <Aeropuerto,T> * left);
    void  set_right (BSTNode <Aeropuerto,T> * right);
    void  set_parent (BSTNode <Aeropuerto,T> * parent);
    BSTNode <Aeropuerto,T> * get_right ();
    BSTNode <Aeropuerto,T> * get_left ();
    BSTNode <Aeropuerto,T> * get_parent ();
    bool  isLeaf ();
    bool  rightChildOnly ();
    bool  leftChildOnly ();
};

template < class  Aeropuerto,class T>

BSTNode <Aeropuerto,T> :: BSTNode (Aeropuerto* datos,T clave) 

{
    this -> Datos = datos;
    this ->clave=clave;
    this -> left = NULL ;
    this -> right = NULL ;
    this -> parent = NULL ;
}

template <class  Aeropuerto,class T>

Aeropuerto* BSTNode <Aeropuerto,T> :: get_data ()
{
    return  this->Datos ;
}

template < class  Aeropuerto,class T>
T BSTNode <Aeropuerto,T> :: get_clave ()
{
    return  this -> clave;
}


template < class  Aeropuerto,class T>
void BSTNode <Aeropuerto,T> :: set_right (BSTNode <Aeropuerto,T> * right, BSTNode <Aeropuerto,T> * parent) {
    this -> right = right;
    this -> parent = parent;
}

template < class  Aeropuerto,class T>
void BSTNode <Aeropuerto,T> :: set_right (BSTNode <Aeropuerto,T> * right) {
    this -> right = right;
}

template < class  Aeropuerto,class T>
void BSTNode <Aeropuerto,T> :: set_left (BSTNode <Aeropuerto,T> * left, BSTNode <Aeropuerto,T> * parent) {
    this -> left = left;
    this -> parent = parent;
}

template < class  Aeropuerto,class T>
void BSTNode <Aeropuerto,T> :: set_parent (BSTNode <Aeropuerto,T> * parent) {
    this -> parent = parent;
}

template < class  Aeropuerto,class T>
void BSTNode <Aeropuerto,T> :: set_clave (T clave) {
    this -> clave = clave;
}


template < class  Aeropuerto,class T >
void BSTNode <Aeropuerto,T> :: set_left (BSTNode <Aeropuerto,T> * left) {
    this -> left = left;
}

template < class  Aeropuerto,class T>
BSTNode <Aeropuerto,T> * BSTNode <Aeropuerto,T> :: get_right ()
{
    return  this -> right ;
}

template < class  Aeropuerto,class T>
BSTNode <Aeropuerto,T> * BSTNode <Aeropuerto,T> :: get_left ()
{
    return  this -> left ;
}

template < class  Aeropuerto,class T>
BSTNode <Aeropuerto,T> * BSTNode <Aeropuerto,T> :: get_parent ()
{
    return  this -> parent ;
}

template < class  Aeropuerto,class T>
bool BSTNode <Aeropuerto,T> :: isLeaf () {
    return ( this -> get_left () == NULL && this -> get_right () == NULL );
}

template < class  Aeropuerto,class T>
bool BSTNode <Aeropuerto,T> :: rightChildOnly () {
    return ( this->get_left() == NULL && this->get_right()!=NULL);
}

template < class  Aeropuerto,class T>
bool BSTNode <Aeropuerto,T> :: leftChildOnly () {
    return ( this->get_left ()!= NULL && this->get_right()==NULL);
}

# endif  // ABB_BSTNODE_H

