#pragma once
#include <cmath>

inline bool closeEnough(float left, float right, float threshold = 0.0000001)
{
	return abs(left - right) < threshold;
}