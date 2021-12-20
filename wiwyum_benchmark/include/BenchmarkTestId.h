#pragma once
#include <typeinfo>
namespace wiwyum::benchmark
{
	using BenchmarkTestId = std::intmax_t;
	BenchmarkTestId generateId() noexcept;
}