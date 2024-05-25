#include "Cliente.h"
#include "ClienteNormal.h"
#include "ClientePreferencial.h"
#include "ColasClientes.h"


#include <iostream>
using namespace std;

void desplegarMenu(){
    cout<<"\nBienvenido\n";
    cout<<"Seleccione una opcion:\n";
    cout<<"1. Entregar numero de atencion\n";
    cout<<"2. Llamar al siguiente cliente\n";
    cout<<"3. Ingresar cliente a la cola de manera correcta\n";
    cout<<"4. Agregar productos a bodega\n";
    cout<<"5. Generar boletas de venta\n";
    cout<<"0. Salir\n";

}

void entregarNumeroDeAtencion(){

}

void llamarAlSiguienteCliente(){

}

void ingresarClienteACola(ColasClientes& cola){
    
    int opcion;
    

    do{
        cout<<"\nQue tipo de atencion requiere: ";
        cout<<"1) Preferencial\n2) General\n0) Salir";
        cin>> opcion;

        if(opcion == 1){
            ClientePreferencial* c1 = new ClientePreferencial("");
            
           do{
            cout<<"Seleccione la opcion que lo represente: \n";
            cout<<"1) Tercera edad\n2) Discapacidad\n3) Embarazada\n0) Salir";
            cin>> opcion;

                if(opcion == 1 || opcion == 2 || opcion == 3){
                    c1->setAtributo(opcion);
                    break;
                } else if(opcion == 0){
                    cout<< "Saliendo";
                    break;
                } else{
                    cout<<"opcion no valida";

                }

           } while(opcion != 1 && opcion != 2 && opcion != 3);

            
            cola.agregarClienteAColaPreferencial(c1);
            delete c1;

        } else if(opcion == 2){
            ClienteNormal* c2 = new ClienteNormal;
            cola.agregarClienteAColaNormal(c2);
            delete c2;
            break;
        } else if(opcion == 0){
            cout<<"Salir";
            break;
        } else{
            cout<<"Selecciona una opcion valida";
        }
        
    } while(opcion != 1 && opcion != 2);
}

void agregarProductosABodega(){

}

void generarBoletaDeVenta(){

}


void menuPrincipal(ColasClientes& cola){
    int opcion;

    do {

        desplegarMenu();
        cin>> opcion;

        switch(opcion){
            
            case 1:
                cout<<"<<Entregar numero de atencion>>";
                entregarNumeroDeAtencion();
                break;
            case 2:
                cout<<"Llamar al siguiente cliente";
                llamarAlSiguienteCliente();
                break;
            case 3:
                cout<<"Ingresar cliente a la cola de manera correcta";
                ingresarClienteACola(cola);
                break;
            case 4:
                cout<<"Agregar productos a bodega";
                agregarProductosABodega();
                break;
            case 5:
                cout<<"Generar boletas de venta";
                generarBoletaDeVenta();
                break;
            case 0:
                cout<<"Saliendo del menu";
                break;
            default:
                cout<<"Ingrese una opcion valida";
                break;
        }


    } while(opcion != 0);

}


int main(int argc, char const *argv[])
{
    ColasClientes cola;
    
    menuPrincipal(cola);

    system("pause");
    return 0;
}
