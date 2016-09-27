//
// Created by allan on 13/09/16.
//

#include <sstream>
#include "ManejadorJson.h"
#include<iostream>
#include <sstream>

using namespace std;


string ManejadorJson::initialize(string tipo, string accion ) {
    string json = "{\"Tipo\":\""+tipo+"\",\"Accion\":\""+accion+"\"}";
    string jsonrecibido = Client::iniciar(json);
    cout<<"JSON recibido:"+jsonrecibido<<endl;
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(jsonrecibido, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON in initialize" << endl << reader.getFormatedErrorMessages() << endl;
    }
    string token = root["Token"].asString();
    string tokendecodificado = base64_decode(token);
    cout<< "Token:"<<tokendecodificado<<endl;
    cout<<"Token codificado"<< base64_encode(reinterpret_cast<const unsigned char*>(tokendecodificado.c_str()),tokendecodificado.length())<<endl;
    return token;
}

void ManejadorJson::xmalloc(string tipo, string token, string accion, int size){
    string strInt;
    stringstream convert;
    convert << size;
    strInt = convert.str();
    string json = "{\"Tipo\":\""+tipo+"\",\"Accion\":\""+accion+"\",\"Token\":\""+token+"\",\"Size\":\""+strInt+"}";
    string jsonrecibido = Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(jsonrecibido, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }

}

void ManejadorJson::xMalloc(string tipo,string token, string accion, int size, string dato){
    string strInt;
    stringstream convert;
    convert << size;
    strInt = convert.str();
    string json = "{\"Tipo\":\""+tipo+"\",\"Accion\":\""+accion+"\",\"Token\":\""+token+"\",\"Size\":\""+strInt+"\",\"Dato\":\""+dato+"}";
    string jsonrecibido = Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(jsonrecibido, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }
}


void ManejadorJson::xAssign(string tipo, string token, string accion, string dato, string id){

    string json = "{\"Tipo\":\""+tipo+"\",\"Accion\":\""+accion+"\",\"Token\":\""+token+"\",\"Dato\":\""+dato+"\",\"UUID\":\""+id+"}";
    string jsonrecibido = Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(jsonrecibido, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }
}

void ManejadorJson::xFree(string tipo,string token, string accion, string id){
    string json = "{\"Tipo\":\""+tipo+"\",\"Accion\":\""+accion+"\",\"Token\":\""+token+"\",\"UUID\":\""+id+"}";
    string jsonrecibido=Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(jsonrecibido, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }

}



