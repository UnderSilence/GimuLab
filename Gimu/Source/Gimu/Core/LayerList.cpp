//
// Created by Metal on 2020/11/18.
//

#include "LayerList.h"

namespace Gimu {

    LayerList::~LayerList() {
        for(auto layer: m_Layers) {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerList::AppendLayer(Layer *layer) {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerList::RemoveLayer(Layer *layer) {
        auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
        if(it != m_Layers.begin() + m_LayerInsertIndex) {
            // remove layer but not destroy them
            // just lost control to this layer
            layer->OnDetach();
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerList::AppendOverlay(Layer *overlay) {
        m_Layers.emplace_back(overlay);
    }

    void LayerList::RemoveOverlay(Layer *overlay) {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
        if(it != m_Layers.end()) {
            overlay->OnDetach();
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

}