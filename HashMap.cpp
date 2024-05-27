#include "HashMap.h"

HashMap::HashMap()
{
    for(int i = 0; i < hashGroups; i++){
        listaProductos[i] = new Lista();
    }
}

bool HashMap::isEmpty() const
{
    
    return false;
}

int HashMap::hashFunction(string clave)
{
    int claveNum = 0;
    int posicionLetra = 0;

    for(char letra : clave){
        letra = toupper(letra);
        int valorASCIILEtra = static_cast<int>(letra);
        claveNum += (valorASCIILEtra * posicionLetra);
        posicionLetra++;
    }
    
    return claveNum%hashGroups;
}

void HashMap::insertarItem(Producto* producto)
{
    int index = hashFunction(producto->obtenerNombreProducto());
    
    for(int i = 1; i < hashGroups + 1; i++){
       if(i == index){
           listaProductos[index]->agregarAlPrincipio(producto); 
        }
    }
}

void HashMap::eliminarItem(Producto* producto)
{

    Node* nodoActual = nullptr;

    int index = hashFunction(producto->obtenerNombreProducto());
    if(buscarItem(producto)){
        for(int i = 0; i < hashGroups; i++){
            if(i == index){
                nodoActual = listaProductos[index]->obtenerNodo(producto);
                listaProductos[index]->eliminarNodo(nodoActual);
            }
        }
    }
    if(nodoActual != nullptr) delete nodoActual;

}

bool HashMap::buscarItem(Producto* producto)
{
    int index = hashFunction(producto->obtenerNombreProducto());

    for(int i = 0; i < hashGroups; i++){
        if(i == index){
            if(listaProductos[index]->buscarElemento(producto)) return true;
        }
    }
    return false;
}

void HashMap::desplegarMap()
{
    for(int i = 0; i < hashGroups; i++){
        for(int j = 0; j < listaProductos[i]->size(); j++){
            Node* nodoActual = listaProductos[i]->obtenerPrimerNodo();
            cout<<"Producto: "<< nodoActual->producto->obtenerNombreProducto()<<endl;
            nodoActual = nodoActual->next;
        } 
    }
    
}

HashMap::~HashMap()
{
    for(int i = 0; i < hashGroups; i ++){
        delete listaProductos[i];
    }
        delete[] listaProductos;
}
