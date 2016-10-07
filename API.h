//
// Created by dilan on 26/09/16.
//

#ifndef MESH_MEM_API_H
#define MESH_MEM_API_H

#include <iostream>
#include "xReference.h"
#include "Client.h"
#include "ManejadorJson.h"


using namespace std;

class API {

private:
    string token;
    string Tipo = "meshMemCLient";
    char* myhost;
    int myport;

public:
    enum xType {Double, Entero, Decimal, Caracter};

    API();
    virtual ~API();
    char* initialize(char* host, int port);

    xReference<API::xType >* xMalloc(int size,xType type);
    xReference<API::xType >* xMalloc(int size, xType type,void* value);
    void xAssign(xReference<API::xType> &reference, void* value);
    void xFree(xReference<API::xType> *toFree);

};


#endif //MESH_MEM_API_H
