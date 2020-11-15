//
// Created by Metal on 2020/11/15.
//

#ifndef GIMUDEV_LOG_H
#define GIMUDEV_LOG_H

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Gimu {
    class GIMU_API Log {
    public:
        static void Init();

        Log();
        virtual ~Log();

        inline static const std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; };
        inline static const std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; };
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define GM_CORE_FATAL(...)  ::Gimu::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define GM_CORE_ERROR(...)  ::Gimu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GM_CORE_WARN(...)   ::Gimu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GM_CORE_INFO(...)   ::Gimu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GM_CORE_TRACE(...)  ::Gimu::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define GM_FATAL(...)  ::Gimu::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define GM_ERROR(...)  ::Gimu::Log::GetClientLogger()->error(__VA_ARGS__)
#define GM_WARN(...)   ::Gimu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GM_INFO(...)   ::Gimu::Log::GetClientLogger()->info(__VA_ARGS__)
#define GM_TRACE(...)  ::Gimu::Log::GetClientLogger()->trace(__VA_ARGS__)

#endif //GIMUDEV_LOG_H