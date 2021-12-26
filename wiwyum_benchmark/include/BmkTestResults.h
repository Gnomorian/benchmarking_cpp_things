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
		virtual void addTimePoint(const timer::TimerResults results) override;
		virtual void addTimePoint(const std::wstring_view key, const timer::TimerResults results) override;
		virtual timer::ClockDuration average() const override;
		virtual timer::ClockDuration max() const override;
		virtual timer::ClockDuration min() const override;
		virtual timer::ClockDuration average(const std::wstring_view key) const override;
		virtual timer::ClockDuration max(const std::wstring_view key) const override;
		virtual timer::ClockDuration min(const std::wstring_view key) const override;
		virtual std::vector<std::wstring> keys() const override;
		virtual void addBenchmarkKey(std::wstring_view key) override;
	};
}