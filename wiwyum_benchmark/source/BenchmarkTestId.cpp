
#include "BenchmarkTestId.h"
#include <atomic>

namespace wiwyum::benchmark
{
	BenchmarkTestId generateId() noexcept
	{
		static std::atomic<BenchmarkTestId> currentId{ 0 };
		return ++currentId;
	}

}