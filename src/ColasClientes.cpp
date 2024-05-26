#include "include\ColasClientes.h"

ColasClientes::ColasClientes(){
    
}

ColasClientes::~ColasClientes(){

}



queue<ClienteNormal> ColasClientes::obtenerColaClientesNormales()
{
    return queue<ClienteNormal>();
}

queue<ClientePreferencial> ColasClientes::obtenerColaClientesPreferenciales()
{
    return queue<ClientePreferencial>();
}

void ColasClientes::agregarClienteAColaNormal(ClienteNormal* cliente)
{
    colaClientesNormales.push(*cliente);
    cout<<colaClientesNormales.size()<<endl;
    
}

void ColasClientes::agregarClienteAColaPreferencial(ClientePreferencial *cliente)
{
    queue <ClientePreferencial> colaAux;
    ClientePreferencial* c = &colaClientesPreferenciales.front();

    int numPersonas = colaClientesPreferenciales.size();
    

    if(cliente->getPrioridad()< c->getPrioridad() && colaClientesPreferenciales.size() < 2){
        colaAux.push(*cliente);
        colaAux.push(*c);
        colaAux.swap(colaClientesPreferenciales);
    } else if(colaClientesPreferenciales.size()>= 2){

        if(cliente->getPrioridad()< colaClientesPreferenciales.back().getPrioridad() && cliente->getPrioridad()> colaClientesPreferenciales.front().getPrioridad()){

            while(colaClientesPreferenciales.empty() == false){
                if(cliente->getPrioridad() > colaClientesPreferenciales.front().getPrioridad() ){
                    colaAux.push(colaClientesPreferenciales.front());
                    colaClientesPreferenciales.pop();
                }
                else if(cliente->getPrioridad() < colaClientesPreferenciales.front().getPrioridad()){
                    colaAux.push(*cliente);
                    colaAux.push(colaClientesPreferenciales.front());
                    colaClientesPreferenciales.pop();
                } else{
                    colaAux.push(colaClientesPreferenciales.front());
                    colaClientesPreferenciales.pop();
                }
            }
        } else if(cliente->getPrioridad()< colaClientesPreferenciales.back().getPrioridad() && cliente->getPrioridad()< colaClientesPreferenciales.front().getPrioridad()){
            colaAux.push(*cliente);
            
            while(colaClientesPreferenciales.empty() == false){
            colaAux.push(colaClientesPreferenciales.front());
            colaClientesPreferenciales.pop();
            }
            colaAux.swap(colaClientesPreferenciales);

        }

    
        for(int i = 0; i < numPersonas-1; i++){
            colaAux.push(colaClientesPreferenciales.front());
            colaClientesPreferenciales.pop();
        }
        colaAux.push(*cliente);
        colaAux.push(colaClientesPreferenciales.front());
        colaAux.swap(colaClientesPreferenciales);
    } else{
        colaClientesPreferenciales.push(*cliente);
    }
        

    cout<<colaClientesPreferenciales.size();
    cout<<colaClientesPreferenciales.front().getAtributo();
    cout<<colaClientesPreferenciales.front().getPrioridad();

    
}
