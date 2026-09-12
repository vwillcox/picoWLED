#pragma once
// WLED's own code (file.cpp, json.cpp, wled_server.cpp, src/dependencies/json/AsyncJson-v6.h)
// references CONTENT_TYPE_* PROGMEM string constants that, on ESP32/ESP8266, come from
// Aircoookie/ESPAsyncWebServer's ContentTypes.h/.cpp - a fork-only addition with no
// equivalent in upstream esp32async/ESPAsyncWebServer (used on RP2040/RP2350). This header
// + compat_content_types_rp2040.cpp provide the same symbols with the same values so that
// code doesn't need platform-specific changes.
#ifdef ARDUINO_ARCH_RP2040

extern const char CONTENT_TYPE_PLAIN[];
extern const char CONTENT_TYPE_HTML[];
extern const char CONTENT_TYPE_CSS[];
extern const char CONTENT_TYPE_JSON[];
extern const char CONTENT_TYPE_JAVASCRIPT[];
extern const char CONTENT_TYPE_PNG[];
extern const char CONTENT_TYPE_GIF[];
extern const char CONTENT_TYPE_JPEG[];
extern const char CONTENT_TYPE_XICON[];
extern const char CONTENT_TYPE_SVG[];
extern const char CONTENT_TYPE_EOT[];
extern const char CONTENT_TYPE_WOFF[];
extern const char CONTENT_TYPE_WOFF2[];
extern const char CONTENT_TYPE_TTF[];
extern const char CONTENT_TYPE_XML[];
extern const char CONTENT_TYPE_PDF[];
extern const char CONTENT_TYPE_ZIP[];
extern const char CONTENT_TYPE_GZIP[];

#endif
