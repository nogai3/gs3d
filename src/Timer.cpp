#include "Timer.h"

Timer::Timer() {}

void Timer::init() {
    auto now = std::chrono::high_resolution_clock::now();
    auto nowNs = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    lastTime = nowNs;
}

int Timer::shouldTick() {
    auto now = std::chrono::high_resolution_clock::now();
    auto nowNs = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    long passedNs = nowNs - lastTime;

    fpsCounter += passedNs;
    frames++;
    if (fpsCounter >= NS_PER_SECOND) {
        fps = frames;
        frames = 0;
        fpsCounter = 0;
    }

    tickAccumulator += passedNs;

    ticksThisFrame = 0;
    while (tickAccumulator >= NS_PER_TICK) {
        ticksThisFrame++;
        tickAccumulator -= NS_PER_TICK;
    }

    partialTicks = (float) (tickAccumulator / NS_PER_TICK);
    return ticksThisFrame;
}

int Timer::getFps() {
    return fps;
}

float Timer::getPartialTicks() {
    return partialTicks;
}