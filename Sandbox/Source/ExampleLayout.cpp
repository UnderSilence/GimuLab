//
// Created by Metal on 2020/11/18.
//

#include "ExampleLayout.h"

ExampleLayout::ExampleLayout():Layer("Example") {
}

void ExampleLayout::OnUpdate() {
    Layer::OnUpdate();
    // GM_INFO(__func__);
}

void ExampleLayout::OnEvent(Gimu::Event &event) {
    Layer::OnEvent(event);
    GM_TRACE("Catch event at {0}: {1}", m_DebugName, event.ToString());
}
