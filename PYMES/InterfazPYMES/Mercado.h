//Proyecto Integrador
//Carlos Alberto Ortiz Montes de Oca
//A01382584
//El archivo header en el que desarrollamos la clase Mercado, asi como los metodos que esta utiliza.

#ifndef MERCADO_H_INCLUDED
#define MERCADO_H_INCLUDED
#include <string>
//Establecemos la clase Mercado - que alberga los objetos "Categorias-Grupos VIP", una disculpa por el nombre si causa confusion.
class Mercado{

  public:
//Definimos constructores, sets y gets
      Mercado();
      Mercado(string nombreMembresia, int numeroMembresia, string alp);

      void setnombreMembresia(string nombreMembresia);
      void setnumeroMembresia(int numeroMembresia);
      void setalpMembresia(string alp);

      int getnumeroMembresia();
      string getnombreMembresia();
      string getalpMembresia();

  private:

//atributos que representan los datos de los objetos
    string nombreMembresia;
    int numeroMembresia;
    string alp;

};

//Parametros iniciales de constructor default y constructor hecho por nosotros
Mercado :: Mercado(){

    nombreMembresia = " ";
    numeroMembresia = 0;
    alp = "VIP";

}
//Dejamos alp constante, que nos interesa mantenerlo asi
Mercado :: Mercado(string nombreMembresia, int numeroMembresia, string alp){

    this -> nombreMembresia = nombreMembresia;
    this -> numeroMembresia = numeroMembresia;
    alp = "VIP";

}

//Sets' y gets' de nuestra clase mercado, alp se queda constante.

void Mercado :: setnombreMembresia(string nombreMembresia){

    this -> nombreMembresia = nombreMembresia;

}
void Mercado :: setnumeroMembresia(int numeroMembresia){

    this -> numeroMembresia = numeroMembresia;

}

void Mercado :: setalpMembresia(string alp){

    alp = "VIP";

}

int Mercado :: getnumeroMembresia(){

    return numeroMembresia;

}
string Mercado :: getnombreMembresia(){

    return nombreMembresia;

}

string Mercado :: getalpMembresia(){

    return alp;

}


#endif // MERCADO_H_INCLUDED
