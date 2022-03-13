#include"ProtocolConvert.h"
void ProtocolConvert::configjson(){
   
    
}
void ProtocolConvert::Convert(String msgPayload){
    DeserializationError error = deserializeJson(doc, msgPayload);
    if(error){
        Serial.print("DeserializationError:");
        Serial.print(error.f_str());
        return;
    }

    String msgfor;
    msgfor = doc["client"].as<String>();
    if(msgfor == "null"){
        msgfor = doc["getway"].as<String>();
    }
    
}