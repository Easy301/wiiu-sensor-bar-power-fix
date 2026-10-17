#include "console_sensorbar.h"

#include <coreinit/title.h>
#include <padscore/kpad.h>
#include <padscore/wpad.h>

#include "wpad_sensorbar_decl.h"

// Wii U Menu title IDs (JPN / USA / EUR).
static constexpr uint64_t TITLE_MENU_JPN = 0x0005001010040000ULL;
static constexpr uint64_t TITLE_MENU_USA = 0x0005001010040100ULL;
static constexpr uint64_t TITLE_MENU_EUR = 0x0005001010040200ULL;

#ifndef CONSOLE_SENSORBAR_ALWAYS_ON
#define CONSOLE_SENSORBAR_ALWAYS_ON 0
#endif

static bool s_wpadReady = false;

bool ConsoleSensorBar_IsWiiUMenuTitle(uint64_t titleId) {
    return titleId == TITLE_MENU_JPN || titleId == TITLE_MENU_USA || titleId == TITLE_MENU_EUR;
}

bool ConsoleSensorBar_ShouldEnable() {
#if CONSOLE_SENSORBAR_ALWAYS_ON
    return true;
#else
    return ConsoleSensorBar_IsWiiUMenuTitle(OSGetTitleID());
#endif
}

static void ensureWpad() {
    if (s_wpadReady) {
        return;
    }
    KPADInit();
    WPADInit();
    s_wpadReady = true;
}

void ConsoleSensorBar_Enable() {
    ensureWpad();
    // padscore: console sensor-bar control (NOT VPADSetSensorBar / GamePad IR).
    WPADEnableSensorBar(TRUE);
    WPADSetSensorBar(TRUE);
    WPADSetSensorBarPower(TRUE);
}

void ConsoleSensorBar_Disable() {
    if (!s_wpadReady) {
        return;
    }
    WPADSetSensorBarPower(FALSE);
    WPADSetSensorBar(FALSE);
    WPADEnableSensorBar(FALSE);
}

void ConsoleSensorBar_Refresh() {
    if (ConsoleSensorBar_ShouldEnable()) {
        ConsoleSensorBar_Enable();
    }
}
