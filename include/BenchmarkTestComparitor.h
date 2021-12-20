#pragma once
#include "BenchmarkTest.h"

namespace wiwyum::benchmark
{
	struct BenchmarkTestLessComparitor
	{

		constexpr bool operator()(const BenchmarkTest& left, const BenchmarkTest& right) const
		{
			return left.myId < right.myId;
		}
		constexpr bool operator()(const BenchmarkTest* left, const BenchmarkTest* right) const
		{
			return left->myId < right->myId;
		}
	};
}