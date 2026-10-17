#include "console_sensorbar.h"

#include <coreinit/alarm.h>
#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <wups.h>

#if CONSOLE_SENSORBAR_ALWAYS_ON
#define PLUGIN_NAME "ConsoleSensorBar Always"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_DESC "Keep the wired Wii sensor bar (rear port) powered in all Wii U titles."
#else
#define PLUGIN_NAME "ConsoleSensorBar Menu"
#define PLUGIN_VERSION "1.0.0"
#define PLUGIN_DESC "Power the wired Wii sensor bar (rear port) on the Wii U Menu only."
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
    if (sEnabled && ConsoleSensorBar_ShouldEnable()) {
        ConsoleSensorBar_Refresh();
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
    if (sEnabled && ConsoleSensorBar_ShouldEnable()) {
        ConsoleSensorBar_Enable();
        scheduleRefresh();
    } else {
        cancelRefresh();
        ConsoleSensorBar_Disable();
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
