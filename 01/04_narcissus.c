//
// Created by cracklu on 2023/10/29.
//
#include <sysinfoapi.h>
#include "stdio.h"
#include "math.h"


#define Size 4
typedef struct Table {
    int *head;
    int length;
    int size;
} table;

void initTable(struct Table *t) {
    t->head = (int *) malloc(Size * sizeof(int));
    if (!t->head) {
        printf("初始化失败");
        exit(0);
    }
    t->length = 0;
    t->size = Size;
}

void addTable(table *t, int elem) {
    if (t->length >= t->size) {
        t->head = (int *) realloc(t->head, (t->size + 1) * sizeof(int));
        if (!t->head) {
            printf("存储分配失败");
        }
        t->size += 1;
    }

    t->head[t->length] = elem;
    t->length++;
}

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
int select(struct Table *r, int N, const int array[], int K, int k, int index, int s[], int sIndex) {
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
            addTable(r, sum);
//            printf("%d\n", v);
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
            count += select(r, N, array, K, k - i, index + 1, s, sIndex + i);
        }
    }
    if (index == N - 1) {
        // 当遍历完也需要输出
        count += select(r, N, array, K, 0, index + 1, s, sIndex + k);
    }
    return count;
}

//直接插入排序函数
void InsertSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j = i - 1;
            int x = a[i];
            while (j > -1 && x < a[j]) {  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;      //插入到正确位置
        }
    }
}

void calcNarcissus2(int N) {// 最小的位数 100
    int array[10];

    for (int i = 0; i < 10; ++i) {
        array[i] = pow(i, N);
    }

    // C103-> 900% AN! ->150
    // 进行组合运算,0 最多选择 N-1 个,其余 均假设为N 个
    int s[N];
    // 选择0的个数总0-N
    struct Table t = {NULL, 0, 0};
    initTable(&t);
    int count = select(&t, 10, array, N, N, 0, s, 0);
    printf("count:%d\n", count);
    InsertSort(t.head, t.length);
    for (int i = 0; i < t.length; ++i) {
        printf("%d\n", t.head[i]);
    }
}

/**
 * 使用递归实现可重复组合 .
 * @return
 */
int main() {
    int N;
    // 如果 N 等于3
    scanf("%d", &N);
    long t1 = GetTickCount();
    calcNarcissus2(N);
    long t2 = GetTickCount();
    printf("time:%dms", t2 - t1);//前后之差即程序运行时间
}






