//
// Created by Metal on 2020/11/17.
// Copy and edit from Hazel Engine
//

#ifndef GIMUDEV_WINDOWSWINDOW_H
#define GIMUDEV_WINDOWSWINDOW_H

#include "Gimu/Core/Window.h"

struct GLFWwindow;

namespace Gimu {

    class WindowsWindow : public Window {
    public:
        explicit WindowsWindow(const WindowProps &props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        virtual void *GetNativeWindow() const { return m_Window; }
    private:
        void Init(const WindowProps &props);
        void Shutdown();
    private:
        GLFWwindow *m_Window{};

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };

}


#endif //GIMUDEV_WINDOWSWINDOW_H
