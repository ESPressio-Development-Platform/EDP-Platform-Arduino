# Arduino Integration Tests

`ArduinoStringAdapterTests.cpp` verifies Arduino `String` conversion to and from `ESPressio::Bounded::String<N>`, including capacity-failure atomicity.

The test requires the optional `EDP-BoundedTypes` integration dependency.
