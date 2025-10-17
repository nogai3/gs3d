#ifndef EOD_H
#define EOD_H

#include <iostream>
#include "platform/Window.h"
#include "platform/ShaderProgram.h"

class EOD {
public:
    EOD();
    void run();
    void getRenderer();
    void getFontRenderer();
    void getTextureManager();
    int getDisplayWidth();
    int getDisplayHeight();
    int getScaledWidth();
    int getScaledHeight();
    int getWidth();
    int getHeight();
    void displayGuiScreen();
    void getCurrentScreen();
    Window getWindow();
    void setIngameFocus();
    void toggleFullscreen();
    void enableVsync(bool status);
    void setCursorGrabbed(bool grabbed);
private:
    Window window = Window(800, 600, "Not initialized window!");
    ShaderProgram* shader = nullptr;
    bool running = true;
    void init();
    void tick();
    void render();
    void cleanup();
};

#endif