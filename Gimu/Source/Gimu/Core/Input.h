//
// Created by Admin on 2020/11/28.
//

#ifndef GIMUDEV_INPUT_H
#define GIMUDEV_INPUT_H

#include <Eigen/Core>
#include "Gimu/Core/Base.h"

#include "Gimu/Core/KeyCodes.h"
#include "Gimu/Core/MouseCodes.h"


namespace Gimu {
    class GIMU_API Input {
    public:
        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(MouseCode button);
        static Eigen::Vector2f GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}


#endif //GIMUDEV_INPUT_H
