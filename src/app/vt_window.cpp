#include "vt_window.hpp"
#include <stdexcept>

namespace vt {

    VTWindow::VTWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }
    
    VTWindow::~VTWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void VTWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

    }

    void VTWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS){
            throw std::runtime_error("Failed to create window surface");
        }
    }
}