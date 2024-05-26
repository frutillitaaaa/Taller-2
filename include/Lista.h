#include <iostream>

#include "Node.h"

using namespace std;

class Lista {

    private:
        Node* first = nullptr;

    public:
        Lista();
        ~Lista();
        bool isEmpty();
        void agregarAlPrincipio(Producto* producto);
        void eliminarNodo(Node* nodo);
        Node* obtenerPrimerNodo();
        bool buscarElemento(Producto* producto);
        Node* obtenerNodo(Producto* producto);


};