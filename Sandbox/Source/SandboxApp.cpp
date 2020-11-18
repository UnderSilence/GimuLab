//
// Created by Metal on 2020/11/14.
//

#include <Gimu.h>
#include <cstdio>
#include <Gimu/Core/EntryPoint.h>
#include "ExampleLayout.h"
using namespace std;


class Sandbox : public Gimu::Application {
public:
    Sandbox() {
        AppendLayer(new ExampleLayout{});
        AppendOverlay(new Gimu::ImGuiLayer{});
    };
    ~Sandbox() override = default;
};

Gimu::Application* Gimu::CreateApplication() {
    return new Sandbox();
}