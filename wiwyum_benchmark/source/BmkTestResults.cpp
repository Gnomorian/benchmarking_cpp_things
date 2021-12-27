#include "BmkTestResults.h"
#include <valarray>

namespace wiwyum::benchmark
{
	void BenchmarkTestResults::addTimePoint(const timer::TimerResults results)
	{
		mainBenchmarkResults.push_back(results);
	}
	void BenchmarkTestResults::addTimePoint(const std::wstring_view key, const timer::TimerResults results)
	{
		const auto itr {
			[&, key=std::wstring{key}]
			{
				auto itr{ benchmarkResultsForKey.find(key) };
				if (itr != benchmarkResultsForKey.cend())
				{
					return itr;
				}
				auto [emplacedItr, emplaced] {benchmarkResultsForKey.emplace(key, std::vector<timer::TimerResults>{})};
				return emplacedItr;
			}()
		};
		auto [actualKey, timePoints] {*itr};
		timePoints.push_back(results);
	}
	timer::ClockDuration BenchmarkTestResults::average() const
	{
		const auto durations{ createValArray(mainBenchmarkResults) };
		auto sumOfValues{ durations.sum() };
		return sumOfValues / durations.size();
	}
	timer::ClockDuration BenchmarkTestResults::max() const
	{
		throw std::runtime_error{ "not implemented" };
	}
	timer::ClockDuration BenchmarkTestResults::min() const
	{
		throw std::runtime_error{ "not implemented" };
	}
	timer::ClockDuration BenchmarkTestResults::average(const std::wstring_view key) const
	{
		throw std::runtime_error{ "not implemented" };
	}
	timer::ClockDuration BenchmarkTestResults::max(const std::wstring_view key) const
	{
		throw std::runtime_error{ "not implemented" };
	}
	timer::ClockDuration BenchmarkTestResults::min(const std::wstring_view key) const
	{
		throw std::runtime_error{ "not implemented" };
	}
	std::vector<std::wstring> BenchmarkTestResults::keys() const
	{
		throw std::runtime_error{ "not implemented" };
	}
	void BenchmarkTestResults::addBenchmarkKey(std::wstring_view key)
	{
		throw std::runtime_error{ "not implemented" };
	}
}