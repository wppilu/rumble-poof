//
// Created by cracklu on 2023/11/1.
//
#include <sysinfoapi.h>
#include "stdio.h"
#include "math.h"


void calcNarcissus1(int N);

int main() {
    int N;
    // 如果 N 等于3
    scanf("%d", &N);
    long t1 = GetTickCount();
    calcNarcissus1(N);
    long t2 = GetTickCount();
    printf("time:%dms", t2 - t1);//前后之差即程序运行时间

}

void calcNarcissus1(int N) {// 计算0到9的值N次幂的大小避免重复计算.
    int array[10];
    for (int i = 0; i < 10; ++i) {
        array[i] = pow(i, N);
    }

    // 最小的位数 100
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
