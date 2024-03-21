#pragma once

#include <chrono>

class Stopwatch {
public:
    Stopwatch();
    void Start();
    void Stop();
    void Reset();
    long long ElapsedMilliseconds() const;

private:
    bool running;
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
};