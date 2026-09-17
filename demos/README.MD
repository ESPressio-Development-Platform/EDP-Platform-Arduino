# Demos

- `atomic-word-basic` — the Arduino `AtomicWord32` concrete provider.

The repository remains the Arduino concrete backend. The policy-required ESP-IDF demo target disables PlatformIO's framework compatibility filter locally so the current SDK-independent atomic provider surface can be compiled there without changing the package's declared Arduino ownership or compatibility.
