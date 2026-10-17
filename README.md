# Wii U Sensor Bar Power project

**Goal:** On **Aroma**, power the **wired Wii sensor bar** plugged into the **red port on the back of the Wii U** while you are on the **Wii U main menu** — without workarounds (Classic Controller, Boopair, vWii first, etc.).

**Out of scope:** GamePad built-in IR. **[DRC Sensorbar](https://github.com/WiiDatabase/DRC-Sensorbar) does not apply** to the console port.

**Status:** **Working** — validated Oct 16, 2026. Two builds in `releases/` (menu-only + always-on). **Author:** easy301.

| Variant | File |
|---------|------|
| Menu only | `releases/consolesensorbar-menu.wps` |
| Always on | `releases/consolesensorbar-always.wps` |

Install with `Launchers/Install ConsoleSensorBar Menu to SD.bat` or `…Always…`. Pick **one** — not both.

**Gregory confirmed:** No IR on menu; IR on with BT controller, vWii, or vWii Classic game. USB bars **not** in scope.

**API:** `WPADSetSensorBarPower` in padscore (console bar). **Not** `VPADSetSensorBar` (GamePad). See `notes/other-ai-proposal-review.md`.

| Doc | Purpose |
|-----|---------|
| `docs/DESIGN.md` | Hardware, plugin plan |
| `notes/GREGORY-NEXT-STEPS.md` | **What you do when SD is ready** |
| `notes/profile-config.md` | USA / E: / Aroma |
| `notes/BUILD-STATUS.md` | Whether `.wps` exists yet |

**Gregory (saved):** USA menu, Aroma latest, SD usually **E:**.

**When the plugin is built:** run `Launchers\Install ConsoleSensorBar to SD.bat` → boot menu → phone camera on **TV bar** → tell agent ON or OFF.

Everything stays in this folder. Nothing goes on the Desktop.

**You now:** nothing until we ping you for SD test.
