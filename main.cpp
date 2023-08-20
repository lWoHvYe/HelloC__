#include <iostream>
#include "seq_list.h"

#include <thread>
#include <mutex>

// 共享资源和互斥锁
int sharedCounter = 0;
std::mutex mutex;

// 线程函数
void incrementCounter() {
    for (int i = 0; i < 100000; i++) {
        // 用std::lock_guard 来自动管理互斥锁的上锁和解锁。
        std::lock_guard<std::mutex> lock(mutex); // 上锁
        sharedCounter++;
    }
}

int main() {
    std::cout << "Hello, C++ World!" << std::endl;
    printf("Hello, C   World!\n");
    SeqList Lr;
    InitList(Lr);
    delete Lr.data;
    ElemType j = Lr.data[0];
    Lr.data[0] = 2;
    printf("after delete %d\n", j);

    asm volatile("":: :"memory"); // Compiler Barrier

//    smp_mb(); // Linux中的宏

    SeqList Lp;
    InitList(&Lp);
    free(Lp.data);
    ElemType i = Lp.data[0];
    Lp.data[0] = 2;
    printf("after free %d\n", i);

    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    // std::cout：这是 C++ 标准库中的标准输出流对象，用于将数据输出到屏幕。
    // <<：这是 C++ 中的流插入操作符，它用于将数据插入到输出流中。<< 操作符在 C++ 中被重载
    // sharedCounter：这是一个变量，我们想要输出它的值。
    // << std::endl：std::endl 是一个用于插入换行符并刷新流的特殊符号。
    std::cout << "Final sharedCounter value: " << sharedCounter << std::endl;

    return 0;
}
