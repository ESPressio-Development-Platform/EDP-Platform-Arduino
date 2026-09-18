# Arduino String / Bounded String Conversion

## Purpose and scope

`EDP-Platform-Arduino` owns the optional conversion bridge between Arduino `::String` and `ESPressio::Bounded::String<N>`.

The bridge is intentionally implemented here rather than in `EDP-BoundedTypes`: the library exposing the external Arduino Type owns the conversion support, while `EDP-BoundedTypes` remains unaware of Arduino.

This integration is a conversion-adapter extension, not a Platform Composition capability. It participates in the `EDP-BoundedTypes` `TypeConversionAdapter` seam when the integration header is explicitly included.

## Enabling the integration

Include:

```cpp
#include <ESPressio_Platform_Arduino_Bounded.hpp>
```

This header requires both the Arduino `WString` API and `EDP-BoundedTypes`.

The optional `EDP-BoundedTypes` dependency is therefore imposed only when the bounded Arduino integration surface is included or used.

## Arduino String to Bounded String

```cpp
ESPressio::Bounded::String<32> bounded;
String arduino("example");

const auto result = bounded.CastFrom(
    arduino
);
```

The adapter first validates the Arduino source state and then delegates bounded publication to `Bounded::String<N>::Assign()` using the source pointer plus its explicit Arduino length.

The possible adapter results are:

```text
Succeeded
CapacityExceeded
EmbeddedNullNotPermitted
SourceInvalid
```

Capacity overflow and embedded null bytes are rejected. An invalid Arduino String state is reported as `SourceInvalid`.

A non-success result leaves the bounded target's logical value unchanged.

## Bounded String to Arduino String

```cpp
String arduino;

const auto result = bounded.CastTo(
    arduino
);
```

The adapter validates that the bounded payload length can be represented by the Arduino `String` length API, then prepares a temporary Arduino `String` candidate.

The candidate must successfully reserve the complete required capacity and accept the complete payload before it is move-published to the caller's target.

The possible adapter results are:

```text
Succeeded
SourceSizeUnsupported
TargetCapacityUnavailable
TargetWriteFailed
```

A reserve or payload-write failure leaves the existing Arduino target unchanged.

## Memory and ownership behavior

`Bounded::String<N>` remains fixed-capacity and allocation-free.

Converting from Arduino `String` into a bounded String does not transfer ownership of the Arduino buffer into the bounded value; the payload is copied into the bounded value's inline storage.

Converting from a bounded String into Arduino `String` deliberately uses Arduino `String` allocation behavior. The temporary Arduino candidate may allocate dynamic storage through the Arduino implementation. This integration therefore must not be interpreted as making Arduino `String` memory-bounded.

The temporary candidate is used to preserve the strong publication guarantee: the caller's target is replaced only after the complete conversion has succeeded.

## Failure and exception semantics

The adapter result Types are operation-specific strongly typed enums.

`TypeConversionAdapter` advertises `IsNoexcept = false` in both directions because the Arduino `String` API used by the bridge does not declare the complete operation sequence `noexcept`.

The adapter does not collapse allocation/capacity/write failures into a Boolean result and does not silently truncate payloads.

## Thread-safety boundary

The adapter introduces no mutex, atomic state, task, or registry.

It does not make either participating object safe for concurrent mutation. Normal ownership and synchronization rules of the consuming application apply.

## Supported and unsupported integration

Currently supported:

```text
Arduino ::String -> Bounded::String<N>
Bounded::String<N> -> Arduino ::String
```

Not currently provided by this integration:

```text
implicit conversion operators
Arduino String / Bounded::Bytes<N> conversion
shared ownership of Arduino String storage
zero-copy aliasing into Arduino String memory
thread-safety wrappers
```

Additional external-Type adapters should remain owned by the library exposing that external Type rather than being added to `EDP-BoundedTypes`.

## Dependency boundary

`EDP-BoundedTypes` is an optional dependency of `EDP-Platform-Arduino` and becomes required only when this conversion integration is included or used.

Ordinary `EDP-Platform-Arduino` use does not acquire an `EDP-BoundedTypes` dependency merely because this optional adapter exists.
