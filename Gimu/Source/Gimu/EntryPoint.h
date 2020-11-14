//
// Created by Metal on 2020/11/15.
//

#ifndef GIMUDEV_ENTRYPOINT_H
#define GIMUDEV_ENTRYPOINT_H

#ifdef GIMU_PLATFORM_WINDOWS

// extern Gimu::Application* Gimu::CreateApplication();
int main(int argc, char** argv) {

    // printf("GIMUEngin Start");
    auto app = Gimu::CreateApplication();
    app->Run();
    delete app;
}

#endif
#endif //GIMUDEV_ENTRYPOINT_H
