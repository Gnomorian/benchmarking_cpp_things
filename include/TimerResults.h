#pragma once
#include <chrono>
#include "timer_defines.h"

namespace wiwyum::timer
{
	struct TimerResults
	{
		ClockTimePoint start;
		ClockTimePoint end;

		ClockDuration duration() const
		{
			return end - start;
		}
	};
}