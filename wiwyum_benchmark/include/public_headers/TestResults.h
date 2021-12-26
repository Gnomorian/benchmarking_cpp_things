#pragma once
#include "dllexports.h"
#include "timer_defines.h"
#include "TimerResults.h"
#include <vector>
#include <iterator>

namespace wiwyum::benchmark
{
	class ExportClass TestResults
	{
	public:
		virtual void addMainTimePoint(const timer::TimerResults results) = 0;
		virtual void addCustomTimePoint(const std::wstring_view key, const timer::TimerResults results) = 0;
		virtual timer::ClockDuration mainBenchmarkAverage() const = 0;
		virtual timer::ClockDuration mainBenchmarkMax() const = 0;
		virtual timer::ClockDuration mainBenchmarkMin() const = 0;
		virtual timer::ClockDuration benchmarkKeyAverage(const std::wstring_view key) const = 0;
		virtual timer::ClockDuration benchmarkKeyMax(const std::wstring_view key) const = 0;
		virtual timer::ClockDuration benchmarkKeyMin(const std::wstring_view key) const = 0;
		virtual std::vector<std::wstring> keys() const = 0;
		virtual void addBenchmarkKey(std::wstring_view key) = 0;
	};
}