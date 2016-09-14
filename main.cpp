#include <iostream>
#include "Client.h"
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
    std::cout<<"Bienvenido"<<std::endl;
    Client::iniciar("peera");
    return 0;
}