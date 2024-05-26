
#include "include\Cliente.h"
#include "include\ClienteNormal.h"
#include "include\ClientePreferencial.h"
#include "include\ColasClientes.h"
#include "include\Producto.h"
#include "include\HashMap.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void desplegarMenu(){
    cout<<"\nBienvenido\n";
    cout<<"Seleccione una opcion:\n";
    cout<<"1. Entregar numero de atencion\n";
    cout<<"2. Llamar al siguiente cliente\n";
    cout<<"3. Ingresar cliente a la cola de manera correcta\n";
    cout<<"4. Menu Productos\n";
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

void desplegarProductosEnBodega(){
    fstream archivo("BODEGA.txt");
    string linea;

    if(archivo.is_open()){
        while(getline(archivo,linea)){
            cout<<linea<<endl;
        }
        archivo.close();
    } else {
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
    }
}
void agregarProductosABodega(HashMap& hashMap){
    string texto;
    int valor;
    Producto* producto;
    
    cout<<"Ingrese el ID del producto: "<<endl;
    cin>>texto;
    producto->setIdProducto(texto);


    
    cout<<"Ingrese el nombre del producto que desea agregar: "<<endl;
    cin>>texto;
    producto->setNombreProducto(texto);

    cout<<"Ingrese la categoria del producto: "<<endl;
    cin>>texto;
    producto->setCategoria(texto);

    cout<<"Ingrese la subcategoria del producto: "<<endl;
    cin>>texto;
    producto->setSubCategoria(texto);

    cout<<"Ingrese el precio del producto: "<<endl;
    cin>>valor;
    producto->setPrecio(valor);

    




}

void menuProductos(HashMap& hashMap){
    int opcion; 

    do{
        cout<<"Seleccione una opcion\n1) Mostrar productos en bodega\n2) Agregar un producto a bodega\n0) Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                desplegarProductosEnBodega();
                break;
            case 2:
                agregarProductosABodega(hashMap);
                break;
            case 0:
                cout<<"Saliendo";
                break;
            default:
                cout<<"Ingrese una opcion valida";
                break;

        }
    } while(opcion != 0);

}

void generarBoletaDeVenta(){

}


void menuPrincipal(ColasClientes& cola, HashMap& hashMap){
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
                menuProductos(hashMap);
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

void leerArchivoBodega(HashMap& hashMap){
    fstream archivo("BODEGA.txt");
    string linea;
    vector<string> partes;
    istringstream ss(linea);
    string parte;

    if(archivo.is_open()){
        while(getline(archivo,linea)){
            getline(ss, parte, ',');
            partes.push_back(parte);

            string categoria = partes[0];
            string subcategoria = partes[1];
            string idProducto = partes[2];
            string nombreProducto = partes[3];
            int precio = stoi(partes[4]);

            Producto* producto = new Producto(idProducto,nombreProducto,precio,categoria,subcategoria);
            hashMap.insertarItem(categoria, producto);
            hashMap.desplegarMap();

        }
        archivo.close();
    } else {
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
    }
}



int main(int argc, char const *argv[])
{
    HashMap hashMap;
    ColasClientes cola;

    leerArchivoBodega(hashMap);
    //menuPrincipal(cola, hashMap);


    system("pause");
    return 0;
}
