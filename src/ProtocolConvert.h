#ifndef ProtocolConvert_H
#define ProtocolConvert_H
#include <stdint.h>
#include <Arduino.h>
#include"configuration.h"
#include"CRC32.h"
class ProtocolConvert {  
    private:
        uint8_t loraMsg[50];
        uint8_t loraMsgLenght;
        uint8_t lastpoint = 0;
        uint8_t nextpoint = 0;
        String payloadSub[3];
        // crc32 crc;
    public:
        void serverToloraConvert(String msgPayload);
        void serverClientCmd(String msgPayload);
        void serverGetwayCmd(String msgPayload);
        bool isNumber(String str);
        void ProtocolConverError(String Error);
        
};
#endif