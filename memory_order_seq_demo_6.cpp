//
// Created by lWoHvYe on 2025/1/25.
//
#include <atomic>
#include <thread>
#include <iostream>
#include <assert.h>
std::atomic<bool> x, y;
// fences, memory barriers
void write_x_then_y() {
    x.store(true, std::memory_order_relaxed); // x 设置为true 在 fence之前
    std::atomic_thread_fence(std::memory_order_release); // 栅栏
    y.store(true, std::memory_order_relaxed); // y 设置为true 在 fence之后
}

void read_y_then_x() {
    while (y.load(std::memory_order_relaxed) == false) {}
    // 自旋 直到 y 被设置为true
    std::atomic_thread_fence(std::memory_order_acquire);
    if (x.load(std::memory_order_relaxed) == true) // x 已经在 y 之前被设置为 true
    {
        std::cout << "ok" << std::endl; // y变成true时候x也是true则输出ok
    }
}

int main() {
    x = false;
    y = false;
    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);
    a.join();
    b.join();
}
