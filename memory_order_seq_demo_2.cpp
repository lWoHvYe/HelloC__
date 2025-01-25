//
// Created by lWoHvYe on 2025/1/25.
//
#include <atomic>
#include <thread>
#include <assert.h>
std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y() {
    x.store(true, std::memory_order_relaxed); // 保证 x 的原子写
    y.store(true, std::memory_order_relaxed); // 保证 y 的原子写
}


void read_y_then_x() {
    while (!y.load(std::memory_order_relaxed)) {
    }
    if (x.load(std::memory_order_relaxed)) ++z; // 如果 y为 true x 已经为ture 则 z++
}

int main() {
    x = false;
    y = false;
    z = 0;
    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);
    a.join();
    b.join();
    assert(z.load() != 0);
}
