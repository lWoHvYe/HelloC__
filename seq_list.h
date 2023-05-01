//
// Created by lWoHvYe on 2023/4/17.
//

#ifndef HELLOC_HELLO_C_H
#define HELLOC_HELLO_C_H
#endif //HELLOC_HELLO_C_H
#define InitSize 100
typedef int ElemType;

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

void InitList(SeqList &L);

void InitList(SeqList *L);