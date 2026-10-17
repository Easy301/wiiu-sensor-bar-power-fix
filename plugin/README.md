# ConsoleSensorBar — WUPS plugin (scaffold)

Powers the **wired** Wii sensor bar on the **Wii U rear port** while the **Wii U Menu** is in the foreground.

**Status:** Scaffold / experimental — **not validated** on hardware. Do not expect first `.wps` to work until RE finds the real enable path.

## Build (Linux or Docker — same pattern as DRC-Sensorbar)

Requires [wut](https://github.com/devkitPro/wut) and [WiiUPluginSystem](https://github.com/wiiu-env/WiiUPluginSystem) installed per their READMEs.

```bash
cd plugin
make all
# → consolesensorbar-menu.wps, consolesensorbar-always.wps (+ copies in ../releases/)
```

Docker (after `docker build -t consolesensorbar-builder .`):

```bash
docker run --rm -v ${PWD}:/project consolesensorbar-builder make all
```

## Install

Copy **one** of `consolesensorbar-menu.wps` or `consolesensorbar-always.wps` to:

`sd:/wiiu/environments/aroma/plugins/`

Reboot or reload plugins. Config: **L + D-Pad Down + Minus** (WUPS menu).

## Test (Gregory)

1. Dark room, phone camera on **TV bar** (not GamePad).
2. Boot to Wii U menu — IR dots should appear if enable path works.
3. Sync Wii Remote — menu pointer should work toward TV.

## Logging

Build with `make DEBUG=1` and install [LoggingModule](https://github.com/wiiu-env/LoggingModule) to see which experimental path ran.
