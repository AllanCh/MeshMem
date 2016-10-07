#include <iostream>
#include "API.h"

string token;



void *worker_thread(void *arg)
{
    printf("This is worker_thread()\n");
    pthread_exit(NULL);
}


int main() {
    int puerto;
    char host[256];
    cout<<"Introduzca el IP del manager: "<<endl;
    cin>>host;
    cout<<"Introduzca el puerto en el que escucha el manager"<<endl;
    cin>>puerto;
    API prueba;
    prueba.initialize(host,puerto);

    API::xType type =  prueba.String;
    xReference<API::xType>* mireference = prueba.xMalloc(32,type);
    cout<<"Este es el id de mireference"<<mireference->ID<<endl;

    return 0;
}