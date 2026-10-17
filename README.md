# Wii U Sensor bar Power Fix Plugin

The Wii U has this annoying "feature": the sensor bar will not power on while you are on the Wii U main menu. It only lights up after you open vWii, or pair a third-party controller on the menu, this plugin for Aroma fixes that issue. This should make it much easier for users like myself who use their Wii U sensor bar for both Dolphin and the Wii U.

Download from [Releases](https://github.com/Easy301/wiiu-sensor-bar-power-fix/releases). Install **one** build.

## AlwaysBar

**`sensorbarfix-alwaysbar.wps`** 
Turn the console on and the sensor bar comes on. It stays on in the menu, in games, in apps, whatever you are doing on the TV. 

## MenuBar

**`sensorbarfix-menubar.wps`**
Same as above but the sensor bar will turn off whenever a Wii U game or app is launched outside of the offical


## Install

1. Copy **one** `.wps` to `SD:/wiiu/environments/aroma/plugins/`
2. Turn on your Wii U and make sure the plug is enabled, you can do this via the wups menu and then pressing the manage plugins button.

How to open the plugin menu: **L + D-Pad Down + Minus button**.

## Limitations

You need a modded Wii U with Aroma so WUPS plugins can load. Stock firmware won’t run this.

## Building

```bash
cd plugin
docker build -t sensorbarfix-builder .
docker run --rm -v ${PWD}:/project sensorbarfix-builder make all
```

That gives you both `.wps` files (`make alwaysbar` or `make menubar` for one).

## License

MIT
