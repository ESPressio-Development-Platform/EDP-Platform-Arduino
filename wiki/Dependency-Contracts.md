# Dependency Contracts

EDP-Platform-Arduino has one unconditional package dependency: **EDP-Platform**.

## EDP-Platform

The repository is an Arduino-specific integration package in the Platform family. It does not reimplement FreeRTOS synchronization merely because Arduino applications may run on FreeRTOS.

## Optional EDP-BoundedTypes surface

`ESPressio_Platform_Arduino_Bounded.hpp` includes the Arduino String conversion adapter and therefore requires **EDP-BoundedTypes** to be available to that build. This is an optional header-level dependency, not an unconditional package/runtime dependency.

The adapter specializes `EDP-BoundedTypes::TypeConversionAdapter` for:

- `::String -> Bounded::String<N>`;
- `Bounded::String<N> -> ::String`.

Arduino-to-bounded conversion preserves the bounded destination on failure. Bounded-to-Arduino conversion prepares a complete candidate before publishing it.

## Ownership boundary

Arduino `String` allocation behaviour remains owned by Arduino. The adapter must not cause BoundedTypes to claim Arduino memory behaviour as deterministic bounded storage.

> Dependency contract audit baseline: `6606a6bc6e05b17ac0cf50f06526561bf6617c38` (`main`).
