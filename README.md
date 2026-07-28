# Keyboard firmware

Vial firmware for three split keyboards sharing a 4-layer 5-column layout.

| Keyboard | Controller | Firmware |
|----------|------------|----------|
| Lily58 | nice!nano v2 | ZMK |
| Cheapino | RP2040-Zero | Vial |
| Silakka54 | RP2040-Zero | Vial |

## Layout

```
                    LEFT                          RIGHT
              P  R  M  I  I              I  I  M  R  P
              i  i  i  n  n              n  n  i  i  i
              n  n  d  d  d              d  d  d  n  n
              k  g        e              e        g  k
              y           x              x           y

Layer 0   ·   Q  W  E  R  T      Y  U  I  O  P   ·
          ·   A  S  D  F  G      H  J  K  L  ;   ·
          ·   Z  X  C  V  B      N  M  ,  .  /   ·
                 MO1 TAB BSPC    SPC ENT MO2

Layer 1   ·   `  /  ·  \  ·      =  7  8  9  ·   ·
          ·   [  (  ]  )  -      *  4  5  6  '   ·
          ·   <  {  >  }  ·      0  1  2  3  .   ·
                 ·   ·   ·       ·   ·   ·

Layer 2   ·   ~  ?  ·  |  ·      +  &  *  $  %   ·
          ·   ·  ·  ·  ·  _      ·  ←  ↓  ↑  →   ·
          ·   !  @  #  ·  ^      ·  ·  ·  ·  ·   ·
                 ·   ·   ·       ·   ·   ·

Layer 3   ·  F1 F2 F3 F4 F5     F6 F7 F8 F9 F10  ·
          ·  F11 F12 · RST BOOT  ·  ←  ↓  ↑  →   ·
          ·  HOME PGDN PGUP END DEL  ·  ·  ·  ·  ·
                 ·   ·   ·       ·   ·   ·
```

| Mod | A | S | D | F | G | H | J | K | L | ; |
|-----|---|---|---|---|---|---|---|---|---|---|
| Tap | A | S | D | F | G | H | J | K | L | ; |
| Hold | GUI | Alt | Ctrl | Shift | — | — | Shift | Ctrl | Alt | GUI |

**Combo:** D+F = ESC  
**Encoder (Cheapino):** rotation=volume, click=play/pause

## Building

```bash
# ZMK (Lily58)
cd zmk/config && west init -l . && west update
west build -b nice_nano_v2 -- -DSHIELD=lily58_left

# Vial — requires vial-qmk fork
git clone https://github.com/vial-kb/vial-qmk
cd vial-qmk && make git-submodule
make cheapino:vial
make silakka54:vial
```

## CI

| Workflow | Builds | Trigger |
|----------|--------|---------|
| `build-zmk.yml` | Lily58 (ZMK) | zmk/** |
| `build-qmk.yml` | Cheapino + Silakka54 (Vial) | qmk/** |
