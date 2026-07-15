# Keyboard firmware

Configurations for three split keyboards sharing a 4-layer 5-column layout.

| Keyboard | Firmware | Controller |
|----------|----------|------------|
| Lily58   | ZMK      | nice!nano v2 |
| Cheapino  | QMK     | RP2040     |
| Silakka54 | QMK     | RP2040     |

## Keymap

**Home-row mods:** F/J=Shift, D/K=Ctrl, S/L=Alt(Opt), A/;=GUI(CMD)  
**Combo:** D+F = ESC  
**Thumbs:** MO(1) TAB BSPC -- SPACE ENT MO(2)  
**Layer 3:** press opposite layer key while on L1 or L2

### Layer 0 -- Default

```
    Q     W     E     R     T         Y     U     I     O     P
  A/CMD  S/Opt D/Ctrl F/Shft  G       H  J/Shft K/Ctrl L/Opt ;/CMD
    Z     X     C     V     B         N     M     ,     .     /
         MO(1)   TAB   BSPC         SPACE   ENT   MO(2)
```

### Layer 1 -- Lower + Numpad (left thumb)

```
  "     /     -     \                 =     7     8     9     '
  [     (     ]     )                 *     4     5     6     `
  <     {     >     }                 0     1     2     3     +
```

### Layer 2 -- Upper + Arrows (right thumb)

```
  ~     !     _     |     ^
  %     @     #     $     &              <-     <-     ->     ->
```

### Layer 3 -- Nav + F-keys + System (both thumbs)

```
 F1    F2    F3    F4    F5        F6    F7    F8    F9   F10
 F11   F12         RST  BOOT       HOME  PGDN  PGUP   END   DEL
```

## Building

```bash
# ZMK (Lily58)
cd zmk/config && west init -l . && west update
west build -b nice_nano_v2 -- -DSHIELD=lily58_left

# QMK
qmk compile -kb cheapino -km default
qmk compile -kb silakka54 -km default
```
