#include "Interfaz.h"

//Constructor
Interfaz::Interfaz(){
}

Interfaz::~Interfaz(){
}

void Interfaz::ingresar_p_arbol(BST<string>* p_arbol){
	this->p_arbol=p_arbol;
}

void Interfaz::set_vertices(Lista <punteroVertice> vertices){
	this->vertices=vertices;
}

void Interfaz::set_vuelos(Lista <punteroVuelo> vuelos){
	this->vuelos=vuelos;
}

void Interfaz::menu(){
	Cargador este_cargador;
	este_cargador.cargar_datos();
	this->p_arbol=este_cargador.obtener_p_arbol();
    rellenar_listas();
	cout<<endl<<"*** Hola, bienvenido a tu programa de aeropuertos! lee con atencion las opciones disponibles para ti en el menu ***"<<endl;
	unsigned opcion;
	do{
		cout<<endl<<"** Presiona un numero correspondiente a alguna de las siguientes alternativas: **"<<endl<<endl;
		cout<<"   1.- Consultar un aeropuerto en particular"<<endl;
		cout<<"   2.- Dar de alta (ingresar) un nuevo aeropuerto al diccionario"<<endl;
		cout<<"   3.- Dar de baja (eliminar) un aeropuerto del diccionario"<<endl;
		cout<<"   4.- Mostrar en orden (segun su codigo IATA) todos los aeropuertos"<<endl;
		cout<<"   5.- Mostrar la estructura del arbol de busqueda binario, herramienta informatica subyacente al diccionario"<<endl;
		cout<<"   6.- Buscar vuelo mas rapido"<<endl;
    	cout<<"   7.- Buscar vuelo mas barato"<<endl;
    	cout<<"   8.- Finalizar la aplicacion"<<endl <<endl;

		cout<<"** Mientras no presiones la opcion 6 seguiremos mostrandote el menu luego de realizar la operacion elegida **"<<endl<<endl;
		cin>>opcion; cout<<endl;

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
			case 6:{
				buscarVueloMasRapido();
				break;
			}
			case 7:{
				buscarVueloMasBarato();
				break;
			}
			case 8: cout<<"gracias por usar este programa! Hasta pronto"<<endl; break;
		}
	}while(opcion!=8);
	delete p_arbol;
}

void Interfaz::consultar_aeropuerto(){
	string codigo;
	cout<<"* Ingresa, con mayusculas, el codigo IATA del aeropuerto del cual quieres conocer su informacion: *"<<endl;
	cin>>codigo;
	if(p_arbol->search(codigo)){
		cout<<endl<<"* Efectivamente este aeropuerto se encuentra en nuestros registros, a continuacion un detalle de su informacion: *"<<endl<<endl;
		(p_arbol->get_p_node(codigo))->get_p_aeropuerto()->mostrar_atributos();
	}else{
		cout<<"* Lo sentimos, el codigo IATA ingresado no figura en nuestros registros *";
	}

}

void Interfaz::ingresar_aeropuerto(){
	string iata, nombre, ciudad, pais;
	double superficie;
	int terminales, d_nacionales, d_internacionales;
	cout<<"           * A continuacion te vamos a pedir una serie de datos *"<<endl;
	cout<<"* Digita por favor cada uno de ellos para agregar la informacion al diccionario: *"<<endl<<endl;
	cout<<"Ingresa, con mayusculas, el codigo iata del aeropuerto: "; cin>>iata; cout<<endl;
	cout<<"Digita el nombre del aeropuerto: "; cin>>nombre; cout<<endl;
	cout<<"Indica el nombre de la ciudad en la que se emplaza el aeropuerto: "; cin>>ciudad; cout<<endl;
	cout<<"Indica el nombre del pais en el que esta el aeropuerto: "; cin>>ciudad; cout<<endl;
	cout<<"Ingresa la superficie que ocupa el aeropuerto: "; cin>>superficie; cout<<endl;
	cout<<"Indica la cantidad de terminales que posee el aeropuerto: "; cin>>terminales; cout<<endl;
	cout<<"Indica la cantidad de destinos nacionales con que cuenta el aeropuerto: "; cin>>d_nacionales; cout<<endl;
	cout<<"Indica la cantidad de destinos internacionales con que cuenta el aeropuerto: "; cin>>d_internacionales; cout<<endl;
	Aeropuerto* aeropuerto_manual=new Aeropuerto(iata, nombre, ciudad, pais, superficie, terminales, d_nacionales, d_internacionales);
	p_arbol->insert((aeropuerto_manual->get_iata()), aeropuerto_manual);
	cout<<" * A continuacion la nueva lista ordenada con todos los aeropuertos, incluido el que acabas de ingresar: *"<<endl<<endl;
	p_arbol->print_in_order();
}

void Interfaz::baja_aeropuerto(){
	string codigo;
	cout<<"* Ingresa, con mayusculas, el codigo IATA del aeropuerto que deseas dar de baja: *"<<endl;
	cin>>codigo;
	if(p_arbol->search(codigo)){
		cout<<endl<<"* Efectivamente este aeropuerto se encuentra en nuestros registros, a continuacion se eliminará: *"<<endl<<endl;
		p_arbol->remove(codigo);
	}else{
		cout<<"* Lo sentimos, el codigo IATA ingresado no figura en nuestros registros *";
	}
}

void Interfaz::mostrar_todos(){
	cout<<"* Esta es la lista ordenada de aeropuertos existente en nuestros registros: *"<<endl<<endl;
	p_arbol->print_in_order();
}

void Interfaz::mostrar_arbol(){
	cout<<"* Asi es como se representa el ABB que otorga funcionalidad y memoria al diccionario: *"<<endl;
    BSTNode<string>* p_salto=new BSTNode<string>;
    p_salto->set_data("   ");
	p_arbol->print_width(p_salto);
	delete p_salto;
}

void Interfaz::buscarVueloMasRapido(){
    string origen, destino;
    cout << "   Ingrese el origen del vuelo: " << endl;
    cin >> origen;
    cout << "   Ingrese el destino del vuelo: " << endl;
    cin >> destino;
	Dijkstra dijkstra (origen, destino, 'R');
	dijkstra.calcular_caminos_minimos(this->vertices,this->vuelos);
}

void Interfaz::buscarVueloMasBarato(){
    string origen, destino;
    cout << "   Ingrese el origen del vuelo: " << endl;
    cin >> origen;
    cout << "   Ingrese el destino del vuelo: " << endl;
    cin >> destino;
	Dijkstra dijkstra (origen, destino, 'B');
	dijkstra.calcular_caminos_minimos(this->vertices,this->vuelos);

};

void Interfaz::rellenar_listas(){

	ifstream archivo_vuelos ("vuelos.txt");
    string origen;
    string destino;
    string costo;
    string horas;

    if (!archivo_vuelos.fail()){
        while(!archivo_vuelos.eof()){
                archivo_vuelos >> origen;
                archivo_vuelos >> destino;
                archivo_vuelos >> costo;
                archivo_vuelos >> horas;

                Vertices* dato = new Vertices(origen);
                Vuelos* dato_2 = new Vuelos(origen, destino, atoi(costo.c_str()), atof(horas.c_str()));

                this->vuelos.agregarAlFinal(dato_2);
                this->vertices.agregarAlFinal(dato);
        }
    }
        for (int i=0; i<vertices.obtenerCantidadElementos(); i++){
            for (int j = i+1 ; j<vertices.obtenerCantidadElementos() ; j++){
                if (vertices.obtenerDato(i)->obtener_vertice() == vertices.obtenerDato(j)->obtener_vertice())
                    vertices.sacar(j);
            }
    }
}
