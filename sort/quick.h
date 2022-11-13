//
// Created by Administrator on 2022/11/13.
//

#ifndef C_LEARN_QUICK_H
#define C_LEARN_QUICK_H

#endif //C_LEARN_QUICK_H
#include <stdio.h>
#include <stdlib.h>
// (void *) 任意类型数据
int compare(const void * a, const void * b) {  //参数为两个待比较的元素，返回值负数表示a比b小，正数表示a比b大，0表示相等
    int * x = (int *) a, * y = (int *) b;   //这里因为判断的是int所以需要先强制类型转换为int *指针
    return *x - *y;   //其实直接返回a - b就完事了，因为如果a比b大的话算出来一定是正数，反之同理
}

int quick() {
    int arr[] = {5, 2, 4, 0, 7, 3, 8, 1, 9, 6};
    //工具库已经为我们提供好了快速排序的实现函数，直接用就完事
    //参数有点多，第一个是待排序数组，第二个是待排序的数量（一开始就是数组长度），第三个是元素大小，第四个是排序规则（我们提供函数实现）
    qsort(arr, 10, sizeof(int), compare);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
}