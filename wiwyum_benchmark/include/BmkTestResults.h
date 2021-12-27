#pragma once
#include "TestResults.h"
#include <vector>
#include <map>
#include <valarray>

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
	private:
		auto makeValArray(const auto& collection) const
		{
			std::valarray<timer::ClockDuration> valarray{ mainBenchmarkResults.size() };
			std::generate(std::begin(valarray), std::end(valarray), [&, i = 0]() mutable {return collection[i++].duration(); });
			return valarray;
		}
		auto average(const auto& valarray) const
		{
			const auto sum{ valarray.sum() };
			return sum / valarray.size();
		}
		std::map<std::wstring, std::vector<timer::TimerResults>>::const_iterator findOrError(std::wstring_view key) const;
	};
}