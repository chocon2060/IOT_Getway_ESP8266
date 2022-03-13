#ifndef ProtocolConvert_H
#define ProtocolConvert_H
#include <stdint.h>
#include <Arduino.h>
#include <ArduinoJson.h>
class ProtocolConvert {  
    private:
        StaticJsonDocument<256> doc;
        String cmd;
        String dataAddress;
    public:
        void configjson();
        void Convert(String msgPayload);
        void toClient(String jsonMsg);
        void toGetway(String jsonMsg);
};
#endif