//
// Created by allan on 10/09/16.
//

#ifndef MESH_MEM_CLIENT_H
#define MESH_MEM_CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <string.h>

using namespace std;

class Client {

    static void error(const char*);
public:
    static void iniciar(const string);
};


#endif //MESH_MEM_CLIENT_H
