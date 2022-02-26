#ifndef CRC32_H
#define CRC32_H
#include <stdint.h>
#include <Arduino.h>
class crc32 {
    private:
        uint32_t polynomial;
        String strmsg;
    public:
        void setPolynomial(uint32_t poly);
        uint32_t getPolynomial();
        uint32_t calculator(const char  *input, uint16_t lenght);
        bool check(const char *input, uint16_t lenght, uint32_t crc32);
        bool strCheckCrc(String msgpayload);

        String getStrmsg();
        void deleteStrmsg();
};
#endif