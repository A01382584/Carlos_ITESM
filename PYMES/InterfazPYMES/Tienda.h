#ifndef ADICIONAL_H_INCLUDED
#define ADICIONAL_H_INCLUDED
#include <string>


using namespace std;

class Tienda{

  public:
    Tienda();
    Tienda(int cuentaC);

    void setcuentaC(int cuentaC);

    int getcuentaC();

  private:
    int cuentaC;
    Cliente listaCliente[10];
    Producto listaProducto[10];

};

Tienda :: Tienda(){

    cuentaC = 0;

}


void
#endif // ADICIONAL_H_INCLUDED
