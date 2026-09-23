# EDP-Platform-Arduino Developer Wiki

EDP-Platform-Arduino owns Arduino-API-specific integrations for EDP-Platform. Its current substantive surface is conversion between Arduino `String` and EDP bounded string types.

This Wiki is maintained beside the code on `main`. Source code and repository `docs/` remain the normative implementation and durable contract sources; the Wiki is the internal developer navigation and explanation layer.

## Public entry point

```cpp
#include <ESPressio_Platform_Arduino_Bounded.hpp>
```

## Dependencies

Mandatory: EDP-Platform. EDP-BoundedTypes is required for the bounded-string integration surface.

## Developer map

Use [Architecture](Architecture.md), [Public API](Public-API.md), [Internal API](Internal-API.md), [Implementation](Implementation.md), [Composition](Composition.md), [Resources / Lifecycle / Concurrency](Resources-Lifecycle-Concurrency.md), and [Build / Test / Source](Build-Test-Source.md).
