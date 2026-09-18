# Demos

- `atomic-word-basic` — the Arduino `AtomicWord32` concrete provider.
- `bounded-string-conversion` — explicit Arduino `String` to/from `Bounded::String<N>` conversion using the Arduino-owned adapter specializations.

Each logical demo provides Arduino IDE, PlatformIO Arduino, and PlatformIO ESP-IDF-targeted variants. The bounded-string ESP-IDF variant uses Arduino as an ESP-IDF component because Arduino `String` is the external Type being demonstrated.
