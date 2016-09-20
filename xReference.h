//
// Created by dilan on 11/09/16.
//

#ifndef MESH_MEM_XREFERENCE_H
#define MESH_MEM_XREFERENCE_H

#include <typeinfo>
#include<iostream>
#include<string>

using namespace std;

template <class T> class xReference {

private:
    string ID;
    T dato;
    int size;
    typedef enum tipos {String, Entero, Decimal, Caracter} xType;

public:
    xReference();

    void SetValue(string id, T dato, int size ,xType type);

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
