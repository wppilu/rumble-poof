//
// Created by cracklu on 2023/11/1.
//

#include<stdio.h>

int main() {
    int i, j, k;
    int amount;
    scanf("%d", &amount);
    int count = 0;
    for (i = amount / 5; i >= 1; i--) {
        int remain = amount - i * 5;
        for (j = remain / 2; j >= 1; j--) {
            k = remain - j * 2;
            if (k >= 1) {
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, (i + j + k));
                count++;
            }
        }
    }
    printf("count = %d", count);
}