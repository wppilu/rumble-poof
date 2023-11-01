//
// Created by cracklu on 2023/10/29.
//
#include "stdio.h"
#include "math.h"

/**
 * 递归选择,但是无法保障有序.
 * @param N
 * @param array
 * @param K
 * @param k
 * @param index
 * @param s
 * @param sIndex
 * @return
 */
int select(int N, int array[], int K, int k, int index, int s[], int sIndex) {
    int count = 0;
    // n总长度,需要选择的长度,i 从数据之后选择. s为已选择数据.
    if (k == 0) {
        int v = 0;
        for (int i = 0; i < K; ++i) {
            v += array[s[i]];
        }
        // pa
        int sum = 0;
        int tmp = v;
        do {
            // 计算各位数 153%10 = 3 这里就是 3的3次方
            sum += array[tmp % 10];
            tmp = tmp / 10;
        } while (tmp > 0);
        if (sum == v) {
            printf("%d\n", v);
            return 1;
        }
        return 0;
    }
    // 选择对应的数.
    for (int i = 0; i <= k; i++) {
        // i=0;直接以为,
        if (index == 0 && i > K - 2) {
            continue;
        }
        if (i > 0) {
            s[sIndex + i - 1] = index;
        }
        if (index < N - 1) {
            count += select(N, array, K, k - i, index + 1, s, sIndex + i);
        }
    }
    if (index == N - 1) {
        // 当遍历完也需要输出
        count += select(N, array, K, 0, index + 1, s, sIndex + k);
    }
    return count;
}

/**
 * 使用递归实现可重复组合 .
 * @return
 */
int main() {
    int N;
    // 如果 N 等于3
    scanf("%d", &N);
    // 最小的位数 100
    int array[10];

    for (int i = 0; i < 10; ++i) {
        array[i] = pow(i, N);
    }

    // C103-> 900% AN! ->150
    // 进行组合运算,0 最多选择 N-1 个,其余 均假设为N 个
    int s[N];
    // 选择0的个数总0-N
    int count = select(10, array, N, N, 0, s, 0);
    printf("命中记录数%d", count);
}




