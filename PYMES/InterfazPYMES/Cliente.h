//Proyecto Integrador
//Carlos Alberto Ortiz Montes de Oca
//A01382584
//El archivo header en el que desarrollamos la clase Cliente, asi como los metodos que esta utiliza.

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string>
#include "Producto.h"
#include "Mercado.h"

using namespace std;
//Se define la clase Cliente, que juega un papel en las clases de composicion y cuenta con una sus funciones fundamentales asi como otras mas.
class Cliente{

  public:

//constructores
      Cliente();
      Cliente(int numeroCliente, int saldoCliente, string nombreCliente);

//funciones get
      string getnombreCliente();
      int getsaldoCliente();
      int getnumeroCliente();

//funciones set
      void setnombreCliente(string nombreCliente);
      void setsaldoCliente (int saldoCliente);
      void setnumeroCliente (int numeroCliente);

//funciones adicionales que juegan un papel en la modificacion de ciertos atributos, cabe notar que en los arreglos
      string altaMembresia(Mercado ab);
      void modificarSaldo(int deposito);
      void imprimeClientes(int numeroCliente, string nombreCliente);

  private:
//se establecen los atributos para esta clase, asi como un arreglo de tipo Mercado (otra clase)
//se utilizan variables temporales asi como las esperadas, representativas de los datos que pertenecen a nuestros objetos
      int numeroCliente;
      int saldoCliente;
      string nombreCliente;
      int deposito;
      Mercado membresias[5];
      int vips = 0;
      int x;


};

//Se desarrollan los constructores.
Cliente :: Cliente(){

    numeroCliente = 0;
    nombreCliente = " ";
    saldoCliente = 0;
    deposito = 0;

}

Cliente :: Cliente(int numeroCliente, int saldoCliente, string nombreCliente){

    this-> numeroCliente = numeroCliente;
    this-> nombreCliente = nombreCliente;
    this-> saldoCliente = saldoCliente;

}

//Se construyen las variables set y get de la clase.
string Cliente :: getnombreCliente(){

    return nombreCliente;

}

int Cliente :: getsaldoCliente(){

    return saldoCliente;

}

int Cliente :: getnumeroCliente(){

    return numeroCliente;

}

void Cliente :: setnombreCliente(string nombreCliente){

    this->nombreCliente = nombreCliente;

}

void Cliente :: setnumeroCliente(int numeroCliente){

    this->numeroCliente = numeroCliente;

}

void Cliente :: setsaldoCliente(int saldoCliente){

    this->saldoCliente = saldoCliente;

}

//Funcion que nos permite guardar elementos en el arreglo de esta clase con propiedades de otra clase
string Cliente :: altaMembresia(Mercado ab){

        if (vips >= 5){
           cout<<"Limite de membresias alcanzado."<<endl;
        }
        else{
            membresias[vips] = ab;
            vips = vips + 1;
        }
}




//Funcion que modifica el valor de el atributo SaldoCliente
void Cliente :: modificarSaldo(int deposito){

    saldoCliente = saldoCliente + deposito;

}

//Funcion que imprime los elementos de este arreglo si es que cumplen ciertas especificaciones.
//En este caso, si es que son los mismos que los que seleccionamos y obtuvimos filtrando con ifs' y fors'
void Cliente :: imprimeClientes(int elementoM, string nombre){

    for (int x = 0; x<vips; x++){
        if(membresias[x].getnombreMembresia() == nombre && membresias[x].getnumeroMembresia() == elementoM){
            cout<<elementoM<<nombre<<endl;
        }
    }

}



#endif // CLIENTE_H_INCLUDED
