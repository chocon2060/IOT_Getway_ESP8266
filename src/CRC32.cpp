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