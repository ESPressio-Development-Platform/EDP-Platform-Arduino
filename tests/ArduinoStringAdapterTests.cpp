#include <cassert>

#include <Arduino.h>

#include <ESPressio_Platform_Arduino_Bounded.hpp>

namespace Test {

    /// Verifies Arduino String conversion in both directions.
    int Run() {
        ::String source("ESPressio");
        ESPressio::Bounded::String<16U> bounded;

        assert(
            bounded.CastFrom(
                source
            ) == ESPressio::Bounded::ArduinoStringToBoundedStringResult::Succeeded
        );

        assert(
            bounded.Size() == 9U
        );

        ::String target("unchanged");

        assert(
            bounded.CastTo(
                target
            ) == ESPressio::Bounded::BoundedStringToArduinoStringResult::Succeeded
        );

        assert(
            target == "ESPressio"
        );

        ESPressio::Bounded::String<4U> tooSmall;

        assert(
            tooSmall.CastFrom(
                source
            ) == ESPressio::Bounded::ArduinoStringToBoundedStringResult::CapacityExceeded
        );

        assert(
            tooSmall.IsEmpty()
        );

        return 0;
    }

} // Test
