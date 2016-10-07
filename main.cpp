#include <iostream>
#include "API.h"

string token;



void *worker_thread(void *arg)
{
    printf("This is worker_thread()\n");
    pthread_exit(NULL);
}

char* initialize(char* host, int port){

}
/*xReference xMalloc(int size, xType type){

    //aqui se debe obtener el ID de la ubicacion de la memoria en el celular
    string id="UJFJDJFDJFD";

    if(type== String){
        xReference<string> referencia(id,size);
        return referencia;
    }if( type == Entero){
        xReference<int> referencia(id,size);
        return referencia;
    }if( type == Decimal){
        xReference<float> referencia(id,size);
        return referencia;
    }if( type == Caracter){
        xReference<char> referencia(id,size);
        return referencia;
    }else{
        return NULL;
    }

}*/


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