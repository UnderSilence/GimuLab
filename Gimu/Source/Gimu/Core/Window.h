//
// Created by Metal on 2020/11/17.
// Edit from Hazel Engine
//

#ifndef GIMUDEV_WINDOW_H
#define GIMUDEV_WINDOW_H

#include <utility>

#include "Gimu/Core/Base.h"
#include "Gimu/Events/Event.h"

namespace Gimu {
    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProps(std::string title = "GimuLab Window",
                    unsigned int width = 1280,
                    unsigned int height = 720) :
                Title(std::move(title)), Width(width), Height(height) {}
    };

    // Interface representing a desktop system based Window
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Scope<Window> Create(const WindowProps& props = WindowProps());
    };
}


#endif //GIMUDEV_WINDOW_H
