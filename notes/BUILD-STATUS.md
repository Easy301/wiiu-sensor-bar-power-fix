# Build status — Oct 16, 2026 afternoon

| Item | Status |
|------|--------|
| Plugin source | `plugin\src\` v0.1.0 — calls `WPADSetSensorBar` + `WPADSetSensorBarPower` |
| `consolesensorbar.wps` | **Built & validated on hardware** — v0.2.0 menu-only in source; SD may still be v0.1 until reinstall |
| Docker Desktop | Download started, then the installer sat idle because **WSL is not installed** on this PC. Hung installer was stopped. |
| WSL | Required for Docker on Windows Home. Install from here was blocked (needs a Windows feature + reboot). |

## When WSL is on

1. Reboot if Windows asks.
2. Finish Docker Desktop (or say so in chat and the agent will).
3. From `plugin\`: `docker build -t consolesensorbar .` then `docker run --rm -v` the folder and `make`.
4. `consolesensorbar.wps` lands in `plugin\`.
5. Gregory runs `Launchers\Install ConsoleSensorBar to SD.bat` (usually **E:**).

Nothing is placed on the Desktop.
