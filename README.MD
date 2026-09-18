# ESPressio Platform - Arduino

`EDP-Platform-Arduino` owns concrete implementations and integration adapters whose backing API is genuinely Arduino-specific.

## Current Arduino-owned integration

- [Arduino String / Bounded String Conversion](./docs/ARDUINO-STRING-BOUNDED-CONVERSION.MD)  
  Supplies the optional `TypeConversionAdapter` specializations that convert between Arduino `::String` and `ESPressio::Bounded::String<N>`.

No current synchronization or execution capability is implemented here because the relevant ESP32 mechanisms are FreeRTOS or ESP-IDF APIs rather than Arduino APIs.

Applications using Arduino-ESP32 may select providers from:

```text
EDP-Platform-FreeRTOS
EDP-Platform-ESP-IDF
EDP-Platform-Portable
```

through their application Composition without misclassifying those providers as Arduino implementations.

## Dependencies

```text
EDP-Platform-Arduino
├── EDP-Platform [mandatory]
│   └── EDP-System [transitive]
└── EDP-BoundedTypes [optional]
    condition: required only when Arduino String / Bounded String conversion integration is included or used
```

See [DEPENDENCY_GRAPH.MD](./DEPENDENCY_GRAPH.MD).

## Bounded String integration

Include the explicit integration surface:

```cpp
#include <ESPressio_Platform_Arduino_Bounded.hpp>
```

The library exposing Arduino `String` owns these adapters. `EDP-BoundedTypes` therefore remains free of Arduino dependencies.

## Demos

The `bounded-string-conversion` demo is provided under [`./demos`](./demos) for the policy-required Arduino IDE, PlatformIO Arduino and PlatformIO ESP-IDF-targeted surfaces.

## Provider Ownership

`AtomicWord32` was moved to `EDP-Platform-Portable` because its implementation uses only Standard C++ `std::atomic`.

Provider ownership follows the implementation API, not the framework through which that API happens to be available.
