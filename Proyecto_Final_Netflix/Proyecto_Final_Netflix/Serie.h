#pragma once
#ifndef Serie_h
#define Serie_h
#include <iostream>
#include "Video.h"

using namespace std;


class Serie : public Video {

public:

	Serie();
	Serie(string, string, string, string, int, int);

	void GetMuestra();
	void GetFiltrado();
	void GetDetalles();

protected:

	int tot_ep;
	Serie* epi[149];

};

#endif 