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
        void agregarAlPrincipio(Node* nodo, Producto* producto);
        void eliminarNodo(Node* nodo, Producto* producto);

};