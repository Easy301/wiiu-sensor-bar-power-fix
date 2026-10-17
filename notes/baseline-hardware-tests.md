# Baseline hardware tests — confirmed (Gregory)

**Date:** Oct 16, 2026  
**Bar:** Physical Wii sensor bar on **red rear port** (not GamePad IR).  
**USB-powered bars:** Out of scope.

| Condition | Rear bar IR (phone camera) |
|-----------|----------------------------|
| Wii U main menu, normal boot | **OFF** |
| External BT controller connected | **ON** |
| vWii entered | **ON** |
| vWii Classic Console game (Wii mode inject) | **ON** |

**Goal:** Same **ON** state on **Wii U main menu at boot** via Aroma plugin — no controller workaround.

## Plugin test (ConsoleSensorBar v0.1.0 on SD)

**Date:** Oct 16, 2026  
**Result:** **PASS** — rear bar IR **ON** on Wii U main menu at boot (Gregory, phone camera on TV bar).

**Enable path (confirmed in build):** `KPADInit` + `WPADInit`, then `WPADEnableSensorBar` / `WPADSetSensorBar` / `WPADSetSensorBarPower` (symbols in `libwut`, declared in `wpad_sensorbar_decl.h`).
