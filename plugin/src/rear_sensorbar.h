#pragma once

#include <cstdint>

bool RearSensorBar_IsWiiUMenuTitle(uint64_t titleId);
bool RearSensorBar_ShouldEnable();
void RearSensorBar_Enable();
void RearSensorBar_Disable();
void RearSensorBar_Refresh();
