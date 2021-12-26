#include "BmkTestResults.h"

namespace wiwyum::benchmark
{
	void BenchmarkTestResults::addTimePoint(const timer::TimerResults results)
	{

	}
	void BenchmarkTestResults::addTimePoint(const std::wstring_view key, const timer::TimerResults results)
	{

	}
	timer::ClockDuration BenchmarkTestResults::average() const
	{

	}
	timer::ClockDuration BenchmarkTestResults::max() const
	{

	}
	timer::ClockDuration BenchmarkTestResults::min() const
	{

	}
	timer::ClockDuration BenchmarkTestResults::average(const std::wstring_view key) const
	{

	}
	timer::ClockDuration BenchmarkTestResults::max(const std::wstring_view key) const
	{

	}
	timer::ClockDuration BenchmarkTestResults::min(const std::wstring_view key) const
	{

	}
	std::vector<std::wstring> BenchmarkTestResults::keys() const
	{

	}
	void BenchmarkTestResults::addBenchmarkKey(std::wstring_view key)
	{

	}
}