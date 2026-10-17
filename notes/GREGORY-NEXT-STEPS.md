# What Gregory does next (short list)

Coding, research, and building the plugin stay on the agent side. You only handle the console, the SD card, and quick answers.

---

## 1. Profile (saved)

| Item | Value |
|------|--------|
| Region | **USA** |
| Aroma | Latest (Gregory) |
| SD | Usually **E:** — pick letter when installer asks |

Nothing else needed from you until the `.wps` is ready.

---

## 2. When the agent says the plugin is built

1. **Power off** the Wii U fully (not sleep).
2. Put the **SD card** in the PC.
3. Run **`Launchers\Install ConsoleSensorBar to SD.bat`** (defaults to **E:**).
4. Eject SD, put it back in the Wii U, **cold boot** to the Wii U menu.
5. **Test:** Dark room, **phone camera** pointed at the **wired bar under the TV** (not the GamePad).
   - See purple IR dots → tell the agent **“rear bar ON.”**
   - No dots → **“rear bar OFF.”**
6. Optional: sync a **Wii Remote** and see if the menu pointer works toward the TV.

If the console acts weird: remove `consolesensorbar.wps` from `plugins`, reboot — stock again.

---

## 3. You do **not** need to

- Install devkitPro, Docker, or compile anything (unless you later want to — optional).
- Install DRC Sensorbar (GamePad bar — wrong hardware for this project).
- Buy a USB sensor bar (out of scope).

---

## 4. Agent is doing (you wait)

- [ ] Padscore / IOSU research for the **real** rear-port power call
- [ ] Fix plugin code + produce **`consolesensorbar.wps`**
- [ ] Put `consolesensorbar.wps` in `plugin\` (this folder only — not the Desktop)

---

*Updated Oct 16, 2026*
