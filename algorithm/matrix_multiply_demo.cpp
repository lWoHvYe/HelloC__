//
// Created by lWoHvYe on 2024/4/7.
//

#include "matrix_multiply_demo.h"

#define N 100
int cost[N][N];
int trace[N][N];

int cmm(int n, int seq[]) {
    int i, j, k, p;
    int tempCost;
    int tempTrace;
    int temp;
    for (i = 0; i < n; i++) {
        cost[i][i] = 0;
    }
    for (p = 1; p < n; p++) { // p 矩阵相乘的规模
        for (i = 0; i < n - p; i++) { // i是单个的起始位置，j是单个的终点
            j = i + p;
            tempCost = -1;
            for (k = i; k < j; k++) { // k是分割点
                temp = cost[i][k] + cost[k + 1][j] + seq[i] * seq[k + 1] * seq[j + 1];
                if (tempCost == -1 | temp > tempCost) {
                    tempCost = temp;
                    tempTrace = k;
                }
            }
            trace[i][j] = tempTrace;
            cost[i][j] = tempCost;
        }
    }
    return cost[0][n - 1];
}