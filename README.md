# Keyboard firmware

Vial firmware for three split keyboards sharing a 4-layer 5-column layout.

| Keyboard | Controller | Flash |
|----------|------------|-------|
| Lily58   | nice!nano v2 | ZMK |
| Cheapino  | RP2040-Zero | Vial |
| Silakka54 | RP2040-Zero | Vial |

## Layout (4 layers)

```
Layer 0 — Default                        Layer 1 — Lower + Numpad (left thumb)
    Q W E R T     Y U I O P               ` / - \         = 7 8 9
  A S D F G     H J K L ;               [ ( ] ) -       * 4 5 6 '
    Z X C V B     N M , . /               < { > }         0 1 2 3 .
                                           L1+Tab        BSPC

Layer 2 — Upper + Arrows (right thumb)   Layer 3 — Nav + System (both thumbs)
  ~ ?     |         + & * $ %            F1-F5       F6-F10
      _               ← ↓ ↑ → "          F11 F12 RST BOOT  ← ↓ ↑ →
  ! @ #     ^                            HOME PGDN PGUP END DEL
          SPC    L2+Enter                             BT0-3
```

**Home-row mods:** F/J=Shift, D/K=Ctrl, S/L=Alt, A/;=GUI  
**Combo:** D+F = ESC (QMK), Space+Backspace = ESC (ZMK)  
**Encoder (Cheapino):** volume rotation, play/pause click

## Building

```bash
# ZMK (Lily58)
cd zmk/config && west init -l . && west update
west build -b nice_nano_v2 -- -DSHIELD=lily58_left

# Vial (Cheapino / Silakka54) — requires vial-qmk
git clone https://github.com/vial-kb/vial-qmk
cd vial-qmk && make git-submodule
make cheapino:vial
make silakka54:vial
```

## CI

- `build-zmk.yml` — Lily58 (ZMK)
- `build-qmk.yml` — Cheapino + Silakka54 (Vial)
