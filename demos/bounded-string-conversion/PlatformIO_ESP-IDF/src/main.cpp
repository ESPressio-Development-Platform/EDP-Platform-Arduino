#include <Arduino.h>
#include "sdkconfig.h"

#include <ESPressio_Platform_Arduino_Bounded.hpp>

/// Demonstrates round-trip conversion between Arduino String and a bounded String.
static void RunBoundedStringConversionDemo() {
    ESPressio::Bounded::String<32> bounded;
    String arduino("Arduino String");

    const auto inbound = bounded.CastFrom(arduino);

    if (inbound != ESPressio::Bounded::ArduinoStringToBoundedStringResult::Succeeded) {
        Serial.println("Arduino -> bounded conversion failed.");
        return;
    }

    const auto append = bounded.Append(" -> bounded");

    if (append != ESPressio::Bounded::StringAppendResult::Succeeded) {
        Serial.println("Bounded append failed.");
        return;
    }

    String roundTrip;
    const auto outbound = bounded.CastTo(roundTrip);

    if (outbound != ESPressio::Bounded::BoundedStringToArduinoStringResult::Succeeded) {
        Serial.println("Bounded -> Arduino conversion failed.");
        return;
    }

    Serial.println(roundTrip);
}

#if !CONFIG_AUTOSTART_ARDUINO

/// Starts the Arduino component explicitly when ESP-IDF does not autostart it.
extern "C" void app_main() {
    initArduino();
    Serial.begin(115200);
    RunBoundedStringConversionDemo();
}

#else

/// Runs the bounded String conversion demonstration once under Arduino autostart.
void setup() {
    Serial.begin(115200);
    RunBoundedStringConversionDemo();
}

/// Leaves the demonstration idle after setup has completed.
void loop() {
}

#endif
