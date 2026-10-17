#pragma once

#include <cstdint>

bool SensorBarFix_IsWiiUMenuTitle(uint64_t titleId);
bool SensorBarFix_ShouldEnable();
void SensorBarFix_Enable();
void SensorBarFix_Disable();
void SensorBarFix_Refresh();
