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
    Client::setHost(myhost);
    Client::setPort(myport);
    string UUIDEspacio=ManejadorJson::xmalloc(this->Tipo,this->token,"xmalloc",size);
    cout<<"UUIDEspacio:"<<UUIDEspacio<<endl;
    xReference<API::xType > *referencia= new xReference<API::xType >(UUIDEspacio,size,type);
    return referencia;
}


xReference<API::xType>* API::xMalloc(int size, xType type, void *value) {
    Client::setHost(myhost);
    Client::setPort(myport);
    string datoalmacenado;
    if(type==API::Entero){
        int datocasteado;
        datocasteado = * (int* )value;
        string datoalmacenar;
        stringstream convert;
        convert << datocasteado;
        datoalmacenar = convert.str();
        cout<<"Dato almacenar int:"<<datoalmacenar<<endl;
        datoalmacenado=datoalmacenar;
    }if(type==API::Decimal){
        float datocasteado;
        datocasteado = * (float *) value;
        std::ostringstream ss;
        ss << datocasteado;
        std::string datoalmacenar(ss.str());
        cout<<"Dato almacenar float:"<<datoalmacenar<<endl;
        datoalmacenado=datoalmacenar;
    }if(type==API::Caracter){
        char *casteador;
        casteador = (char *) value;
        std::string datoalmacenar(casteador);
        cout<<"Dato almacenar char:"<<datoalmacenar<<endl;
        datoalmacenado=datoalmacenar;
    }if(type==API::Double){
        double datocasteado;
        datocasteado= *(double*)value;
        std::ostringstream strs;
        strs << datocasteado;
        std::string datoalmacenar = strs.str();
        cout<<"Dato almacenar double:"<<datoalmacenado<<endl;
        datoalmacenado=datoalmacenar;
    }
    string datocodificado=base64_encode(reinterpret_cast<const unsigned char*>(datoalmacenado.c_str()),datoalmacenado.length());
    string UUIDEspacio = ManejadorJson::xMalloc(this->Tipo,this->token,"xMalloc2",size,datocodificado);
    cout<<"UUIDEspacio:"<<UUIDEspacio<<endl;
    xReference<API::xType > *referencia= new xReference<API::xType >(UUIDEspacio,size,type);
    return referencia;
}

void API::xFree(xReference<API::xType> *toFree) {
    string UUIDEspacio = toFree->ID;
    ManejadorJson::xFree(this->Tipo, this->token, "xFree", UUIDEspacio);
}


