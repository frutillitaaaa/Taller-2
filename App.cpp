
#include "Cliente.h"
#include "ClienteNormal.h"
#include "ClientePreferencial.h"
#include "ColasClientes.h"
#include "Producto.h"
#include "HashMap.h"
#include "Lista.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

void editarArchivoBodega(HashMap& hashMap){
    fstream archivo("BODEGA.txt", ios::in | ios::out);

    if(archivo.is_open()){
        archivo.seekp(0);

        string linea;
        
        for(int i = 0; i < hashMap.obtenerCantHashGroups(); i++){
            Node* nodoActual = hashMap.obtenerLista(i);
            
            while(nodoActual != nullptr){
                linea = nodoActual->producto->toString();
                archivo<<linea<<'\n';
                nodoActual = nodoActual->next;
            }
        }
        
        archivo.flush();
        archivo.close();
        
    } else{
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
    }
    
}

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
    int confirmar;
    bool datoInvalido = false;
    Producto* producto = new Producto();
    do {
    
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

        do{
            datoInvalido = false;
            cout<<"Ingrese el precio del producto: "<<endl;
            cin>>texto;
            

            try{
                valor = stoi(texto);
            } catch(const invalid_argument& e){
                cerr<<"No ingreso un numero"<<endl;
                datoInvalido = true;
            }

        }while(datoInvalido==true);
    
        producto->setPrecio(valor);


        cout<<"Confirmar creacion del producto?\n1) Si\n2)NO"<<endl;
        cout<<"ID Producto: "<<producto->obtenerIdProducto()<<"\nNombre Producto: "<<producto->obtenerNombreProducto()<<
        "\nCategoria: "<<producto->obtenerCategoria()<<"\nSubCategoria: "<<producto->obtenerSubCategoria()<<"\nPrecio: "<<producto->obtenerPrecioProducto()<<endl;
        cin>>confirmar;
    
    } while(confirmar != 1);

    if(confirmar==1){
        hashMap.insertarItem(producto);
        //hashMap.desplegarMap();
        editarArchivoBodega(hashMap);
    } 

    delete producto;

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
    
    Producto* producto;

    if(archivo.is_open()){
        while(getline(archivo,linea)){
            vector<string> partes;
            istringstream ss(linea);
            string parte;
            while(getline(ss, parte, ',')){
                partes.push_back(parte);
            }
            
            if(partes.size() == 5){
                string categoria = partes[0];
                string subcategoria = partes[1];
                string idProducto = partes[2];
                string nombreProducto = partes[3];
                double precio = stod(partes[4]);
                producto = new Producto(categoria,subcategoria,idProducto,nombreProducto,precio);   
            } 
            hashMap.insertarItem(producto);
        }
        delete producto;
        archivo.close();
    } else {
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
    } 
}

int main(int argc, char const *argv[])
{
    HashMap hashMap;
    ColasClientes cola;
    Lista lista;
    leerArchivoBodega(hashMap);
    //menuPrincipal(cola, hashMap);
    agregarProductosABodega(hashMap);
    //hashMap.desplegarMap();
    
    system("pause");
    return 0;
};
