#pragma once
#include "TestResults.h"
#include <vector>
#include <map>

namespace wiwyum::benchmark
{
	class BenchmarkTestResults : public TestResults
	{
		std::vector<timer::TimerResults> mainBenchmarkResults;
		std::map<std::wstring, decltype(mainBenchmarkResults)> benchmarkResultsForKey;
	public:
		virtual void addMainTimePoint(const timer::TimerResults results) override;
		virtual void addCustomTimePoint(const std::wstring_view key, const timer::TimerResults results) override;
		virtual timer::ClockDuration mainBenchmarkAverage() const override;
		virtual timer::ClockDuration mainBenchmarkMax() const override;
		virtual timer::ClockDuration mainBenchmarkMin() const override;
		virtual timer::ClockDuration benchmarkKeyAverage(const std::wstring_view key) const override;
		virtual timer::ClockDuration benchmarkKeyMax(const std::wstring_view key) const override;
		virtual timer::ClockDuration benchmarkKeyMin(const std::wstring_view key) const override;
		virtual std::vector<std::wstring> keys() const override;
		virtual void addBenchmarkKey(std::wstring_view key) override;
	};
}