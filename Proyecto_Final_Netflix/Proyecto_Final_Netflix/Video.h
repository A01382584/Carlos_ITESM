#pragma once
#ifndef Video_h
#define Video_h


#include <iostream>

using namespace std;

class Video{

public:

	Video();
	Video(string, string, string, string, int);

	string GetID();
	string GetNombre();
	string GetGenero();
	string GetDuracion();
	int GetCalificacion();

	void setID(string _ID);
	void setNombre(string _Nombre);
	void setGenero(string _Genero);
	void setDuracion(string _Duracion);
	void setCalificacion(int _Calificacion);

	virtual void GetMuestra() = 0;
	virtual void GetFiltrado() = 0;

	void proyecta();

protected:

	string ID;
	string Nombre;
	string Genero;
	string Duracion;
	int Calificacion;


};

#endif
