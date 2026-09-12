#include "compat_content_types_rp2040.h"
#ifdef ARDUINO_ARCH_RP2040
#include <avr/pgmspace.h> // PROGMEM is not defined by Arduino.h alone on this platform

// Values mirror Aircoookie/ESPAsyncWebServer's src/ContentTypes.cpp exactly, for parity
// with the ESP32/ESP8266 builds. See compat_content_types_rp2040.h for why this exists.
const char CONTENT_TYPE_PLAIN[]      PROGMEM = "text/plain";
const char CONTENT_TYPE_HTML[]       PROGMEM = "text/html";
const char CONTENT_TYPE_CSS[]        PROGMEM = "text/css";
const char CONTENT_TYPE_JSON[]       PROGMEM = "application/json";
const char CONTENT_TYPE_JAVASCRIPT[] PROGMEM = "application/javascript";
const char CONTENT_TYPE_PNG[]        PROGMEM = "image/png";
const char CONTENT_TYPE_GIF[]        PROGMEM = "image/gif";
const char CONTENT_TYPE_JPEG[]       PROGMEM = "image/jpeg";
const char CONTENT_TYPE_XICON[]      PROGMEM = "image/x-icon";
const char CONTENT_TYPE_SVG[]        PROGMEM = "image/svg+xml";
const char CONTENT_TYPE_EOT[]        PROGMEM = "font/eot";
const char CONTENT_TYPE_WOFF[]       PROGMEM = "font/woff";
const char CONTENT_TYPE_WOFF2[]      PROGMEM = "font/woff2";
const char CONTENT_TYPE_TTF[]        PROGMEM = "font/ttf";
const char CONTENT_TYPE_XML[]        PROGMEM = "text/xml";
const char CONTENT_TYPE_PDF[]        PROGMEM = "application/pdf";
const char CONTENT_TYPE_ZIP[]        PROGMEM = "application/zip";
const char CONTENT_TYPE_GZIP[]       PROGMEM = "application/x-gzip";

#endif
