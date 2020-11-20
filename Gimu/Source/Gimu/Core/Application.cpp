//
// Created by Metal on 2020/11/14.
//

#include "gmpch.h"
#include "Gimu/Core/Application.h"
#include "Gimu/Core/Log.h"

#include <glad/glad.h>

namespace Gimu {

    Application *Application::s_Instance = nullptr;

    Application::Application() {

        GM_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = Window::Create(WindowProps());
        m_Window->SetEventCallback(GM_BIND_EVENT_FN(OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        AppendOverlay(m_ImGuiLayer);
    }

    Application::~Application() {

    }

    // Events dispatched here
    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(GM_BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(GM_BIND_EVENT_FN(Application::OnWindowResize));
        // GM_CORE_TRACE("{0}", e.ToString());

        for (auto it = m_LayerList.rbegin(); it != m_LayerList.rend(); it++) {
            if(e.Handled) break;
            (*it)->OnEvent(e);
        }
    }

    void Application::Run() {
        // GM_TRACE(e.ToString());
        // GM_WARN(e.ToString());

        while (m_Running) {
            /* Window screen test */
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (auto layer: m_LayerList) {
                layer->OnUpdate();
            }
            m_ImGuiLayer->Begin();
            {
                for (Layer* layer : m_LayerList)
                    layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();
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

    void Application::AppendLayer(Layer *layer) {
        m_LayerList.AppendLayer(layer);
    }

    void Application::AppendOverlay(Layer *overlay) {
        m_LayerList.AppendOverlay(overlay);
    }

}