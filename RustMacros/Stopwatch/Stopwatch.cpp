#include "Stopwatch.h"

Stopwatch::Stopwatch() : running(false) {}

void Stopwatch::Start() {
    if (!running) {
        running = true;
        startTime = std::chrono::high_resolution_clock::now();
    }
}

void Stopwatch::Stop() {
    if (running) {
        running = false;
        endTime = std::chrono::high_resolution_clock::now();
    }
}

void Stopwatch::Reset() {
    running = false;
    startTime = endTime = std::chrono::high_resolution_clock::now();
}

long long Stopwatch::ElapsedMilliseconds() const {
    auto end = running ? std::chrono::high_resolution_clock::now() : endTime;
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime).count();
}