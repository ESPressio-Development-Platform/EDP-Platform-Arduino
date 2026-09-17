# EDP-Platform-Arduino Dependency Graph

## Library Dependency Tree

```text
EDP-Platform-Arduino
└── EDP-Platform [mandatory]
    └── EDP-System [mandatory, transitive]
```

## Mandatory Dependencies

- `EDP-Platform` — owns the platform-neutral capability contracts implemented by this Arduino backend.
- `EDP-System` — transitive through `EDP-Platform` for Composition.

## Optional Dependencies

There are currently no optional ESPressio library dependencies.

The Arduino framework/toolchain and its C++ standard atomic implementation are target facilities, not ESPressio library dependencies.
