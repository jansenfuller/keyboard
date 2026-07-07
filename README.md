# Keyboard firmware

Firmware configurations for two split keyboards sharing a common layout:

| Keyboard | Firmware | Controller |
|----------|----------|------------|
| Lily58   | ZMK      | nice!nano v2 |
| Silakka54 | QMK     | RP2040     |

## Repo structure

```
├── zmk/          ← ZMK user config (Lily58)
│   ├── config/   ─ keymap + .conf + west.yml
│   ├── build.yaml
│   └── ...
├── qmk/          ← QMK keymap (Silakka54)
│   └── keyboards/
│       └── silakka54/
│           └── keymaps/default/
│               └── keymap.c
└── .github/workflows/build.yml  ← CI builds both
```

## Layout concept

Both keyboards share the same 3-row + thumb cluster layout with home-row mods:

| | | | | | |
|---|---|---|---|---|---|
| — | Q | W | E | R | T |
| Y | U | I | O | P | — |
| ESC | A/GUI | S/Alt | D/Ctrl | F/Shift | G |
| H | J/Shift | K/Ctrl | L/Alt | ;/GUI | ' |
| — | Z | X | C | V | B |
| N | M | , | . | / | — |

- **Thumbs:** Layer 1, Tab, Backspace | Space, Enter, Layer 2
- **Shift/Ctrl/Alt/GUI:** home-row hold-tap (D/F/J/K)
- **Layer 1:** Numerals, symbols, @, %, $ — no Shift needed
- **Layer 2:** F-keys, navigation, bootloader

## Building locally

### ZMK (Lily58)

```bash
cd zmk/config
west init -l .
west update
west build -b nice_nano_v2 -- -DSHIELD=lily58_left
west build -b nice_nano_v2 -- -DSHIELD=lily58_right
```

### QMK (Silakka54)

```bash
qmk compile -kb silakka54 -km default
```

## CI

The GitHub Actions workflow builds both firmwares on every push/PR:

- **ZMK:** uses `zmk-build-user-config` with `config_path: zmk/config`
- **QMK:** clones QMK, copies the keymap, and runs `make silakka54:default`
