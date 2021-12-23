#pragma once
#include <string>
#include <chrono>
#include "formattable.h"
#include <format>

namespace wiwyum::benchmark
{
	struct BenchmarkTestDescriptor : FormattableReference
	{
		const std::wstring_view Name;
		const std::wstring_view Description;
		const std::wstring_view Author;
		BenchmarkTestDescriptor(decltype(Name) name, decltype(Description) description, decltype(Author) author)
			: Name{name}
			, Description{description}
			, Author{author}
		{}

		virtual std::wstring format() const override
		{
			return std::format(L"Name: {}\nDescription: {}\nAuthor: {}\n", Name, Description, Author);
		}
	};
}