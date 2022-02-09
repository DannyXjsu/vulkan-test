#include "vt_first_app.hpp"

namespace vt {

    void FirstApp::run() {

        while (!vtWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}