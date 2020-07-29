#include "Aeropuerto.h"
#include "Cargador.h"
#include "Interfaz.h"

int main(){
	
	BST<string>* p=este_cargador.get_p_arbol();
	p->print_in_order();
	
//	Interfaz este_interfaz(este_cargador.get_p_arbol());
//	este_interfaz.menu();
	
	return 0;
}
