#ifndef ProtocolConvert_H
#define ProtocolConvert_H
#include <stdint.h>
#include <Arduino.h>
class ProtocolConvert {  
    private:
        uint8_t loraMsg[50];
        uint8_t loraMsgLenght;
        uint8_t lastpoint = 0;
        uint8_t nextpoint = 0;
        String payloadSub[3];
    public:
        void serverToloraConvert(String msgPayload);
        void serverClientCmd(String msgPayload);
        void serverGetwayCmd(String msgPayload);
        bool isNumber(String str);
        
};
#endif