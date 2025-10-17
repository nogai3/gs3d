#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

class Timer {
public:
    float partialTicks = 0.0f;

    Timer();
    void init();
    int shouldTick();
    int getFps();
    float getPartialTicks();
private:
    static constexpr long NS_PER_SECOND = 1000000000L;
    static constexpr double TICKS_PER_SECOND = 2.0;
    static constexpr double NS_PER_TICK = NS_PER_SECOND / TICKS_PER_SECOND;
    
    long lastTime;
    double tickAccumulator = 0.0;

    int ticksThisFrame = 0;
    int fps = 0;
    long fpsCounter = 0;
    int frames = 0;
};

#endif