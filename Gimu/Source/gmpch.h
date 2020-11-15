//
// Created by Metal on 2020/11/15.
//

#ifndef GIMUDEV_GMPCH_H
#define GIMUDEV_GMPCH_H

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

// Add ThirdParty
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

#ifdef GIMU_PLATFORM_WINDOWS
    #include <windows.h>
#endif

#endif //GIMUDEV_GMPCH_H
