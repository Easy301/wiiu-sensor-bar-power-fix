# Console SensorBar

Wii U is weird about the **sensor bar in the red port on the back**. On the menu it’s usually off unless you’ve got a Wii Remote connected, you’re in vWii, or something else woke the Wii stack up.

These are [WiiUPluginSystem](https://github.com/wiiu-env/WiiUPluginSystem) plugins for [Aroma](https://aroma.wiiu.dev/) that power that **wired** bar from Wii U mode. They do **not** touch the GamePad’s built-in bar — that’s what [DRC Sensorbar](https://github.com/WiiDatabase/DRC-Sensorbar) is for.

## Pick one

Download from [Releases](https://github.com/Easy301/wiiu-console-sensorbar/releases):

- **`consolesensorbar-menu.wps`** — bar on while you’re on the Wii U Menu (what most people want).
- **`consolesensorbar-always.wps`** — bar stays on in games and apps too. Handy if you’re on the GamePad but still want the TV bar lit for a PC, second player, whatever.

Only install **one** of them.

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
