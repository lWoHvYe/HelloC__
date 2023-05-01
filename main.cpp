#include <iostream>
#include "seq_list.h"

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
    return 0;
}
