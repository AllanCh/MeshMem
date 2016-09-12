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
    string ID;
    int size;
    string storedata;

public:
    xReference(string id, int tamaño){
        ID=id;
        size=tamaño;
    }

    const char* getTypeName(){
        return typeid(T).name();
    }

    T& operator*(){
    }

    bool operator==(xReference &D){
        if(storedata.compare(D.storedata)==0){
            return true;
        }else{
            return false;
        }
    }




};


#endif //MESH_MEM_XREFERENCE_H
