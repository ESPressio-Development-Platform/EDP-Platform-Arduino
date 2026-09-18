#include <ESPressio_Platform_Arduino_Bounded.hpp>

/// Runs the bounded String conversion demonstration once.
void setup() {
    Serial.begin(115200);

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

/// Leaves the demonstration idle after setup has completed.
void loop() {
}
