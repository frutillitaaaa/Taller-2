#include "Lista.h"

Lista::Lista()
{
    Node* first = nullptr;
}

Lista::~Lista()
{
}

bool Lista::isEmpty()
{
    if(first == nullptr) return true;
    return false;
}

void Lista::agregarAlPrincipio(Node* nodo, Producto* producto)
{
   
    Node* nuevoNodo = new Node(producto);
    if(!isEmpty()){
        nuevoNodo->next = first;
        first->anterior = nuevoNodo;
    } 
    first = nuevoNodo;

}

void Lista::eliminarNodo(Node* nodo, Producto* producto)
{
    if(!isEmpty()){
        nodo->anterior->next = nodo->next;
        nodo->next->anterior = nodo->anterior;

        delete nodo;
    } 
}
