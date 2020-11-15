//
// Created by Metal on 2020/11/15.
//

#include "Log.h"
namespace Gimu {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    Log::~Log() {
    }

    Log::Log() {

    }

    void Log::Init() {
        // spdlog::set_pattern("%^[%T] %n: %v%$"); // just use default
        s_CoreLogger = spdlog::stdout_color_mt("GIMU");
        s_CoreLogger->set_level(spdlog::level::level_enum::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::level_enum::trace);
    }
}
