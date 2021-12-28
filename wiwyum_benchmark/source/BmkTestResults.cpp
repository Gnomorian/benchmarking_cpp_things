#include "BmkTestResults.h"
#include <valarray>
#include <iterator>

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
		const auto durations{ makeValArray(mainBenchmarkResults) };
		return average(durations);
	}
	timer::ClockDuration BenchmarkTestResults::max() const
	{
		const auto durations{ makeValArray(mainBenchmarkResults) };
		return durations.max();
	}
	timer::ClockDuration BenchmarkTestResults::min() const
	{
		const auto durations{ makeValArray(mainBenchmarkResults) };
		return durations.min();
	}
	timer::ClockDuration BenchmarkTestResults::average(const std::wstring_view key) const
	{
		const auto itr{ findOrError(key) };
		const auto durations{ makeValArray(itr->second) };
		return average(durations);
	}
	timer::ClockDuration BenchmarkTestResults::max(const std::wstring_view key) const
	{
		const auto itr{ findOrError(key) };
		const auto durations{ makeValArray(itr->second) };
		return durations.max();
	}
	timer::ClockDuration BenchmarkTestResults::min(const std::wstring_view key) const
	{
		const auto itr{ findOrError(key) };
		const auto durations{ makeValArray(itr->second) };
		return durations.min();
	}
	std::vector<std::wstring> BenchmarkTestResults::keys() const
	{
		std::vector<std::wstring> keys;
		auto inserter{ std::back_inserter(keys) };
		for (const auto [key, value] : benchmarkResultsForKey)
		{
			inserter = key;
		}
		return keys;
	}
	void BenchmarkTestResults::addBenchmarkKey(std::wstring_view key)
	{
		throw std::runtime_error{ "not implemented" };
	}
	std::map<std::wstring, std::vector<timer::TimerResults>>::const_iterator BenchmarkTestResults::findOrError(std::wstring_view key) const
	{
		auto itr{ benchmarkResultsForKey.find(std::wstring{ key }) };
		if (itr == benchmarkResultsForKey.end())
		{
			throw std::runtime_error{ "no entry at key." };
		}
		return itr;
	}
	ExportCppFunction std::unique_ptr<TestResults> CALL_CONVENTION makeTestResults()
	{
		return std::make_unique<BenchmarkTestResults>();
	}
}