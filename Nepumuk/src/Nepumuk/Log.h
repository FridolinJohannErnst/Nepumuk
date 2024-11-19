#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nepumuk {

	class NEPUMUK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}
// Core log macros
#define NK_CORE_TRACE(...)    ::Nepumuk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NK_CORE_INFO(...)     ::Nepumuk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NK_CORE_WARN(...)     ::Nepumuk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NK_CORE_ERROR(...)    ::Nepumuk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NK_CORE_FATAL(...)    ::Nepumuk::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define NK_TRACE(...)	      ::Nepumuk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NK_INFO(...)	      ::Nepumuk::Log::GetClientLogger()->info(__VA_ARGS__)
#define NK_WARN(...)	      ::Nepumuk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NK_ERROR(...)	      ::Nepumuk::Log::GetClientLogger()->error(__VA_ARGS__)
#define NK_FATAL(...)	      ::Nepumuk::Log::GetClientLogger()->fatal(__VA_ARGS__)

// why log as macros? because we can check with an #if if we 
// are in distribution build and then can strip it, so customers dont see developer logs