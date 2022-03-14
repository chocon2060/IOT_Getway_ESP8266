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
    }else{
        ProtocolConvert::toClient(msgfor);
    }
    
}
void ProtocolConvert::toClient(String jsonMsg){
    DeserializationError error = deserializeJson(doc, jsonMsg);
    if(error){
        Serial.print("DeserializationError:");
        Serial.print(error.f_str());
        return;
    }
    id = doc["id"].as<uint8_t>();
    cmd = doc["cmd"].as<String>();
    dataAddress = doc["dataAddress"].as<String>();
// process ID lora client 
    loraId = id;
// process cmd 
    Serial.print("ID:");
    Serial.println(id);
    Serial.print("cmd:");
    Serial.println(cmd);
    Serial.print("dataAddress:");
    Serial.println(dataAddress);
// process lora data address 

}
uint8_t ProtocolConvert::stringconvert(String *listConvert){
    
}