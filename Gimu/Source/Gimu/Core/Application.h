//
// Created by Metal on 2020/11/14.
//

#ifndef GIMUDEV_APPLICATION_H
#define GIMUDEV_APPLICATION_H

#include "Gimu/Core/Base.h"
#include "Gimu/Core/Window.h"
#include "Gimu/Core/LayerList.h"
#include "Gimu/ImGui/ImGuiLayer.h"
#include "Gimu/Events/Event.h"
#include "Gimu/Events/AppEvent.h"

namespace Gimu {

    class GIMU_API Application {
    public:
        Application();
        virtual ~Application();
        void Run();

        void AppendLayer(Layer* layer);
        void AppendOverlay(Layer* overlay);

        void OnEvent(Event& e);

        inline static Application& Get() {return *s_Instance;}
        inline Window& GetWindow() {return *m_Window;}

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;

        LayerList m_LayerList;
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}

#endif //GIMUDEV_APPLICATION_H
