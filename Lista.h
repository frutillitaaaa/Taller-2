#pragma once

#include <iostream>

#include "Node.h"

using namespace std;

class Lista {

    private:
        Node* first;

    public:
        Lista();
        ~Lista();
        bool isEmpty() const;
        void agregarAlPrincipio(Producto* producto);
        void eliminarNodo(Node* nodo);
        Node* obtenerPrimerNodo();
        bool buscarElemento(Producto* producto);
        Node* obtenerNodo(Producto* producto);
        int size();
        void desplegarDatosGuardados();


};