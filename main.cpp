#include <iostream>
#include "Window.h"

int main() {
    Window window;
    window.setResolution(1366, 768);
    window.setFullscreen(false);
    window.createWindow();

    while (!window.shouldClose()) {
        window.updateInput();
        window.updateWindow();
    }

    return 0;
}