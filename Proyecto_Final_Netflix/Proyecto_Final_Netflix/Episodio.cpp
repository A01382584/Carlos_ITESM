#include "Episodio.h"
#include <iostream>

Episodio::Episodio() {
	
	id = " ";
	temporada = 0;
	titulo = " ";
	duracion = " ";
	id_episodio = " ";
	duracion = " ";
	calificacion = 0;

}

Episodio::Episodio(string id, string id_episodio, string titulo, string duracion, int calificacion, int temporada,string genero){
	
	this->id = id;
	this->id_episodio = id_episodio;
	this->titulo = titulo;
	this->duracion = duracion;
	this->calificacion = calificacion;
	this->temporada = temporada;
	this->genero = genero;

};

void Episodio::getDetalles() {

	cout << id << "	" << id_episodio << "	" << titulo << "	" << duracion << "	" << calificacion << "	" << temporada << "	" << genero << "	" << endl;
	cout << endl;

};

string Episodio::getId() {
	return id;
};

string Episodio::getDuracion() {
	return duracion;
};

string Episodio::getTitulo() {
	return titulo;
};

string Episodio::getId_Episodio() {

	return id_episodio;

};

string Episodio::getGenero() {

	return genero;

};

int Episodio::getCalificacion() {

	return calificacion;

};

int Episodio::getTemporada() {

	return temporada;

};

void Episodio::getFiltrado() {

	if (calificacion >= 7) {

		cout << id << "	" << id_episodio << "	" << titulo << "	" << calificacion;
		cout << endl;

	};

}

void Episodio::getFiltrado2() {

	if (calificacion >= 8) {

		cout << id << "	" << id_episodio << "	" << titulo << "	" << calificacion;
		cout << endl;

	};

}

