#include <iostream>
#include "Client.h"
#include <pthread.h>

void *worker_thread(void *arg)
{
    printf("This is worker_thread()\n");
    pthread_exit(NULL);
}

int main() {
    std::cout<<"Bienvenido"<<std::endl;
    while(true){
        Client::iniciar(NULL);
    }
    return 0;
}