//
// Created by lWoHvYe on 2025/1/25.
//
#include <atomic>
#include <thread>
#include <assert.h>
std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y() {
    x.store(true, std::memory_order_relaxed); // x是松散式原子写
    y.store(true, std::memory_order_release); // y是释放式原子写
}

void read_y_then_x() {
    while (!y.load(std::memory_order_acquire)) {}
    // y获取式原子读
    if (x.load(std::memory_order_relaxed)) // x 松散式原子读
        ++z; // 如果y变成ture时 x已经变成 true 则z != 0
}

int main() {
    x = false;
    y = false;
    z = 0;
    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);
    a.join();
    b.join();
    assert(z.load()!=0);
}
