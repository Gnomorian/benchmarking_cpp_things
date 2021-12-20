
#include "BenchmarkTestId.h"
#include <atomic>

namespace wiwyum::benchmark
{
	BenchmarkTestId generateBenchmarkTestId() noexcept
	{
		static std::atomic<BenchmarkTestId> currentId{ 0 };
		return ++currentId;
	}

}