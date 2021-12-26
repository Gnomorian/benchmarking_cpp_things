#include "BmkTestResults.h"

namespace wiwyum::benchmark
{
	void BenchmarkTestResults::addMainTimePoint(const timer::TimerResults results)
	{

	}
	void BenchmarkTestResults::addCustomTimePoint(const std::wstring_view key, const timer::TimerResults results)
	{

	}
	timer::ClockDuration BenchmarkTestResults::mainBenchmarkAverage() const
	{

	}
	timer::ClockDuration BenchmarkTestResults::mainBenchmarkMax() const
	{

	}
	timer::ClockDuration BenchmarkTestResults::mainBenchmarkMin() const
	{

	}
	timer::ClockDuration BenchmarkTestResults::benchmarkKeyAverage(const std::wstring_view key) const
	{

	}
	timer::ClockDuration BenchmarkTestResults::benchmarkKeyMax(const std::wstring_view key) const
	{

	}
	timer::ClockDuration BenchmarkTestResults::benchmarkKeyMin(const std::wstring_view key) const
	{

	}
	std::vector<std::wstring> BenchmarkTestResults::keys() const
	{

	}
	void BenchmarkTestResults::addBenchmarkKey(std::wstring_view key)
	{

	}
}