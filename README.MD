# ESPressio Platform - Arduino

`EDP-Platform-Arduino` supplies Arduino-environment concrete implementations and Arduino-owned integration adapters for the ESPressio Development Platform.

## Contents

- [AtomicWord32 Provider](./docs/ATOMIC-WORD32.MD)  
  Supplies the lock-free four-byte `AtomicWord32` capability required by Platform read-mostly concurrency facilities such as `ConcurrentSnapshot`.
- [Arduino String / Bounded String Conversion](./docs/ARDUINO-STRING-BOUNDED-CONVERSION.MD)  
  Supplies the optional `TypeConversionAdapter` specializations that convert between Arduino `::String` and `ESPressio::Bounded::String<N>` without adding Arduino dependencies to `EDP-BoundedTypes`.

## Dependencies

    EDP-Platform-Arduino
    ├── EDP-Platform [mandatory]
    │   └── EDP-System [mandatory, transitive]
    └── EDP-BoundedTypes [optional]
        condition: required only when Arduino String / Bounded String conversion integration is included or used

See [DEPENDENCY_GRAPH.MD](./DEPENDENCY_GRAPH.MD) for the maintained dependency graph.

## Bounded String integration

Include the explicit integration surface:

    #include <ESPressio_Platform_Arduino_Bounded.hpp>

The library exposing Arduino `String` owns these adapters. `EDP-BoundedTypes` therefore remains platform-neutral and dependency-free with respect to Arduino.

## Demos

Demonstrations are available under [`./demos`](./demos):

- `atomic-word-basic` — Arduino `AtomicWord32` concrete provider;
- `bounded-string-conversion` — Arduino `String` to/from `Bounded::String<N>` conversion.

Each logical demo provides Arduino IDE, PlatformIO Arduino, and PlatformIO ESP-IDF-targeted surfaces. The bounded-string ESP-IDF-targeted demo uses Arduino as an ESP-IDF component because the demonstrated external Type is specifically Arduino `String`.

## Development Status

Platform capabilities are added only where Arduino has a concrete responsibility. Arduino-specific Type integrations are likewise owned here rather than introducing platform dependencies into foundation libraries.
