#include <iostream>
#include <string>

#include "Lista.h"

using namespace std;

class HashMap {

    private:
        static const int hashGroups = 10;
        Lista* listaProductos[hashGroups];
        
    public:
        int conversor(string clave);
        bool isEmpty() const;
        int hashFunction(string clave);
        void insertarItem(string clave, Producto* producto);
        void eliminarItem(string clave, Producto* producto);
        bool buscarItem(string clave, Producto* producto);
        void desplegarMap();
        ~HashMap();


};