#include "Nodo.h"
#include <cmath>
#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

template<typename T>
class Cola
{
private:
// Primer elemento de la cola
Nodo<T>* primero;

// Ultimo elemento de la cola
Nodo<T>* ultimo;

public:
// Constructor
// PRE: ninguna
// POST: construye una cola vacía
// - primero y ultimo apuntan a nulo
Cola();

// Destructor
// PRE: cola creada
// POST: Libera todos los recursos de la cola
~Cola();

// ¿La cola es vacía?
// PRE: cola creada
// POST: devuelve verdadero si la cola es vacía
// falso de lo contrario
bool cola_vacia();

// Agregar un elemento a la cola
// PRE: cola creada
// POST: agrega un dato (dentro de un nodo) al final
void insert(T d);

// Obtener el dato que está al principio
// PRE: - cola creada y no vacía
// POST: devuelve el dato que está al principio
// creo que aca hay un error, porque supuestamente la cola almacena nodos que contienen datos. habria que revisar esto
T get_dato();

// Borrado del nodo que está al principio
// PRE: - cola creada y no vacía
// POST: libera el nodo que está al principio
void del_dato();

T pop();

void print_jump(float &cont, int &exp, int &n);

void print_tree();
};



//Constructor
template<typename T>
Cola<T>::Cola()
{
	primero = ultimo = 0;
}

//Destructor
template<typename T>
Cola<T>::~Cola()
{
	while (!(this->cola_vacia()))
	this->del_dato();
}

template<typename T>
bool Cola<T>::cola_vacia()
{
	return (primero == 0);
}

template<typename T>
void Cola<T>::insert(T d)
{
Nodo<T>* pnodo = new Nodo<T>(d);
	if (this->cola_vacia())
		primero = pnodo;
	else
		ultimo->set_sig(pnodo);
		ultimo = pnodo;
}

template<typename T>
T Cola<T>::get_dato()
{
	return primero->get_dato();
}

template<typename T>
void Cola<T>::del_dato()
{
	Nodo<T>* paux = primero;
	primero = paux->get_sig();
	delete paux;
}

template<typename T>
T Cola<T>::pop()
{
	T d_aux=primero->get_dato();
	Nodo<T>* paux = primero;
	primero = paux->get_sig();
	delete paux;
	return d_aux;
}

template<typename T>
void Cola<T>::print_jump(float &cont, int &exp, int &n){
	if(cont==(pow(2,exp))){
		n=(n-3)/2;
		cout<<endl;
		for(int i=0;i<((n-3)/2);i++){
			cout<<" ";
		}
		exp++;
		cont=0;
	}
}

template<typename T>
void Cola<T>::print_tree(){
	Nodo<T>* nodo_aux = primero;
	float cont=0.5;
	int exp=-1, n=189;
	while(nodo_aux->get_sig()){	
		print_jump(cont, exp, n);			
		cout<<nodo_aux->get_dato()->get_data();
		nodo_aux=nodo_aux->get_sig();
		for(int i=0;i<n;i++){
			cout<<" ";
		}
		cont++;
	}
	cout<<nodo_aux->get_dato()->get_data()<<endl;
}

#endif //COLA_H_INCLUDED

