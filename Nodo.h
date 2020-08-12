#include"BSTNode.h"
#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
template < typename T >
class Nodo
{
private:
	T dato; // Dato a almacenar
	Nodo* psig; // Puntero a otro nodo

public:
	
// Constructor con parametro
// PRE: Ninguna
// POST: Crea un nodo con el dato d
// y el puntero a NULL
Nodo(T d);

// Destructor
// PRE: Nodo creado
// POST: No hace nada
~Nodo();

// Setea el dato (lo cambia)
// PRE: el nodo tiene que estar creado
// d tiene que ser un dato válido
// POST: el nodo queda con el dato d
void set_dato(T d);

// Setear el puntero al siguiente nodo
// PRE: nodo creado y ps válido
// POST: el puntero al siguiente apuntará a ps
void set_sig(Nodo<T>* ps);

// Obtener el dato
// PRE: nodo creado
// POST: devuelve el dato que contiene el nodo
T get_dato();

// Obtener el puntero al nodo siguiente
// PRE: nodo creado
// POST: Devuelve el puntero al siguiente nodo
// si es el último devuelve NULL
Nodo<T>* get_sig();

// ¿Hay un siguiente?
// PRE: nodo creado
// POST: V si tiene sig. F sino
bool tiene_sig();

};
// Constructor con parametro
template < typename T >
Nodo<T>::Nodo(T d)
{
	dato = d;
	psig = 0;
}

// Destructor
template < typename T >
Nodo<T>::~Nodo()
{
// No hace nada
}

// Setear el dato
template < typename T >
void Nodo<T>::set_dato(T d)
{
	dato = d;
}

// Setear el ptr al sig
template < typename T >
void Nodo<T>::set_sig(Nodo* ps)
{
	psig = ps;
}

// Devolver el dato
template < typename T>
T Nodo<T>::get_dato()
{
	return dato;
}

// Devolver el siguiente
template < typename T >
Nodo<T>* Nodo<T>::get_sig()
{
	return psig;
}

// Tiene siguiente?
template < typename T >
bool Nodo<T>::tiene_sig()
{
	return (psig != 0);
}
#endif // NODO_H_INCLUDED
