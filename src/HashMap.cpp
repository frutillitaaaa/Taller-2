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
    int index = hashFunction(clave);
    if(buscarItem(clave,producto)){
        int claveCatProducto = hashFunction(producto->obtenerCategoria());
        for(int i = 0; i < hashGroups; i++){
            if(claveCatProducto == index){
                Node* nodoActual = listaProductos[index]->obtenerNodo(producto);
                listaProductos[index]->eliminarNodo(nodoActual);
                delete nodoActual;
        }
    }
    }

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
}
