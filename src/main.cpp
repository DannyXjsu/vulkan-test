#include "app/vt_first_app.hpp"
#include "app/vt_window.hpp"

//std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
    vt::FirstApp app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}