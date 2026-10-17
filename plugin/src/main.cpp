#include "sensor_bar_fix.h"

#include <coreinit/alarm.h>
#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <wups.h>

#if SENSOR_BAR_FIX_ALWAYSBAR
#define PLUGIN_NAME "AlwaysBar"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_DESC "Wii U Sensor bar Power Fix: bar on from boot, stays on in games and apps."
#else
#define PLUGIN_NAME "MenuBar"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_DESC "Wii U Sensor bar Power Fix: bar on in the Wii U Menu only."
#endif

WUPS_PLUGIN_NAME(PLUGIN_NAME);
WUPS_PLUGIN_DESCRIPTION(PLUGIN_DESC);
WUPS_PLUGIN_VERSION(PLUGIN_VERSION);
WUPS_PLUGIN_AUTHOR("easy301");
WUPS_PLUGIN_LICENSE("MIT");

static bool sEnabled = true;
static OSAlarm sRefreshAlarm{};
static bool sAlarmInited = false;

static void refreshAlarmHandler(OSAlarm * /*alarm*/, OSContext * /*context*/) {
    if (sEnabled && SensorBarFix_ShouldEnable()) {
        SensorBarFix_Refresh();
    }
}

static void scheduleRefresh() {
    if (!sAlarmInited) {
        OSCreateAlarm(&sRefreshAlarm);
        sAlarmInited = true;
    }
    OSCancelAlarm(&sRefreshAlarm);
    OSSetPeriodicAlarm(&sRefreshAlarm,
                       OSGetTime(),
                       OSMillisecondsToTicks(2000),
                       refreshAlarmHandler);
}

static void cancelRefresh() {
    if (sAlarmInited) {
        OSCancelAlarm(&sRefreshAlarm);
    }
}

static void applyPowerState() {
    if (sEnabled && SensorBarFix_ShouldEnable()) {
        SensorBarFix_Enable();
        scheduleRefresh();
    } else {
        cancelRefresh();
        SensorBarFix_Disable();
    }
}

INITIALIZE_PLUGIN() {
    applyPowerState();
}

ON_APPLICATION_START() {
    applyPowerState();
}

ON_APPLICATION_ENDS() {
    cancelRefresh();
}
