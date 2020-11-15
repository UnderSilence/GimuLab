//
// Created by Metal on 2020/11/14.
//

#include "Application.h"
#include "Events/AppEvent.h"
#include "Log.h"

namespace Gimu {
    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::Run() {
        WindowResizeEvent e(1920, 1080);
        if(e.IsInCategory(EventCategoryApplication)) {
            GM_INFO(e.ToString());
        }
       // GM_TRACE(e.ToString());
       // GM_WARN(e.ToString());
        while (true) {}
    }

}