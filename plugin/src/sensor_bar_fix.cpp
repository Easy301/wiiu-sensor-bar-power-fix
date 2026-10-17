#include "sensor_bar_fix.h"

#include <coreinit/title.h>
#include <padscore/kpad.h>
#include <padscore/wpad.h>

#include "wpad_sensorbar_decl.h"

static constexpr uint64_t TITLE_MENU_JPN = 0x0005001010040000ULL;
static constexpr uint64_t TITLE_MENU_USA = 0x0005001010040100ULL;
static constexpr uint64_t TITLE_MENU_EUR = 0x0005001010040200ULL;

#ifndef SENSOR_BAR_FIX_ALWAYSBAR
#define SENSOR_BAR_FIX_ALWAYSBAR 0
#endif

static bool s_wpadReady = false;

bool SensorBarFix_IsWiiUMenuTitle(uint64_t titleId) {
    return titleId == TITLE_MENU_JPN || titleId == TITLE_MENU_USA || titleId == TITLE_MENU_EUR;
}

bool SensorBarFix_ShouldEnable() {
#if SENSOR_BAR_FIX_ALWAYSBAR
    return true;
#else
    return SensorBarFix_IsWiiUMenuTitle(OSGetTitleID());
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

void SensorBarFix_Enable() {
    ensureWpad();
    WPADEnableSensorBar(TRUE);
    WPADSetSensorBar(TRUE);
    WPADSetSensorBarPower(TRUE);
}

void SensorBarFix_Disable() {
    if (!s_wpadReady) {
        return;
    }
    WPADSetSensorBarPower(FALSE);
    WPADSetSensorBar(FALSE);
    WPADEnableSensorBar(FALSE);
}

void SensorBarFix_Refresh() {
    if (SensorBarFix_ShouldEnable()) {
        SensorBarFix_Enable();
    }
}
