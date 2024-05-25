#pragma once

#include "Cliente.h"

#include <string>
#include <iostream>
#include <queue>

using namespace std;

class ClientePreferencial:public Cliente {

    private:
        string atributo;
        int prioridad;

    public:

        ClientePreferencial(string atributo);
        ~ClientePreferencial();
        string getAtributo() const;
        void setAtributo(int numero);
        int getPrioridad() const;
        
        
    


};