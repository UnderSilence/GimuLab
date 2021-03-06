//
// Created by Metal on 2020/11/18.
//

#include <GLFW/glfw3.h>

#include "ExampleLayout.h"
#include "imgui/imgui.h"

ExampleLayout::ExampleLayout():Layer("Example") {
}

void ExampleLayout::OnUpdate() {
    Layer::OnUpdate();
    // GM_INFO(__func__);
}

void ExampleLayout::OnEvent(Gimu::Event &event) {
    Layer::OnEvent(event);
    // GM_TRACE("Catch event at {0}: {1}", m_DebugName, event.ToString());
}

void ExampleLayout::OnImGuiRender() {
    Layer::OnImGuiRender();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Begin("Example");
    ImGui::Text("Hello from GimuLab!");
    ImGui::End();
}
