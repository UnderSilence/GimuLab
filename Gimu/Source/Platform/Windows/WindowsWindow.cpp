//
// Created by Metal on 2020/11/17.
//

#include "Platform/Windows/WindowsWindow.h"
#include "Gimu/Events/AppEvent.h"
#include "Gimu/Events/KeyEvent.h"
#include "Gimu/Events/MouseEvent.h"


namespace Gimu {

    /* GLFW Data part */
    static uint8_t s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(int error, const char *description) {
        GM_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    void WindowsWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        GM_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (s_GLFWWindowCount == 0) {
            int success = glfwInit();
            GM_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
        ++s_GLFWWindowCount;

        // Set GLFW Callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            auto data = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            WindowResizeEvent e(width, height);
            data->EventCallback(e);
            data->Width = width;
            data->Height = height;
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            auto data = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            WindowCloseEvent e{};
            data->EventCallback(e);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            auto data = static_cast<WindowData *>(glfwGetWindowUserPointer(window));

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent e(key, 0);
                    data->EventCallback(e);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent e(key, 1);
                    data->EventCallback(e);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent e(key);
                    data->EventCallback(e);
                    break;
                }
                default: {
                    GM_CORE_ERROR("Unknown Keyboard Action");
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            auto data = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent e(button);
                    data->EventCallback(e);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent e(button);
                    data->EventCallback(e);
                    break;
                }
                default: {
                    GM_CORE_ERROR("Unknown Keyboard Action");
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
            auto data = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            MouseScrolledEvent e((float)xOffset, (float)yOffset);
            data->EventCallback(e);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
            auto data = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            MouseMovedEvent e((float)xPos,(float)yPos);
            data->EventCallback(e);
        });
    }

    void WindowsWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;

        if (s_GLFWWindowCount == 0) {
            glfwTerminate();
        }
    }

    void WindowsWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }

    WindowsWindow::WindowsWindow(const WindowProps &props) {
        Init(props);
    }
    WindowsWindow::~WindowsWindow() {
        Shutdown();
    }
    bool WindowsWindow::IsVSync() const {
        return m_Data.VSync;
    }


}