#include "rear_sensorbar.h"

#include <coreinit/title.h>
#include <padscore/kpad.h>
#include <padscore/wpad.h>

#include "wpad_sensorbar_decl.h"

// Wii U Menu title IDs (JPN / USA / EUR).
static constexpr uint64_t TITLE_MENU_JPN = 0x0005001010040000ULL;
static constexpr uint64_t TITLE_MENU_USA = 0x0005001010040100ULL;
static constexpr uint64_t TITLE_MENU_EUR = 0x0005001010040200ULL;

#ifndef REAR_SENSORBAR_ALWAYS_ON
#define REAR_SENSORBAR_ALWAYS_ON 0
#endif

static bool s_wpadReady = false;

bool RearSensorBar_IsWiiUMenuTitle(uint64_t titleId) {
    return titleId == TITLE_MENU_JPN || titleId == TITLE_MENU_USA || titleId == TITLE_MENU_EUR;
}

bool RearSensorBar_ShouldEnable() {
#if REAR_SENSORBAR_ALWAYS_ON
    return true;
#else
    return RearSensorBar_IsWiiUMenuTitle(OSGetTitleID());
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

void RearSensorBar_Enable() {
    ensureWpad();
    WPADEnableSensorBar(TRUE);
    WPADSetSensorBar(TRUE);
    WPADSetSensorBarPower(TRUE);
}

void RearSensorBar_Disable() {
    if (!s_wpadReady) {
        return;
    }
    WPADSetSensorBarPower(FALSE);
    WPADSetSensorBar(FALSE);
    WPADEnableSensorBar(FALSE);
}

void RearSensorBar_Refresh() {
    if (RearSensorBar_ShouldEnable()) {
        RearSensorBar_Enable();
    }
}
