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
    //prueba.initialize(host,puerto);

    API::xType type =  prueba.Caracter;
    //xReference<API::xType>* mireference = prueba.xMalloc(32,type);
    //cout<<"Este es el id de mireference"<<mireference->ID<<endl;

    int i = 10;
    int * iPtr = &i;

    double d = 10;
    double * dPtr = &d;

    float f = 10.67;
    float * fPtr = &f;

    char* sPtr =" Hello World";

    xReference<API::xType>* mireference2 = prueba.xMalloc(64,prueba.Entero,iPtr);
    xReference<API::xType>* mireference3 = prueba.xMalloc(64,prueba.Double,dPtr);
    xReference<API::xType>* mireference4 = prueba.xMalloc(64,prueba.Decimal,fPtr);
    xReference<API::xType>* mireference5 = prueba.xMalloc(64,prueba.Caracter,sPtr);

    //prueba.xFree(mireference);


    return 0;
}