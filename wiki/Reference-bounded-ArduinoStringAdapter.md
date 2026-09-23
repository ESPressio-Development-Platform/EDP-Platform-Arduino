# src/bounded/ArduinoStringAdapter.hpp

**Primary classification:** PUBLIC PROVIDER / EXTENSION API

**Source baseline:** `b778c6661fd9a0f75d343a937683ed36b15e7978`

[Open exact source](https://github.com/ESPressio-Development-Platform/EDP-Platform-Arduino/blob/b778c6661fd9a0f75d343a937683ed36b15e7978/src/bounded/ArduinoStringAdapter.hpp)

## Direct includes

- `cstddef`
- `cstdint`
- `limits`
- `utility`
- `WString.h`
- `bounded/String.hpp`

## Documented declarations

### `ArduinoStringToBoundedStringResult`

**Classification:** PUBLIC PROVIDER / EXTENSION API

Describes the outcome of converting an Arduino String into a bounded String.

```cpp
enum class ArduinoStringToBoundedStringResult : std::uint8_t
```

### `Succeeded`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The Arduino String payload was published to the bounded String successfully.

```cpp
Succeeded = 0,
```

### `CapacityExceeded`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The Arduino String payload exceeds the bounded String's compile-time payload capacity.

```cpp
CapacityExceeded = 1,
```

### `EmbeddedNullNotPermitted`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The Arduino String payload contains an embedded null byte that bounded String does not permit.

```cpp
EmbeddedNullNotPermitted = 2,
```

### `SourceInvalid`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The Arduino String is invalid or cannot expose a valid payload representation.

```cpp
SourceInvalid = 3
    };
```

### `BoundedStringToArduinoStringResult`

**Classification:** PUBLIC PROVIDER / EXTENSION API

Describes the outcome of converting a bounded String into an Arduino String.

```cpp
enum class BoundedStringToArduinoStringResult : std::uint8_t
```

### `Succeeded`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The bounded String payload was published to the Arduino String successfully.

```cpp
Succeeded = 0,
```

### `SourceSizeUnsupported`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The bounded String payload cannot be represented by the Arduino String length parameter Type.

```cpp
SourceSizeUnsupported = 1,
```

### `TargetCapacityUnavailable`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The Arduino String could not reserve the storage required for the complete bounded payload.

```cpp
TargetCapacityUnavailable = 2,
```

### `TargetWriteFailed`

**Classification:** PUBLIC PROVIDER / EXTENSION API

The Arduino String rejected the payload after capacity had been reserved.

```cpp
TargetWriteFailed = 3
    };
```

### `TypeConversionAdapter`

**Classification:** PUBLIC PROVIDER / EXTENSION API

Converts Arduino String values into bounded Strings while preserving bounded String invariants.

```cpp
template<std::size_t TCapacity>
    struct TypeConversionAdapter<::String, String<TCapacity>> final
```

### `ResultType`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Defines the operation-specific result Type returned by this adapter.

```cpp
using ResultType = ArduinoStringToBoundedStringResult;
```

### `IsAvailable`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Indicates that Arduino String to bounded String conversion is available when this adapter header is included.

```cpp
static constexpr bool IsAvailable = true;
```

### `IsNoexcept`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Indicates that the Arduino String API does not declare every operation used by this adapter as noexcept.

```cpp
static constexpr bool IsNoexcept = false;
```

### `Convert`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Converts an Arduino String into a bounded String without modifying the target on failure.

```cpp
static ResultType Convert(
            const ::String& source,
            String<TCapacity>& target
        )
```

### `TypeConversionAdapter`

**Classification:** PUBLIC PROVIDER / EXTENSION API

Converts bounded Strings into Arduino String values while preserving the target on failure.

```cpp
template<std::size_t TCapacity>
    struct TypeConversionAdapter<String<TCapacity>, ::String> final
```

### `ResultType`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Defines the operation-specific result Type returned by this adapter.

```cpp
using ResultType = BoundedStringToArduinoStringResult;
```

### `IsAvailable`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Indicates that bounded String to Arduino String conversion is available when this adapter header is included.

```cpp
static constexpr bool IsAvailable = true;
```

### `IsNoexcept`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Indicates that the Arduino String API does not declare every operation used by this adapter as noexcept.

```cpp
static constexpr bool IsNoexcept = false;
```

### `Convert`

**Classification:** PUBLIC PROVIDER / EXTENSION API · source access: `public`

Converts a bounded String into an Arduino String and publishes only a fully prepared target value.

```cpp
static ResultType Convert(
            const String<TCapacity>& source,
            ::String& target
        )
```

