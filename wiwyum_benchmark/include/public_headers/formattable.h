#pragma once

#include <string>
#include <format>

struct FormattableReference
{
	virtual std::wstring format() const = 0;
};

struct ReferenceFormatter
{
	const FormattableReference& formattable;
	constexpr ReferenceFormatter(decltype(formattable) formattable)
		: formattable{ formattable }
	{}
	constexpr std::wstring format() const
	{
		return formattable.format();
	}
};

template<class CharT>
struct std::formatter<ReferenceFormatter, CharT> : std::formatter<std::wstring, CharT>
{
	// Define format() by calling the base class implementation with the wrapped value
	template<class FormatContext>
	auto format(ReferenceFormatter fmt, FormatContext& fc)
	{
		std::formatter<std::string, CharT>::format(fmt.format(), fc);
		return fc.out();
	}
};