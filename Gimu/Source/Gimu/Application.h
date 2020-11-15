//
// Created by Metal on 2020/11/14.
//

#ifndef GIMUDEV_APPLICATION_H
#define GIMUDEV_APPLICATION_H

#include "Core.h"

namespace Gimu {

    class GIMU_API Application {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}

#endif //GIMUDEV_APPLICATION_H
