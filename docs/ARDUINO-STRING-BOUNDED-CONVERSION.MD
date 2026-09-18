# Arduino String / Bounded String Conversion

`EDP-Platform-Arduino` owns the optional conversion bridge between Arduino `::String` and `ESPressio::Bounded::String<N>`.

The bridge is intentionally implemented here rather than in `EDP-BoundedTypes`: the library exposing the external Arduino Type owns the conversion support, while `EDP-BoundedTypes` remains unaware of Arduino.

## Enabling the integration

Include:

    #include <ESPressio_Platform_Arduino_Bounded.hpp>

This header requires both the Arduino `WString` API and `EDP-BoundedTypes`.

## Arduino String to Bounded String

    ESPressio::Bounded::String<32> bounded;
    String arduino("example");
    const auto result = bounded.CastFrom(arduino);

The conversion validates the complete Arduino payload before publishing it. Capacity overflow, embedded null bytes, and invalid Arduino String state are reported through `ArduinoStringToBoundedStringResult`. A non-success result leaves the bounded target unchanged.

## Bounded String to Arduino String

    String arduino;
    const auto result = bounded.CastTo(arduino);

The adapter first builds a temporary Arduino String, reserves the required capacity, copies the complete bounded payload, and only then move-publishes the candidate to the target. A reserve or write failure leaves the existing Arduino target unchanged.

The operation reports `BoundedStringToArduinoStringResult`.

## Dependency boundary

`EDP-BoundedTypes` is an optional dependency of `EDP-Platform-Arduino` and becomes required only when this conversion integration is included or used. Ordinary Platform-Arduino capability providers do not depend on it.
