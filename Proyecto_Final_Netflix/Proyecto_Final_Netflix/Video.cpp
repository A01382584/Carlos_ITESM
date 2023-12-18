#include "Video.h"

using namespace std;
#include <iostream>

Video::Video()
{
	ID = " ";
	Nombre = " ";
	Genero = " ";
	Duracion = " ";
	Calificacion = 0;

};

Video::Video(string _ID, string _Nombre, string _Duracion, string _Genero, int _Calificacion) {
	ID = _ID;
	Nombre = _Nombre;
	Genero = _Genero;
	Duracion = _Duracion;
	Calificacion = _Calificacion;
};

string Video::GetID() {
	return ID;
};

string Video::GetNombre() {
	return Nombre;
};


string Video::GetGenero() {
	return Genero;
};

string Video::GetDuracion() {
	return Duracion;
};

int Video::GetCalificacion() {
	return Calificacion;
};

void Video::GetMuestra() {

	cout << Nombre << "	" << Calificacion;
	cout << endl;

};

void Video::GetFiltrado() {

	if (Calificacion >= 7) {

		cout << Nombre << "	" << Calificacion;
		cout << endl;

	};

};

void Video::proyecta() {

};

void Video::setID(string _ID) {

	ID = _ID;

};

void Video::setNombre(string _Nombre) {

	Nombre = _Nombre;

};

void Video::setGenero(string _Genero) {

	Genero = _Genero;

};

void Video::setDuracion(string _Duracion) {

	Duracion = _Duracion;

};

void Video::setCalificacion(int _Calificacion) {
	Calificacion = _Calificacion;
};