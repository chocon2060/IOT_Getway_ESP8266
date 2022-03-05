#ifndef configuration
#define configuration
// setting wifi 
    const char* ssid = "200k";
    const char* password = "qwertyuiop";
// setting mqtt url
    const char* mqtt_server = "test.mosquitto.org";
    const char* topic_pub = "HOME/client";
    const char* topic_sub = "HOME/sever";
    const uint16_t port = 1883;  // port number for mqtt server

    #define NumGateway 1

    #define BUILTIN_LED 2       // config led wifi status

    #define Polynomial 0xEDB88320 // Crc32 poly
#endif