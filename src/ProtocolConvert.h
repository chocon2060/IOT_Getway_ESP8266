#ifndef ProtocolConvert_H
#define ProtocolConvert_H
#include <stdint.h>
#include <Arduino.h>
#include <ArduinoJson.h>
class ProtocolConvert {  
    private:
        StaticJsonDocument<256> doc;
        uint8_t id;
        String cmd;
        String dataAddress;
        uint8_t loraId;
        uint8_t loraCmd;
        uint8_t loraDataAddress[50];
        void toClient(String jsonMsg);
        uint8_t stringconvert(String *listConvert);
    public:
        void configjson();
        void Convert(String msgPayload);
        
        // void toGetway(String jsonMsg);
};
#endif