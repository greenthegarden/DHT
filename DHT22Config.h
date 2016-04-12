#ifndef DHT22CONFIG_H_
#define DHT22CONFIG_H_

// DHT22 temperature/humidty sensor library
#include <dht.h>


dht DHT;

const int DHT22_PIN                     = 3;

unsigned long dht22PreviousMillis       = 0UL;

const unsigned long DHT22_READ_INTERVAL = 5UL * 60UL * 1000UL;           // interval at which to take measurement (milliseconds)


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

void publish_temperature_measurement()
{
  progBuffer[0] = '\0';
  strcpy_P(progBuffer, (char*)pgm_read_word(&(STATUS_TOPICS[9])));
  DEBUG_LOG(3, "DHT22 temperature measurement: ");
  // value is stored in DHT object
  DEBUG_LOG(3, DHT.temperature);
  charBuffer[0] = '\0';
  dtostrf(DHT.temperature, 1, FLOAT_DECIMAL_PLACES, charBuffer);
  mqttClient.publish(progBuffer, charBuffer);
}

void publish_humidity_measurement()
{
  progBuffer[0] = '\0';
  strcpy_P(progBuffer, (char*)pgm_read_word(&(STATUS_TOPICS[10])));
  DEBUG_LOG(3, "DHT22 humidity measurement: ");
  // value is stored in DHT object
  DEBUG_LOG(3, DHT.humidity);
  charBuffer[0] = '\0';
  dtostrf(DHT.humidity, 1, FLOAT_DECIMAL_PLACES, charBuffer);
  mqttClient.publish(progBuffer, charBuffer);
}

byte void dht22_measurement(byte pin)
{
  return (DHT.read22(pin));
}


#endif  /* DHT22CONFIG_H_ */
