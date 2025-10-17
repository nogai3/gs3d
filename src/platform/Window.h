#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);

    void init();
    void updateGuiScale();
    void update();
    void clear();
    void setIngameFocus();
    void toggleFullscreen();
    void updateMousePos();
    void enableVsync(bool status);
    void setCursorGrabbed(bool grabbed);
    int getDisplayWidth();
    int getDisplayHeight();
    int getWidth();
    int getHeight();
    float getGuiScale();
    float getScaledWidth();
    float getScaledHeight();
    double getMouseDeltaX();
    double getMouseDeltaY();
    double getMouseX();
    double getMouseY();
    double setMousePos(double x, double y);
    bool isKeyDown(int key);
    bool shouldClose();
    void cleanup();
    void setBackgroundColor(float r, float g, float b, float a);
    GLFWwindow* getWindow();

private:
    static const int BASE_WIDTH = 320;
    static const int BASE_HEIGHT = 240;

    int width;
    int height;
    const char* title;
    GLFWwindow* window;

    float guiScale = 1.0f;
    int windowedX, windowedY, windowedWidth, windowedHeight;
    double lastMouseX = 0;
    double lastMouseY = 0;
    double mouseX, mouseY;
    bool fullscreen = false;
};

#endif
