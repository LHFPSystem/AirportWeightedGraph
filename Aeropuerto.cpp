#include "aeropuerto.h"

Aeropuerto::Aeropuerto(){
}

Aeropuerto::Aeropuerto(string iata, string nombre, string ciudad, string pais, double superficie, int terminales, int d_nacionales, int d_internacionales){
	this->iata=iata;
	this->nombre=nombre;
	this->ciudad=ciudad;
	this->pais=pais;
	this->superficie=superficie;
	this->terminales=terminales;
	this->d_nacionales=d_nacionales;
	this->d_internacionales=d_internacionales;
}

Aeropuerto::~Aeropuerto(){
	
}

void Aeropuerto::setea_todo(string iata, string nombre, string ciudad, string pais, double superficie, int terminales, int d_nacionales, int d_internacionales){
	this->iata=iata;
	this->nombre=nombre;
	this->ciudad=ciudad;
	this->pais=pais;
	this->superficie=superficie;
	this->terminales=terminales;
	this->d_nacionales=d_nacionales;
	this->d_internacionales=d_internacionales;
}

void Aeropuerto::set_iata(string iata){
	this->iata=iata;
}

string Aeropuerto::get_iata(){
	return iata;
}

string Aeropuerto::get_nombre(){
	return nombre;
}

string Aeropuerto::get_ciudad(){
	return ciudad;
}

string Aeropuerto::get_pais(){
	return pais;
}

double Aeropuerto::get_superficie(){
	return superficie;
}

int Aeropuerto::get_terminales(){
	return terminales;
}

int Aeropuerto::get_d_nacionales(){
	return d_nacionales;
}

int Aeropuerto::get_d_internacionales(){
	return d_internacionales;
}

void Aeropuerto::mostrar_atributos(){
	cout<<"Codigo IATA: "<<iata<<endl<<"Nombre: "<<nombre<<endl<<"Ciudad: "<<ciudad<<endl<<"Pais: "<<pais<<endl<<"Superficie: "<<superficie<<endl<<"Numero de terminales: "<<terminales<<endl<<"Destinos nacionales: "<<d_nacionales<<endl<<"Destinos internacionales: "<<d_internacionales<<endl<<endl;
}

