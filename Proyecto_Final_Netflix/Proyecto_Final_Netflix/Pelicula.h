#pragma once
#ifndef Pelicula_h
#define Pelicula_h

#include <iostream>

#include "Video.h"
using namespace std;

class Pelicula : public Video{

public:

	Pelicula();
	Pelicula(string, string, string, string, int);
	void GetMuestra();
	void GetFiltrado();

private:

};

#endif 
