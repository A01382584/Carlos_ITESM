//Proyecto Integrador
//Carlos Alberto Ortiz Montes de Oca
//A01382584
//La interfaz general que nos permite realizar las operaciones.

//Importamos todos archivos header, en los que estamos guardando las clases y sus metodos.

#include <iostream>
#include "Cliente.h"
#include "Producto.h"
#include "Mercado.h"
#include <string>

using namespace std;

int main()
{
    //Aqui establecemos todas las variables que estaremos utilizando en la interfaz, asi como los arreglos que guardan los objetos de cada clase.
    //La mayoria de las funciones son temporales solo se ocupan en casos en especifico y se especializan en cero.
    //Se podria probablemente simplificar el numero de variables, en caso de buscar mejorar la eficiencia.

    Cliente listaClientes[10];
    Producto listaProductos[10];
    Mercado listaMembresias[10];
    int selecc, cantidad, precio, saldo, x;
    int elementoC = 0, elementoP = 0, numeroC = 0, numeroP = 0, elementoM = 0, numeroM = 0, extra = 0;
    string nombre;
    int location1, location2;

    //Establecemos un ciclo do - while, con un switch dentro, que nos permite seguir utilizando la interfaz, en este caso hasta que el usuario presione la tecla 9.
    //Gracias a la funcion switch se plantean los diferentes casos, dependiendo de la eleccion del usuario para realizar las operaciones acordes.
    do{
        cout<<"Bienvenido a la Tienda Michoce."<<endl;
        cout<<"Seleccione la accion que desea realizar"<<endl;
        cout<<"1.Desplegar listado de productos."<<endl;
        cout<<"2.Desplegar listado de clientes dados de alta."<<endl;
        cout<<"3.Consulta y deposito de saldo disponible."<<endl;
        cout<<"4.Dar de alta a un nuevo cliente"<<endl;
        cout<<"5.Dar de alta nuevo producto"<<endl;
        cout<<"6.Crear un grupo VIP."<<endl;
        cout<<"7.Mostrar grupos VIP."<<endl;
        cout<<"8.Ascender a clientes a miembros VIP."<<endl;
        cout<<"9.Mostrar miembros de Club VIP."<<endl;
        cout<<"0.Salir de aplicacion."<<endl;
        cin>>selecc;
        cout<<endl;

    //Se inicializa el switch, al haberse presentado las instrucciones en la seccion de arriba y se definen posteriormente cada uno de los casos.
        switch (selecc){
    //Casos uno y dos queremos imprimir listas, por lo que utilizamos ciclos for que duren la cantidad de elementos[] presentes en for.
        case 1:
                cout<<"Listado de productos: "<<endl;
                cout<<"Numero"<<"        "<<"Nombre"<<"        "<<"        "<<"Unidades"<<"        "<<"Precio "<<endl;
                for (x = 0; x < elementoP; x++){
                    cout<<listaProductos[x].getnumeroProducto()<<"             "
                    <<listaProductos[x].getnombreProducto()<<"                 "<<listaProductos[x].getcantidadProducto()
                    <<"            "<<listaProductos[x].getprecioProducto()<<endl;
                    cout<<endl;
                }
                break;
            case 2:
                cout<<"Listado de clientes: "<<endl;
                cout<<"Numero"<<"        "<<"Nombre"<<"        "<<"Saldo"<<endl;
                for (x = 0; x < elementoC; x++){
                    cout<<listaClientes[x].getnumeroCliente()<<"             "
                    <<listaClientes[x].getnombreCliente()<<"          "<<listaClientes[x].getsaldoCliente()<<endl;
                    cout<<endl;
                }
                break;
     //Caso 3 realiza una operacion que busca alterar ciertos atributos de la clase Cliente, por lo que seleccionamos que elemento[] y realizamos las modificaciones acordes.
        case 3:
            cout<<"Saldo disponible de cliente."<<endl;
            cout<<"Escriba primero su numero de cliente porfavor: "<<endl;
            cin>>x;
            cout<<endl;
            cout<<listaClientes[x].getnumeroCliente()<<"        "<<listaClientes[x].getnombreCliente()
            <<"        "<<listaClientes[x].getsaldoCliente()<<endl;
            cout<<"Introduzca la cantidad de dinero que desea depositar: "<<endl;
            cin>>cantidad;
            listaClientes[x].modificarSaldo(cantidad);
            cout<<"Transaccion exitosa."<<endl;
            cout<<endl;
            break;
      //Caso 4, 5 y 6 buscan de similar manera cambiar los elementos[], pero en este caso de nuestros arreglos. Obtenemos los elementos que vamos a modificar
      // y realizamos las modificaciones correspondientes
        case 4:
            if(elementoC < 10){
                cout<<"Damos de alta a un cliente nuevo, favor de ingresar sus datos."<<endl;
                cout<<"Introduzca el nombre del cliente: "<<endl;
                cin>>nombre;
                cout<<endl;
                cout<<"Introduzca su deposito inicial: "<<endl;
                cin>>saldo;
                numeroC = elementoC;

                listaClientes[elementoC].setnombreCliente(nombre);
                listaClientes[elementoC].setsaldoCliente(saldo);
                listaClientes[elementoC].setnumeroCliente(numeroC);
                elementoC = elementoC + 1;
                cout<<endl;
            }
            else{
                cout<<"Lo sentimos, pero la lista se encuentra llena por el momento."<<endl;
                cout<<endl;
            }

            break;
        case 5:
            if(elementoP < 10){
                cout<<"Damos de alta a un producto nuevo, favor de ingresar sus datos."<<endl;
                cout<<"Introduzca el nombre del producto: "<<endl;
                cin>>nombre;
                cout<<"Introduzca el numero de unidades de producto: "<<endl;
                cin>>cantidad;
                cout<<"Introduzca el precio de cada unidad de producto: "<<endl;
                cin>>precio;
                numeroP = elementoP;

                listaProductos[elementoP].setnombreProducto(nombre);
                listaProductos[elementoP].setcantidadProducto(cantidad);
                listaProductos[elementoP].setprecioProducto(precio);
                listaProductos[elementoP].setnumeroProducto(numeroP);

                elementoP = elementoP + 1;
                cout<<endl;
            }
            else{
                cout<<"Lo sentimos, pero la lista se encuentra llena por el momento."<<endl;
                cout<<endl;
            }
            break;
        case 6:
            if (elementoM <= 5){

                cout<<"6.Crear un grupo VIP."<<endl;
                cout<<"Introduzca el nombre que desea darle al grupo: "<<endl;
                cin>>nombre;
                numeroM = elementoM;

                listaMembresias[elementoM].setnombreMembresia(nombre);
                listaMembresias[elementoM].setnumeroMembresia(numeroM);
                listaMembresias[elementoM].setalpMembresia(nombre);

                elementoM = elementoM + 1;
                cout<<endl;

            }

            else{

                cout<<"Se ha excedido el numero de membresias existentes posibles."<<endl;
                cout<<endl;
            }

            break;
      //Caso 7 busca hacer lo mismo que casos 1 y 2, por lo que establecemos el ciclo for para el numero de elementos guardados en el arreglo e imprimimos los atributos establecidos.
        case 7:
            cout<<"7.Mostrar grupos VIP."<<endl;
            cout<<"Numero"<<"        "<<"Nombre"<<"        "<<"Status"<<endl;
            for (x = 0; x < elementoM;x++){
                cout<<listaMembresias[x].getnumeroMembresia()<<"             "
                <<listaMembresias[x].getnombreMembresia()<<"            "<<listaMembresias[x].getalpMembresia()<<endl;
            }
            break;
      //Casos ocho y nueve son un poco mas avanzados, hablando de composiciones y arreglos dentro de arreglos.
      //Se busca establecer un objeto de un arreglo dentro de otro arreglo, tomando en cuenta que vamos a filtrar para elementos[] en especifico,
      //ya que nosotros queremos seleccionar el elemento. El problema es que los elementos estan guardados dentro del arrego y nosotros queremos sacarlos
      // de una manera sencilla y "automatizada" que checar de uno por uno es la razon por la que escogimos arreglos en un principio.
      //Primero que nada es necesario establecer cual es el elemento[] que queremos seleccionar. Escribimos uno de los atributos del objeto y con un ciclo for
      //buscamos entre todos los elementos del arreglo para que el momento en que sean el mismo guardar el elemento[] en una variable. (Si es que si existe dentro
      //del arreglo). Para comprobar su existencia y seguir avanzando utilizamos condicionales if - else. Al ya contar nosotros con el elemento[] que queremos
      //meter en otro arreglo, ahora es momento de busca el elemento/objeto en el que deseamos introducir nuestro elemento dentro del otro arreglo.
      //Para esto volvemos a utilizar ciclo for para encontrarlo entre todos los atributos del arreglo, y if - else para verificar su existencia- seguir avanzando.
      //Contando ya con los dos elementos que necesitamos, utilizamos una funcion que establece el elemento deseado como atributo de el otro elemento en el arreglo que
      //nosotros tenemos en la funcion Clase, o al menos utiliza este arreglo para la composicion.
        case 8:
            cout<<"8.Ascender a clientes a miembros VIP."<<endl;
            cout<<"Introduzca el nombre del cliente que busca ascender a VIP: "<<endl;
            cin>>nombre;
            location1 = -1;
            for(int x = 0; x < elementoC;x++){
                if(nombre == listaClientes[x].getnombreCliente()){
                    location1 = x;
                }
            }
            if(location1 == -1){

                    cout<<"No se encontro al Cliente en la base de Datos."<<endl;

                        }
            else{
                do{
                    cout<<"La solicitud de "<<nombre<<" a sido considerada y aceptada."<<endl;
                    cout<<"Introduzca ahora el nombre de la categoria VIP a la que pertenece ahora "<<nombre<<endl;
                    cin>>nombre;
                    location2 = -1;
                    for (int x=0; x < elementoM; x++){
                        if(nombre == listaMembresias[x].getnombreMembresia()){
                            location2 = x;
                        }
                    }
                    if(location2 == -1){
                        cout<<"No se encontro la categoria de VIP en la base de Datos."<<endl;

                    }
                    else{
                        cout<<"Transaccion en proceso..."<<endl;
                        cout<<"Introduzca el numero asignado a su categoria: "<<endl;
                        cin>>extra;
                    }
                    cout<<location1;
                }while (location2 == -1);
                listaClientes[location1].altaMembresia(listaMembresias[extra]);
                cout<<"Transaccion en proceso..."<<endl;

            }
            cout<<endl;
            break;
        case 9:
            cout<<"9.Mostrar miembros de Club VIP."<<endl;
            cout<<"Introduzca el nombre del Club VIP del que le interesa conocer a sus miembros: "<<endl;
            cin>>nombre;
            location1 = -1;
            for (int x = 0; x < elementoM ; x++){
                if(listaMembresias[x].getnombreMembresia() == nombre){
                    location1 = x;
                }
                else{
                    cout<<"No se encontro ningun nombre de Club VIP bajo ese nombre."<<endl;
                }
            }
            if(location1 != -1){
                cout<<"Clientes miembros de "<<listaMembresias[location1].getnombreMembresia()<<" : "<<endl;
                for(x = 0; x < elementoM; x++){
                    listaClientes[x].imprimeClientes(location1,nombre);

            }
            }
            cout<<endl;
            break;
        }

    }
  //Salida por parte del usuario al presionar
    while (selecc != 0);
    return 0;
}
