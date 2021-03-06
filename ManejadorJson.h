//
// Created by allan on 13/09/16.
//

#ifndef MESH_MEM_MANEJADORJSON_H
#define MESH_MEM_MANEJADORJSON_H

#include <iostream>
#include "Client.h"
#include "json/json.h"
#include "base64.h"
using namespace std;

class ManejadorJson {
public:
    static string initialize(string,string);
    static void leerJson(string);
    static string xmalloc(string,string, string ,int);
    static string xMalloc(string,string, string, int, string);
    static void xAssign(string,string, string, string, string);
    static void xFree(string,string, string, string);

};


#endif //MESH_MEM_MANEJADORJSON_H
