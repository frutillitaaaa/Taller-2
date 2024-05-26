#include "Lista.h"

Lista::Lista()
{
    first = nullptr;
}

Lista::~Lista()
{
    Node* nodoActual = first;
    while(nodoActual != nullptr){
        Node* siguiente = nodoActual->next;
        delete nodoActual;
        nodoActual = siguiente;
    }
    first = nullptr;
}

bool Lista::isEmpty()
{
    if(first == nullptr) return true;
    return false;
}

void Lista::agregarAlPrincipio(Producto* producto)
{
   
    Node* nuevoNodo = new Node(producto);
    if(!isEmpty()){
        nuevoNodo->next = first;
        first->anterior = nuevoNodo;
    } 
    first = nuevoNodo;

    delete nuevoNodo;

}

void Lista::eliminarNodo(Node* nodo)
{
    if(!isEmpty()){
        nodo->anterior->next = nodo->next;
        nodo->next->anterior = nodo->anterior;

        delete nodo;
    } 
}

Node *Lista::obtenerPrimerNodo()
{
    if(!isEmpty()){
        return first;
    }
    return nullptr;
}

bool Lista::buscarElemento(Producto* producto)
{
    Node* nodoActual = first;
    if(!isEmpty()){
        while(nodoActual->next != nullptr){
            if(nodoActual->producto != producto){
                nodoActual = nodoActual->next;
            } else{
                return true;
            }
        }
    }
    
    return false;
}

Node* Lista::obtenerNodo(Producto* producto)
{
    Node* nodoActual = first;
    if(!isEmpty()){
        while(nodoActual->next != nullptr){
            if(nodoActual->producto != producto){
                nodoActual = nodoActual->next;
            } else{
                return nodoActual;
            }
        }
    }
    
    return nullptr;
}

int Lista::size()
{
    int contador = 0;
    Node* nodoActual = first;

    while(nodoActual->next != nullptr){
        nodoActual = nodoActual->next;
        contador++;
    }
    
    return contador;
}