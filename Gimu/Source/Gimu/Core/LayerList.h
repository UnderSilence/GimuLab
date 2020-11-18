//
// Created by Metal on 2020/11/18.
//

#ifndef GIMUDEV_LAYERSTACK_H
#define GIMUDEV_LAYERSTACK_H

#include "Gimu/Core/Base.h"

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


    class LayerList {
    public:
        LayerList() = default;
        ~LayerList();

        void AppendLayer(Layer* layer);
        void RemoveLayer(Layer* layer);
        void AppendOverlay(Layer* overlay);
        void RemoveOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

        // const_iterator versions is needed, by effective c++.
        [[nodiscard]] std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
        [[nodiscard]] std::vector<Layer*>::const_iterator end()	const { return m_Layers.end(); }
        [[nodiscard]] std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
        [[nodiscard]] std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //GIMUDEV_LAYERSTACK_H
