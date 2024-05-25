#pragma once

#include <queue>
#include <string>
#include <iostream>

#include "Cliente.h"
#include "ClienteNormal.h"
#include "ClientePreferencial.h"

using namespace std;

class ColasClientes {

    public:
    ColasClientes();
    ~ColasClientes();
    void agregarClienteAColaPreferencial(ClientePreferencial* cliente);
    void agregarClienteAColaNormal(ClienteNormal* cliente);
    queue<ClienteNormal>obtenerColaClientesNormales();
    queue<ClientePreferencial> obtenerColaClientesPreferenciales();

    private:
        queue<ClienteNormal> colaClientesNormales;
        queue<ClientePreferencial> colaClientesPreferenciales;


    
};