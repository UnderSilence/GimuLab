//
// Created by Metal on 2020/11/18.
//

#ifndef GIMUDEV_IMGUILAYER_H
#define GIMUDEV_IMGUILAYER_H

#include "Gimu/Core/LayerList.h"

namespace Gimu {
    class GIMU_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override = default;
        void OnAttach() override;
        void OnDetach() override;
        void OnEvent(Event &event) override;

        void Begin();

        void OnImGuiRender() override;

        void End();
        void BlockEvents(bool block) { m_BlockEvents = block; }

    private:
        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };
}

#endif //GIMUDEV_IMGUILAYER_H
