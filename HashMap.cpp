#include "HashMap.h"

bool HashMap::isEmpty() const
{

    return false;
}
int HashMap::conversor(string clave){
    int claveNum = 0;

    for(char letra : clave){
        letra = toupper(letra);
        int index = letra - 'A' + 1;
        claveNum += index;
    }

    return claveNum;

}
int HashMap::hashFunction(string clave)
{
    int claveNum = conversor(clave);
    return claveNum%hashGroups;
}

void HashMap::insertarItem(string clave, Producto* producto)
{
    int index = hashFunction(clave);
    int claveCatProducto = hashFunction(producto->obtenerCategoria());
    
    for(int i = 0; i < hashGroups; i++){
        if(claveCatProducto == index){
            listaProductos[index]->agregarAlPrincipio(producto);
        }
    }

}

void HashMap::eliminarItem(string clave, Producto* producto)
{

    Node* nodoActual = nullptr;

    int index = hashFunction(clave);
    if(buscarItem(clave,producto)){
        int claveCatProducto = hashFunction(producto->obtenerCategoria());
        for(int i = 0; i < hashGroups; i++){
            if(claveCatProducto == index){
                nodoActual = listaProductos[index]->obtenerNodo(producto);
                listaProductos[index]->eliminarNodo(nodoActual);
                
            }
        }
    }
    if(nodoActual != nullptr) delete nodoActual;

}

bool HashMap::buscarItem(string clave, Producto* producto)
{
    int index = hashFunction(clave);
    int claveCatProducto = hashFunction(producto->obtenerCategoria());

    for(int i = 0; i < hashGroups; i++){
        if(claveCatProducto == index){
            if(listaProductos[index]->buscarElemento(producto)) return true;
        }
    }
    
    return false;
}

void HashMap::desplegarMap()
{
    Node* nodoActual = nullptr;

    for(int i = 0; i < hashGroups; i++){
        for(int j = 0; j < listaProductos[i]->size(); j++){
            nodoActual = listaProductos[i]->obtenerPrimerNodo();
            cout<<"Producto: "<< nodoActual->producto->obtenerNombreProducto();
            nodoActual = nodoActual->next;

            
        } 
    }
    
}

HashMap::~HashMap()
{
    for(int i = 0; i < hashGroups; i ++){
        delete listaProductos[i];
    }
    //delete[] listaProductos;
}
