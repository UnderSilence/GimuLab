//
// Created by Metal on 2020/11/14.
//

#ifndef GIMUDEV_CORE_H
#define GIMUDEV_CORE_H

#ifdef GIMU_PLATFORM_WINDOWS
    #ifdef GIMU_BUILD_DLL
        #define GIMU_API __declspec(dllexport)
    #else
        #define GIMU_API __declspec(dllimport)
    #endif
#else
    #error Hazel only support Windows currently!
#endif

#include "Base.h"

#endif //GIMUDEV_CORE_H
