#include <iostream>
#include <string>

#include "Lista.h"

using namespace std;

class HashMap {

    private:
        static const int hashGroups = 100;
        Lista* listaProductos[hashGroups];
        
    public:
        HashMap();
        int conversor(string clave);
        bool isEmpty() const;
        int hashFunction(string clave);
        void insertarItem(Producto* producto);
        void eliminarItem(Producto* producto);
        bool buscarItem(Producto* producto);
        void desplegarMap();
        ~HashMap();


};