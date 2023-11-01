//
// Created by cracklu on 2023/11/1.
//
#include "stdio.h"
#include "math.h"


int main() {
    int N;
    // 如果 N 等于3
    scanf("%d", &N);
    // 最小的位数 100
    int array[10];

    for (int i = 0; i < 10; ++i) {
        array[i] = pow(i, N);
    }

    int a = pow(10, N - 1);
    // 最大的三位数 1000 -1
    int b = a * 10;
    // 100 +1 101 +2=  3;
    for (; a < b; a++) {
        int n = a;
        int sum = 0;
        // 列如当前数为 153
        // 153= 1 3 +5 3+3 3
        // 三位数
        do {
            // 计算各位数 153%10 = 3 这里就是 3的3次方
            sum += array[n % 10];
            n = n / 10;
        } while (n > 0);

        if (sum == a) {
            printf("%d\n", a);
        }
    }
}