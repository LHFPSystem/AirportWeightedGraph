#include "aeropuerto.h"

Aeropuerto::Aeropuerto(){
	iata="";
	nombre="";
	ciudad="";
	pais="";
	superficie=0;
	terminales=0;
	d_nacionales=0;
	d_internacionales=0;
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