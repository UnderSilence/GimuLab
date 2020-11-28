//
// Created by Admin on 2020/11/28.
//

#include "Gimu/Core/Input.h"
#include "Gimu/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Gimu {

    bool Input::IsKeyPressed(const KeyCode keycode) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsMouseButtonPressed(MouseCode button) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);;
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    Eigen::Vector2f Input::GetMousePosition() {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float) xpos, (float) ypos};
    }

    float Input::GetMouseX() {
        return GetMousePosition().x();
    }

    float Input::GetMouseY() {
        return GetMousePosition().y();
    }
}
