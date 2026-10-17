# Review — other AI’s plugin plan (Gregory quote)

> Scaffold from DRC-Sensorbar, wire **WPADSetSensorBarPower**, menu-only gating, optional keep-alive refresh, produce `.wps` for SD. Validate with phone camera on the bar.

## Verdict: **wrong API for this project**

| Claim | Fact |
|-------|------|
| Fork **DRC-Sensorbar** | That plugin calls **`VPADSetSensorBar(VPAD_CHAN_0, true)`** — **GamePad IR only** ([source](https://github.com/WiiDatabase/DRC-Sensorbar/blob/master/src/main.cpp)). Does **not** drive the **rear AV port**. |
| **WPADSetSensorBarPower** | **Exists** in current wut `padscore/wpad.h` (`void WPADSetSensorBarPower(BOOL enable)`), next to `WPADSetSensorBar`. This is the call the plugin uses. It is **not** `VPADSetSensorBar`. |
| **VPADSetSensorBar** | Official wut docs: turns on the **given Gamepad’s** sensor bar. Wiimotes can track **relative to GamePad** — **not** “power the wired bar under the TV.” |

Using that plan as-is would probably **do nothing** to Gregory’s wired bar, or only light the **GamePad** (wrong hardware).

## What we keep from the idea

| Good idea | Our use |
|-----------|---------|
| **WUPS** plugin (`.wps`) | Yes — `ConsoleSensorBar` |
| **Menu-only gating** | Yes — title ID **Wii U Menu** (USA `0005001010040100`, EUR `0005001010040200`, JPN `0005001010040000`) |
| **Keep-alive refresh** | Maybe — if Nintendo auto-powers-down, periodic re-assert on foreground |
| **Phone camera test** | Yes — only valid test for **rear** bar |

## What we try instead (action phase)

1. **Hypothesis A:** BT controller path initializes **padscore** (`KPADInit` / `WPADInit`) and that indirectly enables **console** sensor power — call same init from plugin on menu (experimental).
2. **Hypothesis B:** Hidden export in **padscore.rpl** / **coreinit** — find via dump + `OSDynLoad_FindExport` (RE).
3. **Hypothesis C:** **IOSU / MCP / STM** GPIO for sensor 12 V (hardware notes: TP31–TP33) — kernel patch or iosu module if userland fails.

Scaffold lives in `plugin/` — builds need **wut + wups** (Docker like DRC-Sensorbar). **Gregory validates** every build on hardware.
