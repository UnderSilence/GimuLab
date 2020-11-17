//
// Created by Metal on 2020/11/14.
//

#include "gmpch.h"
#include "Gimu/Core/Application.h"
#include "Gimu/Core/Log.h"
#include <GLFW/glfw3.h>

namespace Gimu {
    Application::Application() {
        m_Window = Window::Create(WindowProps());
    }

    Application::~Application() {

    }

    void Application::Run() {
       // GM_TRACE(e.ToString());
       // GM_WARN(e.ToString());

        while (m_Running) {
            // glClearColor(1, 0, 1, 1);
            // glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
}