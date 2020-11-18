//
// Created by Metal on 2020/11/18.
//

#ifndef GIMUDEV_LAYER_H
#define GIMUDEV_LAYER_H

#include "Gimu/Core/Base.h"
#include "Gimu/Events/Event.h"

namespace Gimu {
    class Layer {
    public:
        explicit Layer(std::string name = "DefaultLayer") :
                m_DebugName(std::move(name)) {}

        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &event) {}

        const std::string &GetName() { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
};


#endif //GIMUDEV_LAYER_H
