//
// Created by Metal on 2020/11/17.
//

#include "Gimu/Core/Window.h"

#ifdef GIMU_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace Gimu {
    Scope <Window> Window::Create(const WindowProps &props) {
#ifdef GIMU_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
#else
        GM_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif
    }
}