//
// Created by allan on 10/09/16.
//

#ifndef MESH_MEM_CLIENT_H
#define MESH_MEM_CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>



class Client {

    static void error(const char*);
public:
    static void* iniciar(void*);
};


#endif //MESH_MEM_CLIENT_H
