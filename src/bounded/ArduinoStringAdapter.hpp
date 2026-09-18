#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <utility>

#include <WString.h>
#include <bounded/String.hpp>

namespace ESPressio::Bounded {

    /// Describes the outcome of converting an Arduino String into a bounded String.
    enum class ArduinoStringToBoundedStringResult : std::uint8_t {
        /// The Arduino String payload was published to the bounded String successfully.
        Succeeded = 0,
        /// The Arduino String payload exceeds the bounded String's compile-time payload capacity.
        CapacityExceeded = 1,
        /// The Arduino String payload contains an embedded null byte that bounded String does not permit.
        EmbeddedNullNotPermitted = 2,
        /// The Arduino String is invalid or cannot expose a valid payload representation.
        SourceInvalid = 3
    };

    /// Describes the outcome of converting a bounded String into an Arduino String.
    enum class BoundedStringToArduinoStringResult : std::uint8_t {
        /// The bounded String payload was published to the Arduino String successfully.
        Succeeded = 0,
        /// The bounded String payload cannot be represented by the Arduino String length parameter Type.
        SourceSizeUnsupported = 1,
        /// The Arduino String could not reserve the storage required for the complete bounded payload.
        TargetCapacityUnavailable = 2,
        /// The Arduino String rejected the payload after capacity had been reserved.
        TargetWriteFailed = 3
    };

    /// Converts Arduino String values into bounded Strings while preserving bounded String invariants.
    template<std::size_t TCapacity>
    struct TypeConversionAdapter<::String, String<TCapacity>> final {

        /// Defines the operation-specific result Type returned by this adapter.
        using ResultType = ArduinoStringToBoundedStringResult;

        /// Indicates that Arduino String to bounded String conversion is available when this adapter header is included.
        static constexpr bool IsAvailable = true;

        /// Indicates that the Arduino String API does not declare every operation used by this adapter as noexcept.
        static constexpr bool IsNoexcept = false;

        /// Converts an Arduino String into a bounded String without modifying the target on failure.
        static ResultType Convert(
            const ::String& source,
            String<TCapacity>& target
        ) {
            if (!source) { return ResultType::SourceInvalid; }

            const auto assignmentResult = target.Assign(
                source.c_str(),
                static_cast<std::size_t>(source.length())
            );

            if (assignmentResult == StringAssignmentResult::Succeeded) { return ResultType::Succeeded; }

            if (assignmentResult == StringAssignmentResult::CapacityExceeded) { return ResultType::CapacityExceeded; }

            if (assignmentResult == StringAssignmentResult::EmbeddedNullNotPermitted) {
                return ResultType::EmbeddedNullNotPermitted;
            }

            return ResultType::SourceInvalid;
        }

    };

    /// Converts bounded Strings into Arduino String values while preserving the target on failure.
    template<std::size_t TCapacity>
    struct TypeConversionAdapter<String<TCapacity>, ::String> final {

        /// Defines the operation-specific result Type returned by this adapter.
        using ResultType = BoundedStringToArduinoStringResult;

        /// Indicates that bounded String to Arduino String conversion is available when this adapter header is included.
        static constexpr bool IsAvailable = true;

        /// Indicates that the Arduino String API does not declare every operation used by this adapter as noexcept.
        static constexpr bool IsNoexcept = false;

        /// Converts a bounded String into an Arduino String and publishes only a fully prepared target value.
        static ResultType Convert(
            const String<TCapacity>& source,
            ::String& target
        ) {
            if (source.Size() > static_cast<std::size_t>(std::numeric_limits<unsigned int>::max())) {
                return ResultType::SourceSizeUnsupported;
            }

            const auto sourceSize = static_cast<unsigned int>(source.Size());
            ::String candidate;

            if (!candidate.reserve(sourceSize)) { return ResultType::TargetCapacityUnavailable; }

            if (
                sourceSize > 0U &&
                !candidate.concat(
                    source.Data(),
                    sourceSize
                )
            ) {
                return ResultType::TargetWriteFailed;
            }

            target = std::move(candidate);
            return ResultType::Succeeded;
        }

    };

} // ESPressio::Bounded
