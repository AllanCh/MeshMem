//
// Created by allan on 13/09/16.
//

#ifndef MESH_MEM_MANEJADORJSON_H
#define MESH_MEM_MANEJADORJSON_H

#include <iostream>
#include "Client.h"
#include <jsoncpp/json.h>
using namespace std;

template <typename T>class ManejadorJson {
public:
    static void crearJson(string, string );
    static void leerJson(string);
    static void xMalloc(string, string ,int);
    static void xMalloc(string, string, int, string);
    static void xAssign(string, string, string, string);
    static void xFree(string, string, string);

};


#endif //MESH_MEM_MANEJADORJSON_H
