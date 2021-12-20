#pragma once
#include <string>
#include <chrono>

namespace wiwyum::benchmark
{
	struct BenchmarkTestDescriptor
	{
		const std::wstring_view Description;
		const std::wstring_view Author;
		BenchmarkTestDescriptor(decltype(Description) description, decltype(Author) author)
			: Description{description}
			, Author{author}
		{}
	};
}