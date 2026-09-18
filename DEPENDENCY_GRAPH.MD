# EDP-Platform-Arduino Dependency Graph

## Library Dependency Tree

    EDP-Platform-Arduino
    ├── EDP-Platform [mandatory]
    │   └── EDP-System [mandatory, transitive]
    └── EDP-BoundedTypes [optional]
        condition: required only when Arduino String / Bounded String conversion integration is included or used

## Mandatory Dependencies

- `EDP-Platform` — owns the platform-neutral capability contracts implemented by this Arduino backend.
- `EDP-System` — transitive through `EDP-Platform` for Composition.

## Optional Dependencies

- `EDP-BoundedTypes` — required only when consuming `ESPressio_Platform_Arduino_Bounded.hpp` or `bounded/ArduinoStringAdapter.hpp` to convert between Arduino `::String` and `ESPressio::Bounded::String<N>`.

The Arduino framework/toolchain and its `String` implementation are target facilities, not ESPressio library dependencies.
