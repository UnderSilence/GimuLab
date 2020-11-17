//
// Created by Metal on 2020/11/14.
//

#ifndef GIMUDEV_APPLICATION_H
#define GIMUDEV_APPLICATION_H

#include "Gimu/Core/Base.h"
#include "Gimu/Core/Window.h"

namespace Gimu {

    class GIMU_API Application {
    public:
        Application();
        virtual ~Application();
        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}

#endif //GIMUDEV_APPLICATION_H
