//
// Created by allan on 13/09/16.
//

#include "ManejadorJson.h"

void ManejadorJson::crearJson(string token, string accion ) {
    string json = "{\"Token\": \"" + token + "\" , \"Accion\": \"" + accion + "\"}";
    Client::iniciar(json);
    Json::Value root;
    Json::Reader reader;
    bool parsedSuccess = reader.parse(json, root, false);
    if (not parsedSuccess) {
        cout << "Failed to parse JSON" << endl << reader.getFormatedErrorMessages() << endl;
    }
}