//
// Created by cracklu on 2023/11/1.
//
#include <stdio.h>
#include <math.h>

int main() {
    double x;
    double i = 1, j = 1;
    double temp = 1;
    double sum = 1;//记得一定要定义初始值
    scanf("%lf", &x);

    for (i = 1; temp > 0.00001; i++) {
        j *= i;//阶乘分母
        temp = pow(x, i) / j;//中间值
        sum += temp;
    }

    printf("%.4lf", sum);
    return 0;
}