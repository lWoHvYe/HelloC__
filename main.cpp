#include <iostream>
#include "seq_list_demo.h"

#include <thread>
#include <mutex>
#include <unistd.h>

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

    pid_t pid;
    // fork 函数在调用后，会返回不同的值，具体含义如下：
    //如果 fork 返回值为0，表示当前代码在子进程中执行。这是因为在子进程中，fork 返回0，所以可以通过这个返回值来判断当前代码是否在子进程中执行。
    //如果 fork 返回值大于0，表示当前代码在父进程中执行，同时返回值为子进程的进程ID（PID）。父进程通过检查 fork 返回值是否大于0 来区分自己是在父进程中执行。
    //如果 fork 返回值为-1，表示创建子进程失败
    pid = fork();
    // 当使用fork函数创建子进程后，子进程会继续执行fork函数调用之后的代码，而且父进程和子进程都会从fork函数调用后的位置开始执行。
    if (pid == 0) {
        std::cout << "这是一个子进程" << std::endl;
    } else if (pid > 0) {
        std::cout << "这是一个父进程" << std::endl;
        std::cout << "子进程id" << pid << std::endl;
    } else {
        std::cout << "创建进程失败" << std::endl;
    }

    return 0;
}
