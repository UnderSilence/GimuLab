//
// Created by Metal on 2020/11/14.
//

#include "gmpch.h"
#include "Gimu/Core/Application.h"
#include "Gimu/Core/Log.h"
#include <GLFW/glfw3.h>

namespace Gimu {

    Application* Application::s_Instance = nullptr;

    Application::Application() {

        GM_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = Window::Create(WindowProps());
        m_Window->SetEventCallback(GM_BIND_EVENT_FN(OnEvent));
    }

    Application::~Application() {

    }

    // Events dispatched here
    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(GM_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(GM_BIND_EVENT_FN(Application::OnWindowResize));
        GM_CORE_TRACE("{0}", e.ToString());
    }

    void Application::Run() {
       // GM_TRACE(e.ToString());
       // GM_WARN(e.ToString());

        while (m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
    bool Application::OnWindowClose(WindowCloseEvent &e) {
        m_Running = false;
        return true;
    }
    bool Application::OnWindowResize(WindowResizeEvent &e) {
        GM_CORE_INFO(e.ToString());
        return true;
    }

}