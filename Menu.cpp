#include "Menu.h"
#include "Graph.h"

using namespace  std;

Menu::Menu(Graph& grafo) {
    this->vuelos = &grafo;
}
void Menu::mostrarMenu(){

    cout << "\n\t1. Consultar por un aeropuerto en particular.\n";
    cout << "\t2. Agregar aeropuerto\n";
    cout << "\t3. Remover aeropuerto\n";
    cout << "\t4. Mostrar todos los aeropuertos (En orden)\n";
    cout << "\t5. Mostrar todos los aeropuertos (Recorrido en ancho)\n";
    cout << "\t6. Buscar vuelo mas rapido\n";
    cout << "\t7. Buscar vuelo mas barato\n";
    cout << "\t8. Salir\n";
    cout << "\tIngrese el numero de la opcion que desea seleccionar: \n";
    cin >> opcion;
}

bool Menu::selectorDeOpciones() {

    bool estado;

    switch (this->opcion) {

        case '1': {
            cout << "\n\tIngrese el codigo IATA del aeropuerto a consultar: \n";
            estado = true;
            break;
        }

        case '2': {
            cout << "FUNCION DE AGREGAR AEROPUERTO";
            estado = true;
            break;
        }

        case '3': {
            cout << "FUNCION DE REMOVER AEROPUERTO";
            estado = true;
            break;
        }

        case '4': {
            cout << "FUNCION DE MOSTRAR TODOS LOS AEROPUERTOS EN ORDEN";
            estado = true;
            break;
        }

        case '5': {
            cout << "FUNCION DE MOSTRAR TODOS LOS AEROPUERTOS EN ANCHO";
            estado = true;
            break;
        }
        case '6': {
            buscarVueloMasRapido();
            estado = true;
            break;
        }
        case '7': {
            buscarVueloMasBarato();
            estado = true;
            break;
        }
        case '8': {
            estado = false;
            break;
        }

        default: {
            cout << "\tOpcion no valida. Ingrese alguna de las opciones en el menu" << endl;
            estado = true;
            break;
        }
    }
    return estado;
}

void Menu::buscarVueloMasRapido(){
    int origen, destino;
    cout << "Ingrese el origen del vuelo: " << endl;
    cin >> origen;
    cout << "Ingrese el destino del vuelo: " << endl;
    cin >> destino;
    cout << "HASHEANDO NOMBRES A NUMEROS";
    this->vuelos->encontrarSenderoMasRapido(origen,destino);

}

void Menu::buscarVueloMasBarato(){
    int origen, destino;
    cout << "Ingrese el origen del vuelo: " << endl;
    cin >> origen;
    cout << "Ingrese el destino del vuelo: " << endl;
    cin >> destino;
    cout << "HASHEANDO NOMBRES A NUMEROS";
    this->vuelos->encontrarSenderoMasBarato(origen,destino);

};