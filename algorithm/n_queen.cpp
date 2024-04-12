//
// Created by lWoHvYe on 2024/4/12.
//

#include "n_queen.h"
#include "math.h"
#include "stdio.h"

#define N 8;

int answer_count = 0;

int q[9]; // 皇后列号

void n_queen::recursion_queen(int n) {
    int i;
    for (i = 1; i <= 8; ++i) {
        q[n] = i; // 放在第几列
        if (check(n)) {
            if (n == 8) {
                answer_count++;
                for (i = 1; i <= 8; i++) {
                    printf("%d ", q[i]);
                }
                printf("\n");
            } else {
                recursion_queen(n + 1); // 摆放下一行
            }
        }
    }
}

bool n_queen::check(int j) {
    int i;
    for (i = 1; i < j; ++i) {
        if (q[i] == q[j] || abs(i - j) == abs(q[i] - q[j])) return false;
    }
    return true;
}

void n_queen::un_recur_queen() {
    int i;
    for (i = 0; i <= 8; ++i) {
        q[i] = 0;
    }
    int answer = 0;
    int n = 1; // 开摆第几个皇后
    while (n >= 1) {
        q[n] = q[n] + 1; // 后移一列

        while (q[n] <= 8 && !check(n)) q[n] = q[n] + 1;

        if (q[n] <= 8) {
            if (n == 8) {
                answer++;
                for (i = 1; i <= 8; i++) {
                    printf("%d ", q[i]);
                }
                printf("\n");
            } else ++n;
        } else {
            // 没法放，回溯
            q[n] = 0;
            --n;
        }
    }

}
