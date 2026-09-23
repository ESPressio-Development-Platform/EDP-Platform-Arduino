# Resources, Lifecycle and Concurrency

The bounded destination remains fixed-capacity and allocation-free. Conversion to Arduino `String` may allocate because that is inherent to Arduino `String`. No independent concurrency or ISR guarantee is added by the adapter.
