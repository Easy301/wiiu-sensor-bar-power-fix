#pragma once

#include <cstdint>

bool ConsoleSensorBar_IsWiiUMenuTitle(uint64_t titleId);
bool ConsoleSensorBar_ShouldEnable();
void ConsoleSensorBar_Enable();
void ConsoleSensorBar_Disable();
void ConsoleSensorBar_Refresh();
