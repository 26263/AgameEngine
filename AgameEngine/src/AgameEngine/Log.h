#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace AgameEngine {

	class AGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;

	};

}

//core log macros
#define AGE_CORE_TRACE(...) ::AgameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AGE_CORE_INFO(...)  ::AgameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AGE_CORE_WARN(...)  ::AgameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AGE_CORE_ERROR(...) ::AgameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AGE_CORE_FATAL(...) ::AgameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define AGE_TRACE(...) ::AgameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AGE_INFO(...)  ::AgameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AGE_WARN(...)  ::AgameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AGE_ERROR(...) ::AgameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AGE_FATAL(...) ::AgameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

