#pragma once

#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace vt {

    class VTWindow{
        
        public:
            VTWindow(int w, int h, std::string name);
            ~VTWindow();

            VTWindow(const VTWindow &) = delete;
            VTWindow &operator=(const VTWindow &) = delete;

            bool shouldClose() {return glfwWindowShouldClose(window);}

            void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        private:
            void initWindow();

            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };
}