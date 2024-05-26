#include "include\Cliente.h"
#include "include\ClientePreferencial.h"

using namespace std;

ClientePreferencial::ClientePreferencial(string atributo){

}

ClientePreferencial::~ClientePreferencial(){

}

string ClientePreferencial::getAtributo() const{
    return atributo;
}

void ClientePreferencial::setAtributo(int numero){

    switch(numero){
        case 1:
            this->atributo = "tercera edad";
            this->prioridad = 1;
            break;
        case 2:
            this->atributo = "discapacidad";
            this->prioridad = 2;
            break;

        case 3:
            this->atributo = "embarazada";
            this->prioridad = 3;
            break;
    }

}

int ClientePreferencial::getPrioridad() const
{
    return prioridad;
}
