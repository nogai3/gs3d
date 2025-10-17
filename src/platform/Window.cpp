#include "Window.h"
#include <algorithm>

Window::Window(int width, int height, const char* title)
    : width(width), height(height), title(title) {}

void Window::init() {
    if (!glfwInit())
        throw std::runtime_error("GLFW initialization failed!");

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window)
        throw std::runtime_error("Failed to create GLFW window!");

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD!");
    }

    
    glfwShowWindow(window);
}

void Window::updateGuiScale() {
    float scaleX = width / (float)BASE_WIDTH;
    float scaleY = height / (float)BASE_HEIGHT;

    guiScale = std::min(scaleX, scaleY);
    guiScale = std::max(0.5f, std::min(guiScale, 3.0f));
}

void Window::update() {
    updateMousePos();
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::setIngameFocus() {
    glfwMakeContextCurrent(window);
    glfwShowWindow(window);
}

void Window::toggleFullscreen() {
    fullscreen = !fullscreen;

    if (fullscreen) {
        glfwGetWindowPos(window, &windowedX, &windowedY);
        glfwGetWindowSize(window, &windowedWidth, &windowedHeight);

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* vidMode = glfwGetVideoMode(monitor);

        glfwSetWindowMonitor(window, monitor, 0, 0, vidMode->width, vidMode->height, vidMode->refreshRate);
        width = vidMode->width;
        height = vidMode->height;
    } else {
        glfwSetWindowMonitor(window, nullptr, windowedX, windowedY, windowedWidth, windowedHeight, 0);
        width = windowedWidth;
        height = windowedHeight;
    }
}

void Window::updateMousePos() {
    glfwGetCursorPos(window, &mouseX, &mouseY);
}

void Window::enableVsync(bool status) {
    glfwSwapInterval(status ? 1 : 0);
}

void Window::setCursorGrabbed(bool grabbed) {
    glfwSetInputMode(window, GLFW_CURSOR, grabbed ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

int Window::getDisplayWidth() {
    const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    return vidMode->width;
}

int Window::getDisplayHeight() {
    const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    return vidMode->height;
}

int Window::getWidth() { return width; }
int Window::getHeight() { return height; }
float Window::getGuiScale() { return guiScale; }

float Window::getScaledWidth() { return width / guiScale; }
float Window::getScaledHeight() { return height / guiScale; }

double Window::getMouseDeltaX() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    double dx = xpos - lastMouseX;
    lastMouseX = xpos;
    return dx;
}

double Window::getMouseDeltaY() {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    double dy = ypos - lastMouseY;
    lastMouseY = ypos;
    return dy;
}

double Window::getMouseX() { return mouseX; }
double Window::getMouseY() { return mouseY; }

double Window::setMousePos(double x, double y) {
    mouseX = x;
    mouseY = y;
    return 0.0;
}

bool Window::isKeyDown(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::setBackgroundColor(float r, float g, float b, float a) {
    glClearColor((GLfloat) r / 255.0f, (GLfloat) g / 255.0f, (GLfloat) b / 255.0f, (GLfloat) a);
}

GLFWwindow* Window::getWindow() { return window; }