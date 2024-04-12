//
// Created by lWoHvYe on 2024/4/12.
//

#include "max_sub_sum.h"
#include "stdio.h"
#include "stdlib.h"

int max_sub_sum::MaxSubSum(int *Array, int left, int right) {
    int sum = 0;
    int i;
    if (left == right) {
        if (Array[left] > 0)
            sum = Array[left];
        else
            sum = 0;
    } else {
        int center = (left + right) >> 1;
        int leftSum = MaxSubSum(Array, left, center);
        int rightSum = MaxSubSum(Array, center + 1, right);

        // 下面是包含中点的
        int s1 = 0; // 向左的最大值
        int lefts = 0;
        for (i = center; i >= left; i--) {
            lefts += Array[i];
            if (lefts > s1)
                s1 = lefts;
        }

        int s2 = 0; // 向右的最大值
        int rights = 0;
        for (i = center + 1; i < right; i++) {
            rights += Array[i];
            if (rights > s2)
                s2 = rights;
        }

        sum = s1 + s2;
        if (sum < leftSum)
            sum = leftSum;
        if (sum < rightSum)
            sum = rightSum;
    }
    return sum;
}
