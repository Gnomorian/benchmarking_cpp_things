#pragma once
#include "timer_defines.h"
#include "TimerResults.h"
#include "dllexports.h"

namespace wiwyum::timer
{
	/// <summary>
	/// Simple clean way to get the start and end time of a scope in nanoseconds.
	/// </summary>
	class ExportClass RaiiTimer
	{
		TimerResults& myResults;
	public:
		RaiiTimer(TimerResults& results)
			: myResults{ results }
		{
			myResults.start = Clock::now();
		}
		virtual ~RaiiTimer()
		{
			myResults.end = Clock::now();
		}
	};
}