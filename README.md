# Keyboard firmware

Vial + ZMK firmware for three split keyboards.

| Keyboard | Controller | Firmware |
|----------|------------|----------|
| Lily58 | nice!nano v2 | ZMK |
| Cheapino | RP2040-Zero | Vial |
| Silakka54 | RP2040-Zero | Vial |

**Combos:** D+F=ESC · F+J=Caps Lock

## Layout

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
         │L1/TAB│ BSPC │ TRNS │             │ TRNS │ SPC  │L2/ENT│
         └──────┴──────┴──────┘             └──────┴──────┴──────┘

 L1 │  ~   │  !   │  _   │  |   │  ^   │ │  =   │  7   │  8   │  9   │  '   │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  %   │  @   │  #   │  $   │  &   │ │  *   │  4   │  5   │  6   │  "   │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │ TRNS │ TRNS │ TRNS │ TRNS │ TRNS │ │  0   │  1   │  2   │  3   │  +   │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │ MO3  │ TRNS │ TRNS │             │ TRNS │ TRNS │ MO3  │
         └──────┴──────┴──────┘             └──────┴──────┴──────┘

 L2 │  `   │  /   │  -   │  \   │ TRNS │ │ TRNS │ TRNS │ TRNS │ TRNS │ TRNS │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  {   │  (   │  }   │  )   │ TRNS │ │ LEFT │ DOWN │  UP  │RIGHT │ TRNS │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │  <   │  [   │  >   │  ]   │ TRNS │ │ TRNS │ TRNS │ TRNS │ TRNS │ TRNS │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │ MO3  │ TRNS │ TRNS │             │ TRNS │ TRNS │ MO3  │
         └──────┴──────┴──────┘             └──────┴──────┴──────┘

 L3 │ F1   │ F2   │ F3   │ F4   │ F5   │ │ F6   │ F7   │ F8   │ F9   │ F10  │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │ F11  │ F12  │ TRNS │ RST  │ BOOT │ │ HOME │ PGDN │ PGUP │ END  │ DEL  │
    ├──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┤
    │ TRNS │ TRNS │ TRNS │ TRNS │ TRNS │ │ TRNS │ TRNS │ TRNS │ TRNS │ TRNS │
    └──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┘
         ┌──────┬──────┬──────┐             ┌──────┬──────┬──────┐
         │ TRNS │ TRNS │ TRNS │             │ TRNS │ TRNS │ TRNS │
         └──────┴──────┴──────┘             └──────┴──────┴──────┘
```

## Build

```bash
# Lily58 (ZMK)
cd zmk/config && west init -l . && west update
west build -b nice_nano_v2 -- -DSHIELD=lily58_left

# Cheapino / Silakka54 (Vial) — requires vial-qmk
git clone https://github.com/vial-kb/vial-qmk
cd vial-qmk && make git-submodule
make cheapino:vial
make silakka54:vial
```

## CI

| Workflow | Builds | Trigger |
|----------|--------|---------|
| `build-zmk.yml` | Lily58 | zmk/** |
| `build-qmk.yml` | Cheapino + Silakka54 | qmk/** |
