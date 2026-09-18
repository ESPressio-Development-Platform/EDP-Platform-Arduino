# EDP-Platform-Arduino Dependency Graph

## Library Dependency Tree

```text
EDP-Platform-Arduino
├── EDP-Platform [mandatory]
│   └── EDP-System [transitive]
└── EDP-BoundedTypes [optional]
    condition: required only when Arduino String / Bounded String conversion integration is included or used
```

## Mandatory Dependencies

- `EDP-Platform` — defines the Platform abstraction vocabulary consumed by Arduino-owned integrations and any future Arduino-backed providers.

## Optional Dependencies

- `EDP-BoundedTypes` — required only when consuming `ESPressio_Platform_Arduino_Bounded.hpp` or `bounded/ArduinoStringAdapter.hpp`.

The Arduino framework and `String` Type are target facilities, not ESPressio library dependencies.
