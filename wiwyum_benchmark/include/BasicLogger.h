#pragma once
#include "Logger.h"
#include <string>
#include <fstream>
#include <filesystem>

namespace wiwyum
{
	class BasicLogger : public Logger
	{
		std::wofstream file;
		const bool useConsole{ true };
	public:
		BasicLogger(std::filesystem::path filePath, bool useConsole);
		// Inherited via Logger
		virtual void info(const std::wstring& message) override;
		virtual void debug(const std::wstring& message) override;
		virtual void critical(const std::wstring& message) override;
	private:
		virtual void writeToStreams(const std::wstring& formattedMessage);
		virtual std::wstring currentTimeFormatted() const;
		virtual std::wstring formatMessage(std::wstring_view prefix, const std::wstring& message) const;
	};
}