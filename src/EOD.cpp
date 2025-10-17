#include "EOD.h"
#include "platform/Window.h"

EOD::EOD() {
    
}

void EOD::run() {
    init();

    while (running && !window.shouldClose()) {
        window.clear();
        window.update();
    }
    cleanup();
}

void EOD::init() {
    window = Window(1280, 720, "Edge of Despair");
    window.init();
    window.setBackgroundColor(99, 116, 143, 1);

    shader = new ShaderProgram(
        "shaders/VertexShader.glsl",
        "shaders/FragmentShader.glsl"
    );
}

void EOD::tick() {}
void EOD::render() {}
void EOD::cleanup() {
    window.cleanup();
}

void EOD::getRenderer() {}
void EOD::getFontRenderer() {}
void EOD::getTextureManager() {}

int EOD::getDisplayWidth() {
    return window.getDisplayWidth();
}

int EOD::getDisplayHeight() {
    return window.getDisplayHeight();
}

int EOD::getScaledWidth() {
    return window.getScaledWidth();
}

int EOD::getScaledHeight() {
    return window.getScaledHeight();
}

int EOD::getWidth() {
    return window.getWidth();
}

int EOD::getHeight() {
    return window.getHeight();
}

void EOD::displayGuiScreen() {}
void EOD::getCurrentScreen() {}

Window EOD::getWindow() {
    return this->window;
}

void EOD::setIngameFocus() {
    window.setIngameFocus();
}

void EOD::toggleFullscreen() {
    window.toggleFullscreen();
}

void EOD::enableVsync(bool status) {
    window.enableVsync(status);
}

void EOD::setCursorGrabbed(bool grabbed) {
    window.setCursorGrabbed(grabbed);
}