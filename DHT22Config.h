#ifndef DHT22CONFIG_H_
#define DHT22CONFIG_H_

// DHT22 temperature/humidty sensor library
#include <DHT.h>


DHT dht;


// DHT22 status messages
const char DHT22_STATUS_OK[]        PROGMEM = "OK";
const char DHT22_CHECKSUM_ERROR[]   PROGMEM = "Checksum error";
const char DHT22_TIMEOUT_ERROR[]    PROGMEM = "Time out error";
const char DHT22_CONNECT_ERROR[]    PROGMEM = "Connect error";
const char DHT22_ACK_LOW_ERROR[]    PROGMEM = "Ack Low error";
const char DHT22_ACK_HIGH_ERROR[]   PROGMEM = "Ack High error";
const char DHT22_UNKNOWN_ERROR[]    PROGMEM = "Unknown error";

PGM_P const DHT22_STATUS_MESSAGES[] PROGMEM = { DHT22_STATUS_OK,        // idx = 0
                                                DHT22_CHECKSUM_ERROR,   // idx = 1
                                                DHT22_TIMEOUT_ERROR,    // idx = 2
                                                DHT22_CONNECT_ERROR,    // idx = 3
                                                DHT22_ACK_LOW_ERROR,    // idx = 4
                                                DHT22_ACK_HIGH_ERROR,   // idx = 5
                                                DHT22_UNKNOWN_ERROR,    // idx = 6
                                              };

byte dht22_reading(byte pin)
{
  return (dht.read22(pin));
}


#endif  /* DHT22CONFIG_H_ */
