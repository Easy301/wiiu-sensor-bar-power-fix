#pragma once

#include <wut.h>

#ifdef __cplusplus
extern "C" {
#endif

// Exported by libwut but missing from padscore/wpad.h in some toolchain builds.
void WPADSetSensorBar(BOOL enable);
void WPADSetSensorBarPower(BOOL enable);
void WPADEnableSensorBar(BOOL enable);

#ifdef __cplusplus
}
#endif
