#include <iostream>
#include "Client.h"
#include <jsoncpp/json.h>
#include "ManejadorJson.h"
/*string token;
enum xType {String, Entero, Decimal, Caracter};

void *worker_thread(void *arg)
{
    printf("This is worker_thread()\n");
    pthread_exit(NULL);
}

char* initialize(char* host, int port){

}
template <typename T> xReference xMalloc(int size, xType type){

    xReference<T> hola("UXCCJSHDDE",2);
    return hola;

}*/


int main() {
    int puerto;
    char host[256];
    cout<<"Introduzca el IP del manager: "<<endl;
    cin>>host;
    cout<<"Introduzca el puerto en el que escucha el manager"<<endl;
    cin>>puerto;
    Client::setHost(host);
    Client::setPort(puerto);
    ManejadorJson::crearJson("","Guardar");
    return 0;
}