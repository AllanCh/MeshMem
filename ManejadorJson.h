//
// Created by allan on 13/09/16.
//

#ifndef MESH_MEM_MANEJADORJSON_H
#define MESH_MEM_MANEJADORJSON_H

#include <iostream>
#include "Client.h"
#include <jsoncpp/json.h>
using namespace std;

class ManejadorJson {
public:
    static void crearJson(string, string );
    static void leerJson(string);

};


#endif //MESH_MEM_MANEJADORJSON_H
