#include "BSTNode.h"
#include<iostream>

#ifndef ABB_BST_H
#define ABB_BST_H

template <class Aeropuerto,class T>
class BST
{
private:
    // attributes
    BSTNode<Aeropuerto,T>* root;

    // methods
    BSTNode<Aeropuerto,T>* insert(BSTNode<Aeropuerto,T>* node, Aeropuerto* data,T clave);
    void print_in_order(BSTNode<Aeropuerto,T> * node);
    BSTNode<Aeropuerto,T>* search(BSTNode<Aeropuerto,T>* node,Aeropuerto*data,T clave);
    T find_min(BSTNode<Aeropuerto,T>* node);
    T find_max(BSTNode<Aeropuerto,T>* node);
    T successor(BSTNode<Aeropuerto,T>* node);
    T predecessor(BSTNode<Aeropuerto,T>* node);
    BSTNode<Aeropuerto,T>* remove(BSTNode<Aeropuerto,T>* node,T clave);
    void delete_all(BSTNode<Aeropuerto,T>* node);

public:
    //methods

    // Creates an empty tree
    BST();

     // Adds a new node to the actual BST. If its the tree is empty
     // the node inserted will be the root
    void insert(Aeropuerto* data,T clave);

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void print_in_order();

    // Finds a given value in the BST. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool search(T clave);

    // Finds the minimum value that exist in the BST.
    T find_min();

    // Finds the maximum value that exist in the BST.
    T find_max();

    // Finds the successor of a given data value.
    T successor(T clave);

    // Finds the predecessor of a given data value.
    T predecessor(T clave);

    // Removes a given data from the BST
    void remove(T clave);

    BSTNode<Aeropuerto,T>* get_root();
    bool empty();

    // Deletes all the nodes in the BST
    void delete_all();
    ~BST<Aeropuerto,T>();

};

template <class Aeropuerto,class T>
BST<Aeropuerto,T>::BST() {
    this->root = NULL;
}

template <class Aeropuerto,class T>
BSTNode<Aeropuerto,T>* BST<Aeropuerto,T>::insert(BSTNode<Aeropuerto,T>* node, Aeropuerto* data,T clave) {

    if (node == NULL) {
        node = new BSTNode<Aeropuerto,T>(data,clave);
    }

    else if (clave > node->get_clave()) {
        node->set_right(insert(node->get_right(), data,clave), node);
    }

    else {
        node->set_left(insert(node->get_left(), data,clave), node);
    }
    return node;
}

template <class Aeropuerto,class T>
void BST<Aeropuerto,T>::insert(Aeropuerto* data,T clave)
{
    this->root = insert(this->root, data,clave);
}

template <class Aeropuerto,class T>
void BST<Aeropuerto,T>::print_in_order(BSTNode<Aeropuerto,T>* node)
{
    if (node != NULL)
    {
        print_in_order(node->get_left());
        
        std::cout<<"El codigo IATA es:"<<node->get_clave()<<endl;
        print_in_order(node->get_right());
    }
}

template <class Aeropuerto,class T>
void BST<Aeropuerto,T>::print_in_order()
{
    this->print_in_order(this->root);
}

template <class Aeropuerto,class T>
BSTNode<Aeropuerto,T>* BST<Aeropuerto,T>::search(BSTNode<Aeropuerto,T>* node,Aeropuerto* data,T clave)
{
    if (node == NULL || node->get_clave() == clave)
        return node;

    if (data > node->get_clave())
        return search(node->get_right(), clave);

    return search(node->get_left(), clave);
}

template <class Aeropuerto,class T>
bool BST<Aeropuerto,T>::search(T clave)
{
    BSTNode<Aeropuerto,T>* result = search(this->root, clave);

    return result != NULL;
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::find_min(BSTNode<Aeropuerto,T>* node)
{
    if(node == NULL)
        return -1;
    else if(node->get_left() == NULL)
        return node->get_clave();
    else
        return find_min(node->get_left());
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::find_min()
{
    return find_min(this->root);
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::find_max(BSTNode<Aeropuerto,T>* node)
{
    if(node == NULL)
        return -1;
    else if(node->get_right() == NULL)
        return node->get_clave();
    else
        return find_max(node->get_right());
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::find_max()
{
    return find_max(this->root);
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::successor(BSTNode<Aeropuerto,T>* node)
{
    if (node->get_right() != NULL)
    {
        return find_min(node->get_right());
    }
    BSTNode<Aeropuerto,T>* successor = NULL;
    BSTNode<Aeropuerto,T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_clave() < ancestor->get_clave()) {
            successor = ancestor;
            ancestor = ancestor->get_left();
        }
        else
            ancestor = ancestor->get_right();
    }
    return successor->get_clave();
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::successor(T clave)
{
    BSTNode<Aeropuerto,T>* clave_node = this->search(this->root, clave);
    // Return the key. If the key is not found or successor is not found, return -1
    if(clave_node == NULL)
       return -1;
    else return successor(clave_node);
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::predecessor(BSTNode<Aeropuerto,T> * node)
{
    if (node->get_left() != NULL)
    {
        return find_max(node->get_left());
    }

    BSTNode<Aeropuerto,T>* successor = NULL;
    BSTNode<Aeropuerto,T>* ancestor = this->root;
    while(ancestor != node) {
        if(node->get_clave() > ancestor->get_clave()) {
            successor = ancestor; // so far this is the deepest node for which current node is in left
            ancestor = ancestor->get_right();
        }
        
        
        else
            ancestor = ancestor->get_left();
    }
    return successor->get_clave();
}

template <class Aeropuerto,class T>
T BST<Aeropuerto,T>::predecessor(T clave)
{
    BSTNode<Aeropuerto,T> * clave_node = this->search(this->root, clave);

    if( clave_node== NULL)
        return -1;
    else return predecessor(clave_node);
}

template <class Aeropuerto,class T>
BSTNode<Aeropuerto,T> * BST<Aeropuerto,T>::remove(BSTNode<Aeropuerto,T>* node,T clave)
{
    // The given node is not found in BST
    if (node == NULL)
        return NULL;

    if (node->get_clave() == clave)
    {
        if (node->isLeaf())
            delete node;
        else if (node->rightChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_right()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<Aeropuerto,T>* aux = node;
            node = node->get_right();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            BSTNode<Aeropuerto,T>* aux = node;
            node = node->get_left();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_clave = this->successor(clave);

            // Replace node's key with successor's key
            node->set_clave(successor_clave);

            // Delete the old successor's key
            node->set_right(remove(node->get_right(), successor_clave));
        }
    }

    else if (node->get_clave() < clave)
        node->set_right(remove(node->get_right(), clave));

    else
        node->set_left(remove(node->get_left(), clave));

    return node;
}

template <class Aeropuerto,class T>
void BST<Aeropuerto,T>::remove(T clave)
{
    this->root = remove(this->root, clave);
}

template <class Aeropuerto,class T>
BSTNode<Aeropuerto,T>* BST<Aeropuerto,T>::get_root(){
    return this->root;
}

template <class Aeropuerto,class T>
bool BST<Aeropuerto,T>::empty()
{
    return this->root == NULL;
}


template <class Aeropuerto,class T>
void BST<Aeropuerto,T>::delete_all(BSTNode<Aeropuerto,T>* node)
{
    if(node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node;
}

template <class Aeropuerto,class T>
void BST<Aeropuerto,T>::delete_all()
{
    this->delete_all(this->root);
}

template <class Aeropuerto,class T>
BST<Aeropuerto,T>::~BST<Aeropuerto,T>()
{
    this->delete_all();
}


#endif //ABB_BST_H

