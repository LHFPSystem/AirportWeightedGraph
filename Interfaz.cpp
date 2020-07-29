#include "Interfaz.h"

//Constructor
Interfaz::Interfaz(BST<string>* p_arbol){
	this->p_arbol=p_arbol;
}

Interfaz::~Interfaz(){

}

void Interfaz::menu(){
	Cargador este_cargador;	
	este_cargador.cargar_datos();
	do{
		cout<<endl<<"Presiona un numero correspondiente a alguna de las siguientes alternativas: "<<endl<<endl;
		cout<<"1.- Consultar un aeropuerto en particular"<<endl;
		cout<<"2.- Dar de alta (ingresar) un nuevo aeropuerto al diccionario"<<endl;
		cout<<"3.- Dar de baja (eliminar) un aeropuerto del diccionario"<<endl;
		cout<<"4.- Mostrar en orden (segun su codigo IATA) todos los aeropuertos"<<endl;
		cout<<"5.- Mostrar la estructura del arbol informatico que es el soporte computacional del diccionario"<<endl;
		cout<<"6.- Finalizar la aplicacion"<<endl<<endl;
		unsigned opcion; cin>>opcion; cout<<endl;
		
		// Ramificacion del programa de acuerdo a la opcion escogida
		switch(opcion){
			case 1:{
				consultar_aeropuerto();			
				break;
			}
			case 2:{
				ingresar_aeropuerto();
				break;
			}
			case 3:{
				baja_aeropuerto();
				break;
			}
			case 4:{
				mostrar_todos();
				break;
			}
			case 5:{
				mostrar_arbol();
				break;
			}
			case 6: cout<<"gracias por usar este programa! Hasta pronto"<<endl; break;
		}
	}while(opcion!=6);
}

void Interfaz::consultar_aeropuerto(){

}

void Interfaz::ingresar_aeropuerto(){

}

void Interfaz::baja_aeropuerto(){

}

void Interfaz::mostrar_todos(){
	p_arbol->print_in_order();
}

void Interfaz::mostrar_arbol(){

}
