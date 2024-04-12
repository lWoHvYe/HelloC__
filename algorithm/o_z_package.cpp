//
// Created by lWoHvYe on 2024/4/12.
//

#include <opencl-c.h>
#include "o_z_package.h"
#include "stdio.h"


void o_z_package::OneZeroPackage(int *v, int *w) {
    const int ROWS = 5;
    const int COLS = 6;
    int f[ROWS][COLS] = {}; // 子问题解数组

    int i, j;
    for (i = 1; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (j >= w[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    printf("%d\n", f[ROWS - 1][COLS - 1]);
}
