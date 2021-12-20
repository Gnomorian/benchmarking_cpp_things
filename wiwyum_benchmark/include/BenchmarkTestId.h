#pragma once
#include <typeinfo>
namespace wiwyum::benchmark
{
	using BenchmarkTestId = std::intmax_t;

	/// <summary>
	/// Benchmark test ids are program unique. Hide the generation behind its own function
	/// </summary>
	/// <returns>new unique id</returns>
	BenchmarkTestId generateBenchmarkTestId() noexcept;
}