//
// Created by lWoHvYe on 2023/4/17.
//

#include <cstdlib>
#include "seq_list_demo.h"

// n 是m的一个引用（reference），m 是被引用物（referent）。
//  int m;
//  int &n = m;
//n 相当于 m 的别名（绰号），对 n 的任何操作就是对m的操作。
//所以 n 既不是m的拷贝，也不是指向 m 的指针，其实n就是 m 它自己。
//
//引用的规则：
//（1）引用被创建的同时必须被初始化（指针则可以在任何时候被初始化）。
//（2）不能有 NULL 引用，引用必须与合法的存储单元关联（指针则可以是 NULL）。
//（3）一旦引用被初始化，就不能改变引用的关系（指针则可以随时改变所指的对象）。
// 引用的主要功能是传递函数的参数和返回值。
//C++ 语言中，函数的参数和返回值的传递方式有三种：值传递、指针传递和引用传递。
//
//会发现"引用传递"的性质象"指针传递"，而书写方式象"值传递"。
//实际上"引用"可以做的任何事情"指针"也都能够做，为什么还要"引用"这东西？
//答案是"用适当的工具做恰如其分的工作"。
//指针能够毫无约束地操作内存中的任何东西，尽管指针功能强大，但是非常危险。
void InitList(SeqList &L) {
    L.data = new int[InitSize]; // init with C++
    L.MaxSize = InitSize;
    L.length = 0;
}

void InitList(SeqList *L) {
//    (*L).data = (int *) malloc(sizeof(ElemType) * InitSize); // init in C style
    L->data = (int *) malloc(sizeof(ElemType) * InitSize); // init in C style
//    (*L).MaxSize = InitSize;
    L->MaxSize = InitSize;
//    (*L).length = 0;
    L->length = 0;
}