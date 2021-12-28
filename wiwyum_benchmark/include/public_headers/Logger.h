#pragma once
#include "dllexports.h"
#include <memory>
#include <string>
#include <sstream>

namespace wiwyum
{
	class ExportClass Logger
	{
	public:
		virtual void info(const std::wstring& message) = 0;
		virtual void debug(const std::wstring& message) = 0;
		virtual void critical(const std::wstring& message) = 0;
		void infoArgs(auto...message)
		{
			info(concatinate(message...));
		}
		void debugArgs(auto...message)
		{
			debug(concatinate(message...));
		}
		void criticalArgs(auto...message)
		{
			critical(concatinate(message...));
		}
	private:
		std::wstring concatinate(auto...messageParts)
		{
			std::wstringstream stream;
			((stream << messageParts), ...);
			return stream.str();
		}
	};

	ExportCppFunction std::unique_ptr<Logger> CALL_CONVENTION makeLogger();
}