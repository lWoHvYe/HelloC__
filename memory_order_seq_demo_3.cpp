//
// Created by lWoHvYe on 2025/1/25.
//
#include <atomic>
#include <thread>
#include <iostream>
#include <assert.h>
std::atomic<bool> x, y;
std::atomic<int> z;
// 获取-释放序列 acquire-release ordering
void write_x() {
    x.store(true, std::memory_order_release); // x 设置为true
}

void write_y() {
    y.store(true, std::memory_order_release); // y 设置为true
}

void read_x_then_y() {
    while (x.load(std::memory_order_acquire) == false) {}
    if (y.load(std::memory_order_acquire) == true) {
        std::cout << "ok1" << std::endl; // x变成true时候y也是true则输出ok1
    }
}

void read_y_then_x() {
    while (y.load(std::memory_order_acquire) == false) {}
    if (x.load(std::memory_order_acquire) == true) {
        std::cout << "ok2" << std::endl; // y变成true时候x也是true则输出ok2
    }
}

int main() {
    x = false;
    y = false;
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);
    a.join();
    b.join();
    c.join();
    d.join();
}
