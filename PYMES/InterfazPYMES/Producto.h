//Proyecto Integrador
//Carlos Alberto Ortiz Montes de Oca
//A01382584
//El archivo header en el que desarrollamos la clase Producto, asi como los metodos que esta implementa.

#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string>
#include "Cliente.h"


using namespace std;

//Se inicializa la clase producto, en donde definimos sus respectivos constructores, metodos y atributos acordes al diagrama.
class Producto{

  public:
//constructores
      Producto();
      Producto(string nombreProducto, int numeroProducto, int precioProducto, int cantidadProducto);

//funciones get para los atributos
      string getnombreProducto();
      int getprecioProducto();
      int getcantidadProducto();
      int getnumeroProducto();

//funciones set para los atributos
      void setnombreProducto(string nombreProducto);
      void setprecioProducto(int precioProducto);
      void setcantidadProducto(int cantidadProducto);
      void setnumeroProducto(int numeroProducto);


      private:
//atributos-parametros de la clase
      string nombreProducto;
      int cantidadProducto, precioProducto, numeroProducto;


};
//Se establecen los valores iniciales para ambos constructores
Producto :: Producto(){

    nombreProducto = " ";
    precioProducto = 0;
    cantidadProducto = 0;
    numeroProducto = 0;

}

Producto :: Producto(string nombreProducto, int numeroProducto, int precioP, int cantidadP){

    this -> nombreProducto = nombreProducto;
    this -> numeroProducto = numeroProducto;
    this -> precioProducto = precioProducto;
    this -> cantidadProducto = cantidadProducto;

}

//Se desarrollan las funciones "set y get" para poder llamar y modificar los valores de los atributos de la clase
string Producto :: getnombreProducto(){

    return nombreProducto;

}

int Producto :: getprecioProducto(){

    return precioProducto;

}

int Producto :: getcantidadProducto(){

    return cantidadProducto;

}

int Producto :: getnumeroProducto(){

    return numeroProducto;

}

void Producto :: setnombreProducto(string nombreProducto){

    this -> nombreProducto = nombreProducto;
}

void Producto :: setprecioProducto(int precioProducto){

    this-> precioProducto = precioProducto;

}

void Producto :: setcantidadProducto(int cantidadProducto){

    this-> cantidadProducto = cantidadProducto;

}

void Producto :: setnumeroProducto(int numeroProducto){

    this-> numeroProducto = numeroProducto;

}


#endif // PRODUCTO_H_INCLUDED
