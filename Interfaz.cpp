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
	BSTNode<string>* node;
	cout<<"Ingrese la clave del Aeropuerto"<<endl;
    	string clave;
    	cin>>clave;
    	p_arbol->search(clave);
    	
	}
    



void Interfaz::ingresar_aeropuerto(){
	Aeropuerto* aeropuerto;
    	string codigo,nombre,ciudad,pais;
    	double superficie;
		int terminales,d_nacionales,d_internacionales;
    	cout<<"Ingrese el codigo del Aeropuerto "<<endl;
    	cin>>codigo;
    	cout<<"Ingrese el nombre del Aeropuerto "<<endl;
    	cin>>nombre;
    	cout<<"Ingrese la ciudad "<<endl;
    	cin>>ciudad;
    	cout<<"Ingrese el pais "<<endl;
    	cin>>pais;
    	cout<<"Ingrese el superficie"<<endl;
    	cin>>superficie;
    	cout<<"Ingrese la cantidad de terminales"<<endl;
    	cin>>terminales;
    	cout<<"Ingrese los destinos nacionales"<<endl;
    	cin>>d_nacionales;
    	cout<<"Ingrese los destinos internacionales"<<endl;
    	cin>>d_internacionales;
    	aeropuerto=new Aeropuerto(codigo,nombre,ciudad,pais,superficie,terminales,d_nacionales,d_internacionales);
		p_arbol->insert(codigo,aeropuerto);
		 delete aeropuerto;	
		p_arbol->print_in_order();
}

void Interfaz::baja_aeropuerto(){
	Aeropuerto* p_aeropuerto;
	cout<<"Ingrese la clave del aeropuerto"<<endl;
	string clave;
    cin>>clave;
    p_arbol-> remove(clave,p_aeropuerto);
    p_arbol->print_in_order();

}

void Interfaz::mostrar_todos(){
	cout<<endl;
	p_arbol->print_in_order();
}

void Interfaz::mostrar_arbol(){

}


