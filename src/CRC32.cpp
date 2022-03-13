#include "CRC32.h"

void crc32::setPolynomial(uint32_t poly){
    polynomial = poly;
}
uint32_t crc32::getPolynomial(){
    return polynomial;
}
uint32_t crc32::calculator(const char *input, uint16_t lenght){
    uint32_t crc32 = 0xFFFFFFFF;
    for(uint16_t i = 0 ; i < lenght ; i++){
        crc32 ^= input[i];
        for(int bit = 0; bit < 8 ;bit++){
            if(crc32 & 1){
                crc32 = (crc32 >> 1) ^ polynomial;
            }
            else{
                crc32 >>= 1;
            }
        }
    }
    return ~crc32;
}

bool crc32::check(const char *playload_input, uint16_t playload_lenght, uint32_t crc32){
    uint32_t crc32_cal = crc32::calculator(playload_input, playload_lenght);
    if (crc32_cal == crc32)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool crc32::strCheckCrc(String msgpayload){
    bool crcCheckStatus = false;
    uint8_t lastpoint = 0;
    uint8_t nextpoint = 0;
    String msgCRC = "";

    

    lastpoint = msgpayload.indexOf("[") + 1;
    nextpoint = msgpayload.indexOf("]");

    msgCRC = msgpayload.substring(lastpoint,nextpoint);
    lastpoint = msgpayload.indexOf("{");
    nextpoint = msgpayload.indexOf("}") + 2;
    strmsg = msgpayload.substring(lastpoint,nextpoint);
    uint32_t crc32 = strtoul(msgCRC.c_str(),nullptr,16);
    crcCheckStatus = crc32::check(strmsg.c_str(),strmsg.length(),crc32);
    
    if(!crcCheckStatus)
    {
        crc32::deleteStrmsg();
    }
    return crcCheckStatus;
}

String crc32::getStrmsg(){
    return strmsg;
}

void crc32::deleteStrmsg(){
    strmsg ="";
}