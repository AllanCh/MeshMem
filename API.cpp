//
// Created by dilan on 26/09/16.
//

#include "API.h"



API::API() {}

API::~API() {}

char* API::initialize(char *host, int port) {
    this->myhost=host;
    this->myport=port;
    Client::setHost(myhost);
    Client::setPort(myport);
    this->token=ManejadorJson::initialize(this->Tipo,"Conexion");
}


xReference<API::xType >* API::xMalloc(int size, xType type) {
    //aqui se debe obtener el ID de la ubicacion de la memoria en el celular
    cout<<"Antes de pedir el UUID"<<endl;
    Client::setHost(myhost);
    Client::setPort(myport);
    string UUIDEspacio=ManejadorJson::xmalloc(this->Tipo,this->token,"xmalloc",size);
    cout<<"Despues de pedirel UUID:"<<UUIDEspacio<<endl;
    xReference<API::xType > *referencia= new xReference<API::xType >(UUIDEspacio,size,type);
    return referencia; 
}


