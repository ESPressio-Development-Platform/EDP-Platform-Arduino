# Architecture

This repository follows API ownership rather than application-framework ownership. FreeRTOS-backed synchronization used by Arduino applications belongs in EDP-Platform-FreeRTOS, not here. The Arduino-specific code here exists because Arduino `::String` is itself the external API being adapted.

Conversion is deliberately transactional: destination state is changed only on complete success.
