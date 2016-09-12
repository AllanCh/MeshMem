#include <iostream>
#include "Client.h"
#include "xReference.h
#include "xReference.h"
#include <pthread.h>
#include <string>

using namespace std;

string token;
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

}

int main() {
    std::cout<<"Bienvenido"<<std::endl;
    while(true){
        Client::iniciar(NULL);
    }
    return 0;
}