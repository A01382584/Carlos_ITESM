#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula() {

};

Pelicula::Pelicula(string _ID, string _Nombre, string _Duracion, string _Genero, int _Calificacion) : Video(_ID, _Nombre, _Duracion, _Genero, _Calificacion) {

};

void Pelicula::GetMuestra() {

	cout << ID << "	" << Nombre << "	" << Duracion << "	" << Genero << "	" << Calificacion;
	cout << endl;

};

void Pelicula::GetFiltrado() {

	if (Calificacion >= 7) {

		cout << Nombre << "	" << Calificacion;
		cout << endl;

	};

};

