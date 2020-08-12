# ifndef TP_FINAL_DICCIONARIO_H
# define  TP_FINAL_DICCIONARIO_H

# include < iostream >
# include  " BST.h "

using namespace std;
class  Diccionario {
private:
	BSTNode<Aeropuerto,string>* node;
	Aeropuerto* data;
	T clave;
	BST<Aeropuerto,clave>* bst;

public:

    Diccionario (BST <Aeropuerto,string> & diccionario);
    void agregarclave(BSTNode<Aeropuerto,string>* node);
    void agregaraeropuerto(BSTNode<Aeropuerto,string>* node);
    void borraraeropuerto(BST<Aeropuerto,clave>* bst,BSTNode<Aeropuerto,string>* node);
    void mostrarenorden(BST<Aeropuerto,clave>* bst);
    void mostrarenancho(BST<Aeropuerto,clave>* bst);
    void insertarnodo(Aeropuerto* data,T clave);

};

# endif  // TP_FINAL_DICCIONARIO_H
