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

    xReference<API::xType>* mireference = prueba.xMalloc(32,prueba.Double);
    cout<<"Este es el id de mireference"<<mireference->ID<<endl;

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
    xReference<API::xType > *mireference6 = mireference5;
    cout<<(mireference5->operator!=(*mireference6))<<endl;

    prueba.xFree(mireference);

    prueba.xAssign(*mireference4, fPtr);




    return 0;
}