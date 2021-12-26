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
		virtual void addTimePoint(const timer::TimerResults results) = 0;
		virtual void addTimePoint(const std::wstring_view key, const timer::TimerResults results) = 0;
		virtual timer::ClockDuration average() const = 0;
		virtual timer::ClockDuration max() const = 0;
		virtual timer::ClockDuration min() const = 0;
		virtual timer::ClockDuration average(const std::wstring_view key) const = 0;
		virtual timer::ClockDuration max(const std::wstring_view key) const = 0;
		virtual timer::ClockDuration min(const std::wstring_view key) const = 0;
		virtual std::vector<std::wstring> keys() const = 0;
		virtual void addBenchmarkKey(std::wstring_view key) = 0;
	};
}