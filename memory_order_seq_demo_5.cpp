//
// Created by lWoHvYe on 2025/1/25.
//
#include <atomic>
#include <cassert>
#include <string>
#include <thread>

// 数据依赖 data dependency
struct X {
    int i_;
    std::string s_;
};

std::atomic<int> a;
std::atomic<X *> p;

void create_x() {
    X *x = new X;
    x->i_ = 42;
    x->s_ = "hello";
    a.store(99, std::memory_order_relaxed);
    p.store(x, std::memory_order_release); // x 和 p 构成
}

void use_x() {
    X *x;
    while (!(x = p.load(std::memory_order_consume))) {
    }
    assert(x->i_ == 42);
    assert(x->s_ == "hello");
    assert(a.load(std::memory_order_relaxed) == 99);
}

int main() {
    std::thread t1(create_x);
    std::thread t2(use_x);
    t1.join();
    t2.join();
    return 0;
}
