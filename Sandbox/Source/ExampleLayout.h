//
// Created by Metal on 2020/11/18.
//

#ifndef GIMUDEV_EXAMPLELAYOUT_H
#define GIMUDEV_EXAMPLELAYOUT_H

#include <Gimu.h>

class ExampleLayout : public Gimu::Layer {
public:
    ExampleLayout();
    virtual ~ExampleLayout() = default;

    void OnUpdate() override;
    void OnEvent(Gimu::Event& event) override;
};


#endif //GIMUDEV_EXAMPLELAYOUT_H
