# Demos

- `bounded-string-conversion` — explicit Arduino `String` to/from `Bounded::String<N>` conversion using the Arduino-owned adapter specializations.

The demo provides Arduino IDE, PlatformIO Arduino and PlatformIO ESP-IDF-targeted variants. The ESP-IDF variant uses Arduino as an ESP-IDF component because Arduino `String` is the external Type being demonstrated.

## C++ Language Baseline

The PlatformIO-compatible variants require C++20 and explicitly select the maintained PIOArduino ESP32 platform package. PIOArduino is the recommended Arduino-ESP32 environment for ESPressio.
