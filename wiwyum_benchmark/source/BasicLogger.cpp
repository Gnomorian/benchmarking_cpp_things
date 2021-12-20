#include "BasicLogger.h"
#include <iostream>
#include <chrono>
#include <format>

namespace wiwyum
{
	BasicLogger::BasicLogger(std::filesystem::path filePath, bool useConsole)
		: file{ filePath, std::ios_base::app }
		, useConsole{useConsole}
	{}
	void BasicLogger::info(const std::wstring& message)
	{
		std::wstring_view Prefix{ L"[INFO]" };
		writeToStreams(formatMessage(Prefix, message));
	}
	void BasicLogger::debug(const std::wstring& message)
	{
		std::wstring_view Prefix{ L"[DEBUG]" };
		writeToStreams(formatMessage(Prefix, message));
	}
	void BasicLogger::critical(const std::wstring& message)
	{
		std::wstring_view Prefix{ L"[CRITICAL]" };
		writeToStreams(formatMessage(Prefix, message));
	}
	void BasicLogger::writeToStreams(const std::wstring& formattedMessage)
	{
		file << formattedMessage << std::endl;
		if (useConsole)
		{
			std::wcout << formattedMessage << std::endl;
		}
	}
	std::wstring BasicLogger::currentTimeFormatted() const
	{
		const auto currentTime{ std::chrono::utc_clock::now() };
		return std::format(L"{0:%F %H:%M:%OS}", currentTime);
	}
	std::wstring BasicLogger::formatMessage(std::wstring_view prefix, const std::wstring& message) const
	{
		return std::format(L"{} {} {}", currentTimeFormatted(), prefix, message);
	}
}