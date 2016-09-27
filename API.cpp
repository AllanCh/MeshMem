//
// Created by dilan on 26/09/16.
//

#include "API.h"



API::API() {}

API::~API() {}

char* API::initialize(char *host, int port) {
    Client::setHost(host);
    Client::setPort(port);
    this->token=ManejadorJson::initialize(this->Tipo,"Conexion");
}

template<typename T>
xReference<T>* API::xMalloc(int size, xType type) {
    //aqui se debe obtener el ID de la ubicacion de la memoria en el celular
    string id="UJFJDJFDJFD";

    if(type== String){
        xReference<string> *referencia= new xReference<string>(id,size);
        return referencia;
    }if( type == Entero){
        xReference<int> *referencia = new xReference<int>(id,size);
        return referencia;
    }if( type == Decimal){
        xReference<float>  *referencia = new xReference<float>(id,size);
        return referencia;
    }if( type == Caracter){
        xReference<char> *referencia = new xReference<char>(id,size);
        return referencia;
    }else{
        return NULL;
    }
}


