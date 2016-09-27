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
    string token = Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(json, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON in initialize" << endl << reader.getFormatedErrorMessages() << endl;
    }
    return token;
}

void ManejadorJson::xMalloc(string tipo, string token, string accion, int size){
    string strInt;
    stringstream convert;
    convert << size;
    strInt = convert.str();
    string json = "{\"Tipo\":\""+tipo+"\",\"Token\":\""+token+"\",\"Accion\":\""+accion+"\",\"Size\":\""+strInt+"}";
    Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(json, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }

}

void ManejadorJson::xMalloc(string tipo,string token, string accion, int size, string dato){
    string strInt;
    stringstream convert;
    convert << size;
    strInt = convert.str();
    string json = "{\"Tipo\":\""+tipo+"\",\"Token\":\""+token+"\",\"Accion\":\""+accion+"\",\"Size\":\""+strInt+"\",\"Dato\":\""+dato+"}";
    Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(json, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }
}


void ManejadorJson::xAssign(string tipo, string token, string accion, string dato, string id){

    string json = "{\"Tipo\":\""+tipo+"\",\"Token\":\""+token+"\",\"Accion\":\""+accion+"\",\"Dato\":\""+dato+"\",\"UUID\":\""+id+"}";
    string mensaje = Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(json, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }
}

void ManejadorJson::xFree(string tipo,string token, string accion, string id){
    string json = "{\"Tipo\":\""+tipo+"\",\"Token\":\""+token+"\",\"Accion\":\""+accion+"\",\"UUID\":\""+id+"}";
    Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(json, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }

}



