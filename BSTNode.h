#include<string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


# ifndef ABB_BSTNODE_H
# define  ABB_BSTNODE_H


template < class  T >
class  BSTNode
{
private:
  	 T* Datos;
    string clave;
    BSTNode <T> * left; 
    BSTNode <T> * right; 
    BSTNode <T> * padre;

public:
	
    BSTNode (T* datos,string clave); 
    
    
    string get_clave();
    T get_data ();
    void  set_data (T *datos);
    void  set_right (BSTNode <T> * right, BSTNode <T> * parent);
    void  set_left (BSTNode <T> * left, BSTNode <T> * parent);
    void  set_left (BSTNode <T> * left);
    void  set_right (BSTNode <T> * right);
    void  set_parent (BSTNode <T> * parent);
    BSTNode <T> * get_right ();
    BSTNode <T> * get_left ();
    BSTNode <T> * get_parent ();
    bool  isLeaf ();
    bool  rightChildOnly ();
    bool  leftChildOnly ();
};

template < class  T >

BSTNode <T> :: BSTNode (T* datos,string clave) 

{
    this -> datos = datos;
    this ->clave=clave;
    this -> left = NULL ;
    this -> right = NULL ;
    this -> padre = NULL ;
}

template < class  T >
T BSTNode <T> :: get_data ()
{
    return  this -> datos ;
}

template < class  T >
T BSTNode <T> :: get_clave ()
{
    return  this -> clave;
}


template < class  T >
void BSTNode <T> :: set_right (BSTNode <T> * right, BSTNode <T> * parent) {
    this -> right = right;
    this -> parent = parent;
}

template < class  T >
void BSTNode <T> :: set_right (BSTNode <T> * right) {
    this -> right = right;
}

template < class  T >
void BSTNode <T> :: set_left (BSTNode <T> * left, BSTNode <T> * parent) {
    this -> left = left;
    this -> parent = parent;
}

template < class  T >
void BSTNode <T> :: set_parent (BSTNode <T> * parent) {
    this -> parent = parent;
}

template < class  T >
void BSTNode <T> :: set_data (T* datos) {
    this -> datos = datos;
}


template < class  T >
void BSTNode <T> :: set_left (BSTNode <T> * left) {
    this -> left = left;
}

template < class  T >
BSTNode <T> * BSTNode <T> :: get_right ()
{
    return  this -> right ;
}

template < class  T >
BSTNode <T> * BSTNode <T> :: get_left ()
{
    return  this -> left ;
}

template < class  T >
BSTNode <T> * BSTNode <T> :: get_parent ()
{
    return  this -> parent ;
}

template < class  T >
bool BSTNode <T> :: isLeaf () {
    return ( this -> get_left () == NULL && this -> get_right () == NULL );
}

template < class  T >
bool BSTNode <T> :: rightChildOnly () {
    return ( this->get_left() == NULL && this->get_right()!=NULL);
}

template < class  T >
bool BSTNode <T> :: leftChildOnly () {
    return ( this->get_left ()!= NULL && this->get_right()==NULL);
}

# endif  // ABB_BSTNODE_H

