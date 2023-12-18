#include "Serie.h"
#include <iostream>

using namespace std;

Serie::Serie() {
	tot_ep = 0;
};

Serie::Serie(string _ID, string _Nombre, string _Duracion, string _Genero, int _Calificacion, int _tot_ep) : Video(_ID, _Nombre, _Duracion, _Genero, _Calificacion) {

	tot_ep = _tot_ep;
};

void Serie::GetMuestra() {

	cout << ID << "	" << Nombre << "	" << Duracion << "	" << Genero << "	" << Calificacion << "	" << tot_ep;
	cout << endl;

};

void Serie::GetDetalles() {

};

void Serie::GetFiltrado() {

	if (Calificacion >= 7) {

		cout << Nombre << "	" << Calificacion;
		cout << endl;

	};

};