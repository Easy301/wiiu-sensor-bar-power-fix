# Console SensorBar

The Wii U has an annoying quirk: the **wired sensor bar** in the **red port on the back** often won’t power on from the main menu. Usually it only lights up after you open **vWii**, or pair a **third-party controller** on the menu — workarounds nobody should need just to use a Wii Remote on the couch.

These [WiiUPluginSystem](https://github.com/wiiu-env/WiiUPluginSystem) plugins for [Aroma](https://aroma.wiiu.dev/) fix that. Turn the console on and the bar comes on — no vWii trip, no fake controller pairing. This is the **rear-port** bar only, not the GamePad LEDs ([DRC Sensorbar](https://github.com/WiiDatabase/DRC-Sensorbar) handles those).

There are **two builds**. Pick one:

| Build | File | What it does |
| --- | --- | --- |
| **Menu** | `consolesensorbar-menu.wps` | Bar on in the **Wii U Menu** only. |
| **Always** | `consolesensorbar-always.wps` | Bar stays on from boot — menu, games, apps, whatever you’re doing on the TV. |

Download from [Releases](https://github.com/Easy301/wiiu-console-sensorbar/releases). Don’t install both at once.

## Install

1. Install Aroma if you haven’t already.
2. Grab a `.wps` from Releases.
3. Put it in `SD:/wiiu/environments/aroma/plugins/`
4. Reboot or reload plugins.

To turn it off without deleting the file: WUPS menu — **L + D-Pad Down + Minus**.

## Limitations

- I only tested with a normal Wii sensor bar in the rear port. USB bars are a different thing.
- Same kind of WUPS limits as other plugins (HOME menu, some applets, etc. may behave oddly — if something breaks, disable the plugin and report an issue).
- Don’t run both `.wps` files at once.

## Building

You need [wut](https://github.com/devkitPro/wut) and [wups](https://github.com/wiiu-env/WiiUPluginSystem), or Docker:

```bash
cd plugin
docker build -t consolesensorbar-builder .
docker run --rm -v ${PWD}:/project consolesensorbar-builder make all
```

That spits out both `.wps` files (`make menu` or `make always` if you only want one).

## License

MIT
