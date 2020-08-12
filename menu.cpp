# include  " Menu.h "
# include  " Graph.h "
# include	"Diccionario.h"

using namespace std;

Menú :: Menú (Gráfico y grafo) {
    this -> vuelos = & grafo;
}
 Menú vacío :: mostrarMenu () {

    cout << " \ n \ t 1. Consultar por un aeropuerto en particular. \ n " ;
    cout << " \ t 2. Agregar aeropuerto \ n " ;
    cout << " \ t 3. Remover aeropuerto \ n " ;
    cout << " \ t 4. Mostrar todos los aeropuertos (En orden) \ n " ;
    cout << " \ t 5. Mostrar todos los aeropuertos (Recorrido en ancho) \ n " ;
    cout << " \ t 6. Buscar vuelo mas rapido \ n " ;
    cout << " \ t 7. Buscar vuelo mas barato \ n " ;
    cout << " \ t 8. Salir \ n " ;
    cout << " \ t Ingrese el número de la opción que desea seleccionar: \ n " ;
    cin >> opcion;
}

bool  Menu :: selectorDeOpciones () {

    bool estado;
    Diccionario *diccionario;

    switch ( this -> opcion ) {

        case  ' 1 ' : {
            cout << " \ n \ t Ingrese el codigo IATA del aeropuerto a consultar: \ n " ;
            
            estado = true ;
            diccionario->agregarclave();
            break ;
        }

        case  ' 2 ' : {
            cout << " FUNCION DE AGREGAR AEROPUERTO " ;
            diccionario->agregaraeropuerto();
            estado = true ;
            break ;
        }

        case  ' 3 ' : {
            cout << " FUNCION DE REMOVER AEROPUERTO " ;
            diccionario->borraraeropuerto();
            estado = true ;
            break ;
        }

        case  ' 4 ' : {
            cout << " FUNCION DE MOSTRAR TODOS LOS AEROPUERTOS EN ORDEN " ;
            diccionario->mostrarenorden();
            estado = true ;
            break ;
        }

        case  ' 5 ' : {
            cout << " FUNCION DE MOSTRAR TODOS LOS AEROPUERTOS EN ANCHO " ;
            diccionario->mostrarenancho();
            estado = true ;
            break ;
        }
        caso  ' 6 ' : {
            buscarVueloMasRapido ();
            estado = true ;
            braek ;
        }
        caso  ' 7 ' : {
            buscarVueloMasBarato ();
            estado = true ;
            break ;
        }
        caso  ' 8 ' : {
            estado = false ;
            break ;
        }

        default : {
            cout << " \ t Opción no valida. Ingrese alguna de las opciones en el menú " << endl;
            estado = true ;
            break ;
        }
    }
    return estado;
}

 void Menu :: buscarVueloMasRapido () {
    int origen, destino;
    cout << " Ingrese el origen del vuelo: " << endl;
    cin >> origen;
    cout << " Ingrese el destino del vuelo: " << endl;
    cin >> destino;
    cout << " HASHEANDO NOMBRES A NUMEROS " ;
    this -> vuelos -> encontrarSenderoMasRapido (origen, destino);

}

 Menú vacío :: buscarVueloMasBarato () {
    int origen, destino;
    cout << " Ingrese el origen del vuelo: " << endl;
    cin >> origen;
    cout << " Ingrese el destino del vuelo: " << endl;
    cin >> destino;
    cout << " HASHEANDO NOMBRES A NUMEROS " ;
    this -> vuelos -> encontrarSenderoMasBarato (origen, destino);

};

