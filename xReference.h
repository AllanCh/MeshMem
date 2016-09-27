//
// Created by dilan on 11/09/16.
//

#ifndef MESH_MEM_XREFERENCE_H
#define MESH_MEM_XREFERENCE_H

#include <typeinfo>
#include<iostream>
#include<string>

using namespace std;

template <typename T> class xReference {

private:
    string ID;
    T dato;
    int Size;

public:
    typedef enum tipos {String, Entero, Decimal, Caracter} xType;
    xReference(string id, int size){
        ID=id;
        Size=size;
    }
    xReference(string id, int size, T t){
        dato=t;
        ID=id;
        Size=size;
    }

    const char* getTypeName(){
        return typeid(T).name();
    }

    T& operator*(){
    }

    bool operator==(xReference &D){
        if(ID.compare(D.ID)==0){
            return true;
        }else{
            return false;
        }
    }


    bool operator!=(xReference &D){
        if(ID.compare(D.ID)==0){
            return false;
        }else{
            return true;
        }
    }

};


#endif //MESH_MEM_XREFERENCE_H
