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
public:
    typedef enum tipos {String, Entero, Decimal, Caracter} xType;
    API();
    virtual ~API();
    char* initialize(char* host, int port);

    template<typename T>
    xReference<T>* xMalloc(int size, xType type);
    template<typename T>
    xReference<T>* xMalloc(int size, xType type,void* value);
    template<typename T>
    static void xAssign(xReference<T> &reference, void* value);
    template<typename T>
    void xFree(xReference<T> &toFree);

};


#endif //MESH_MEM_API_H
