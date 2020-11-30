//
// Created by Metal on 2020/11/17.
//

#ifndef GIMUDEV_PLATFORMDETECTION_H
#define GIMUDEV_PLATFORMDETECTION_H

#ifdef GIMU_PLATFORM_WINDOWS
    #ifdef GIMU_BUILD_DLL
        #define GIMU_API
    #else
        #define GIMU_API
#endif
#else
    #error Hazel only support Windows currently!
#endif

#endif //GIMUDEV_PLATFORMDETECTION_H
