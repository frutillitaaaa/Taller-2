#include <iostream>
#include <string>

#include "Lista.h"

using namespace std;

class HashMap {

    private:
        static const int hashGroups = 5;
        
    public:
        bool isEmpty() const;
        int hashFunction(int clave);
        void insertarItem(int clave, string valor);
        void eliminarItem(int clave);
        string buscarItem(int clave);
        void desplegarMap();

};