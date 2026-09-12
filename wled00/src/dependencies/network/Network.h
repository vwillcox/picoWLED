#ifdef ESP8266
  #include <ESP8266WiFi.h>
#elif defined(ARDUINO_ARCH_RP2040)
  #include <WiFi.h> // no ETH.h equivalent - wired ethernet is not supported on this platform
#else // ESP32
  #include <WiFi.h>
  #include <ETH.h>
#endif

#ifndef Network_h
#define Network_h

class WLEDNetworkClass
{
public:
  IPAddress localIP();
  IPAddress subnetMask();
  IPAddress gatewayIP();
  void localMAC(uint8_t* MAC);
  bool isConnected();
  bool isEthernet();
};

extern WLEDNetworkClass WLEDNetwork;

#endif