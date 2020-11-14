//
// Created by Metal on 2020/11/14.
//

#include <Gimu.h>
#include <cstdio>
using namespace std;

class Sandbox : public Gimu::Application {
public:
    Sandbox() = default;
    ~Sandbox() override = default;
};

int main() {
    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    return 0;
}