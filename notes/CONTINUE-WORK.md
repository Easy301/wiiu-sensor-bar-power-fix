# CONTINUE-WORK — Wii U Sensor Bar Power (console port)

## Correct scope (Oct 16, 2026)

Gregory clarified: **wired sensor bar in the red Wii U port** — **NOT** GamePad IR.

- **Do not** recommend DRC Sensorbar as the solution.
- **Do** pursue Aroma plugin (or IOSU patch) to energize **rear AV sensor bar** on **Wii U main menu**.

## User symptom

Bar dark on Wii U menu; lights when Classic/Boopair/vWii (per Gregory — **verify TV bar with phone camera** in action phase).

## Docs

| File | Role |
|------|------|
| `docs/DESIGN.md` | Full design v0.2 |
| `README.md` | One-screen summary |

## Phase 1 — Report (now)

- [x] Folder + design updated for console port
- [ ] Gregory answers DESIGN.md §9
- [ ] Optional: 1-page report for school using DESIGN §1–6

## Phase 2 — Action (in progress)

- [x] `notes/baseline-hardware-tests.md` — Gregory confirmed
- [x] `notes/other-ai-proposal-review.md` — DRC / WPAD plan rejected for rear port
- [x] `plugin/` — `KPADInit` + WPAD sensor-bar exports (v0.2.0 menu-only)
- [x] Build `.wps` (Docker + `consolesensorbar-builder` image)
- [x] Gregory hardware test — **rear bar ON on Wii U menu** (Oct 16, 2026)
- [ ] Optional: reinstall v0.2.0 on SD if Gregory wants bar off outside menu

## Blockers

| Blocker | Notes |
|---------|--------|
| No public prior plugin | Greenfield RE |
| Unknown enable API | R3–R4 required |
| Classic-connected behavior unverified | Might be misleading vs port power |

## Paths

```
Wiiu Sensor Bar Power project/
├── README.md
├── docs/DESIGN.md
└── notes/CONTINUE-WORK.md
```
