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
    T tipo;
    int Size;
    string datoalmacenado;

public:
    string ID;
    xReference(string id, int size,T type){
        ID=id;
        Size=size;
        tipo=type;
    }
    xReference(string id, int size, T type,string dato){
        datoalmacenado=dato;
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
