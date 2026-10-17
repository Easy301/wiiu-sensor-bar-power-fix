# Wii U Sensor bar Power Fix

The Wii U has this annoying "feature": the wired sensor bar in the red port on the back will not power on while you are on the main menu. It only lights up after you open vWii, or pair a third-party controller on the menu. Workarounds nobody should need just to use a Wii Remote on the couch.

[WiiUPluginSystem](https://github.com/wiiu-env/WiiUPluginSystem) plugins for [Aroma](https://aroma.wiiu.dev/) that power the **rear AV port** bar (not GamePad IR; see [DRC Sensorbar](https://github.com/WiiDatabase/DRC-Sensorbar) for that).

Download from [Releases](https://github.com/Easy301/wiiu-sensor-bar-power-fix/releases). Install **one** build.

## AlwaysBar

**`sensorbarfix-alwaysbar.wps`** — what most people want.

Turn the console on and the sensor bar comes on. It stays on in the menu, in games, in apps, whatever you are doing on the TV. No vWii trip, no pairing a controller just to get IR.

## MenuBar

**`sensorbarfix-menubar.wps`** — lighter option.

Same fix on the **Wii U Menu only**. The bar turns off when you launch a game (closer to stock outside the menu).

## Install

1. Install Aroma.
2. Copy **one** `.wps` to `SD:/wiiu/environments/aroma/plugins/`
3. Reboot or reload plugins.

WUPS menu to disable: **L + D-Pad Down + Minus**.

Windows SD copy scripts are in `Launchers/` (`Install AlwaysBar` / `Install MenuBar`).

## Limitations

- Tested with a normal Wii sensor bar in the rear port. USB bars are out of scope.
- Usual WUPS caveats (HOME menu, some applets). If something acts up, disable the plugin.
- Do not install AlwaysBar and MenuBar at the same time.

## Building

```bash
cd plugin
docker build -t sensorbarfix-builder .
docker run --rm -v ${PWD}:/project sensorbarfix-builder make all
```

That gives you both `.wps` files (`make alwaysbar` or `make menubar` for one).

## License

MIT
