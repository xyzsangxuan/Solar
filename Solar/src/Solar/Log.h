#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Solar {
	class SOLAR_API Log
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
//Core log macros
#define SL_CORE_ERROR(...)		::Solar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_WARN(...)		::Solar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_INFO(...)		::Solar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_TRACE(...)		::Solar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_FATAL(...)		::Solar::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SL_ERROR(...)			::Solar::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_WARN(...)			::Solar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_INFO(...)			::Solar::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_TRACE(...)			::Solar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_FATAL(...)			::Solar::Log::GetClientLogger()->fatal(__VA_ARGS__)

