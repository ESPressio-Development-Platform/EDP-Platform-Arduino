# Private Implementation

Arduino-to-bounded conversion must leave the bounded destination unchanged on failure. Bounded-to-Arduino conversion builds a complete candidate before publishing it to the destination. Arduino-side allocation remains an Arduino behaviour and is not reclassified as deterministic bounded EDP storage.
