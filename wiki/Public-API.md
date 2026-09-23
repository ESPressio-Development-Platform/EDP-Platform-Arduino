# Public API

The public adapter surface converts Arduino `String` to `Bounded::String<N>` and back with typed results. Arduino-to-bounded conversion distinguishes success, capacity exceeded, embedded NUL and invalid source conditions. Bounded-to-Arduino conversion distinguishes unsupported source size, unavailable target capacity and failed target write.

The adapter is explicit and does not make Arduino allocation semantics part of EDP-BoundedTypes.

Exact declarations, template parameters and signatures remain authoritative in the headers exported by `ESPressio_Platform_Arduino_Bounded.hpp`.
