//
// Created by lWoHvYe on 2024/4/12.
//

#include "partial_package.h"

double answer[6];

double partial_package::Max_Value(int *v, int *w, double *vw) {
    double result = 0.0;
    int i;
    int W_temp = 10; // 背包容量
    for (i = 0; i <= 5; ++i) {
        if (W_temp >= w[i]) {
            answer[i] = 1.0;
            result += v[i];
            W_temp -= w[i];
        } else break;
    }
    if (W_temp > 0 && i <= 5) {
        answer[i] = (double) W_temp / w[i];
        result += (W_temp * vw[i]);
    }

    return result;
}
