# Keyboard firmware

QMK and ZMK firmware for three split keyboards.

| Keyboard | Controller | Firmware |
|---|---|---|
| Cheapino v2 | RP2040-Zero | QMK |
| Silakka54 | RP2040-Zero | QMK |
| Lily58 | nice!nano v2 | ZMK |

---

## Cheapino v2

> Layout rationale (bracket/operator finger assignment, SFB avoidance) is documented in [`KEYMAP_ANALYSIS.md`](./KEYMAP_ANALYSIS.md).

### Encoder

| Action | Output |
|---|---|
| Rotate clockwise | Next editor tab (Ctrl+Tab) |
| Rotate counter-clockwise | Previous editor tab (Ctrl+Shift+Tab) |
| Click | Play / Pause |

### Combos

| Keys | Output |
|---|---|
| D + F | Escape |
| Z + X | Caps Lock |

### Timing

| Setting | Value |
|---|---|
| `TAPPING_TERM` | 150 ms |
| `QUICK_TAP_TERM` | 120 ms |
| `PERMISSIVE_HOLD` | disabled |
| `DEBOUNCE_TYPE` | `sym_eager_pr` |

### Layout

```
                       LEFT                           RIGHT
    ┌──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┐
 L0 │  Q   │  W   │  E   │  R   │  T   │ │  Y   │  U   │  I   │  O   │  P   │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │A/GUI │S/Alt │D/Ctrl│F/Sft │  G   │ │  H   │J/Sft │K/Ctrl│L/Alt │;/GUI │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  Z   │  X   │  C   │  V   │  B   │ │  N   │  M   │  ,   │  .   │  /   │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │L1/TAB│ BSPC │      │             │      │ SPC  │L2/ENT│
         └──────┴──────┴──────┘             └──────┴──────┴──────┘

    ┌──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┐
 L1 │  ~   │  !   │  _   │  |   │  ^   │ │  =   │  7   │  8   │  9   │  '   │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  %   │  @   │  #   │  $   │  &   │ │  *   │  4   │  5   │  6   │  "   │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │      │      │      │      │      │ │  0   │  1   │  2   │  3   │  +   │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │      │      │      │             │      │      │ MO3  │
         └──────┴──────┴──────┘             └──────┴──────┴──────┘

    ┌──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┐
 L2 │  -   │  =   │  `   │  \   │  |   │ │ HOME │ PGDN │ PGUP │ END  │ DEL  │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  {   │  }   │  (   │  )   │  &   │ │ LEFT │ DOWN │  UP  │RIGHT │      │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  [   │  ]   │  <   │  >   │  !   │ │      │      │      │      │      │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │ MO3  │      │      │             │      │      │ MO3  │
         └──────┴──────┴──────┘             └──────┴──────┴──────┘

    ┌──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┐
 L3 │ F1   │ F2   │ F3   │ F4   │ F5   │ │ F6   │ F7   │ F8   │ F9   │ F10  │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │ F11  │ F12  │      │      │      │ │      │      │      │      │ INS  │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │      │      │      │ RST  │ BOOT │ │      │      │      │      │      │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │      │      │      │             │      │      │      │
         └──────┴──────┴──────┘             └──────┴──────┴──────┘
```

---

## Silakka54

Same homerow mod layout and combos as the Cheapino. The outer columns on every row are transparent — the Silakka54 has a Lily58-style 6-col footprint; only 5 inner columns are used per side.

### Combos

| Keys | Output |
|---|---|
| D + F | Escape |
| Z + X | Caps Lock |

---

## Lily58

ZMK firmware. Wireless via nice!nano v2.

### Combos

| Keys | Output |
|---|---|
| D + F | Escape |
| Z + X | Caps Lock |

### Timing (ZMK)

| Setting | Value |
|---|---|
| `tapping-term-ms` | 200 ms |
| `require-prior-idle-ms` | 150 ms |
| `flavor` | `balanced` |

---

## Build

### Cheapino / Silakka54 — QMK

Requires [qmk_firmware](https://github.com/qmk/qmk_firmware). The RP2040 target needs several submodules not initialised by default.

```bash
# One-time: fetch the submodules required for RP2040
cd ~/qmk_firmware
git submodule update --init lib/chibios lib/pico-sdk lib/printf lib/lufa

# Copy keyboard definitions into the QMK tree
cp -r qmk/keyboards/cheapino  ~/qmk_firmware/keyboards/
cp -r qmk/keyboards/silakka54 ~/qmk_firmware/keyboards/

# Compile
cd ~/qmk_firmware
qmk compile -kb cheapino  -km custom   # → cheapino_custom.uf2
qmk compile -kb silakka54 -km custom   # → silakka54_custom.uf2
```

### Flashing — drag and drop

1. Hold **BOOT** on the RP2040-Zero while connecting USB (or double-tap RESET if already connected).
2. The board mounts as a USB drive (`RPI-RP2`).
3. Drag the `.uf2` file onto the drive — it flashes and reboots automatically.

### Flashing — picotool (when the drive does not appear)

If the board enters bootloader mode but the drive isn't mounted (common on some Linux setups or hubs):

```bash
# Install picotool if needed: https://github.com/raspberrypi/picotool
picotool load cheapino_custom.uf2
picotool reboot
```

To flash a board that is already running QMK without pressing BOOT (requires the board to be in a state where it can accept USB commands, e.g. after sending QK_BOOT from the keyboard):

```bash
picotool load --force cheapino_custom.uf2
picotool reboot
```

### Lily58 — ZMK

```bash
cd zmk/config
west init -l .
west update

# Build each half separately
west build -b nice_nano_v2 -- -DSHIELD=lily58_left
west build -b nice_nano_v2 -- -DSHIELD=lily58_right
```

Flash each half by double-tapping the reset button to enter bootloader mode, then drag the `.uf2` onto the mounted drive.
