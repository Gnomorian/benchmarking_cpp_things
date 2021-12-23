#pragma once
#include <string>
#include <chrono>

namespace wiwyum::benchmark
{
	struct BenchmarkTestDescriptor
	{
		const std::wstring_view Name;
		const std::wstring_view Description;
		const std::wstring_view Author;
		BenchmarkTestDescriptor(decltype(Name) name, decltype(Description) description, decltype(Author) author)
			: Name{name}
			, Description{description}
			, Author{author}
		{}
	};
}