#pragma once
#ifndef Episodio_h
#define Episodio_h
#include <iostream>

using namespace std;

class Episodio{

public:

	Episodio();
	Episodio(string, string, string, string, int, int, string);

	void getDetalles();
	void getFiltrado();
	void getFiltrado2();

	string getId();
	string getId_Episodio();
	string getTitulo();
	string getGenero();
	string getDuracion();

	int getCalificacion();
	int getTemporada();

private:

	string id;
	string id_episodio;
	string titulo;
	string duracion;
	int calificacion;
	int temporada;
	string genero;


};

#endif
