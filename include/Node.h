#include <iostream>

#include "Producto.h"

using namespace std;

class Node {

    public:
        Producto* producto;
        Node* next;
        Node* anterior;
        Node(Producto* producto);
        
};