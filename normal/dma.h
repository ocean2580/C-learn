//
// 动态内存分配
//

#ifndef C_LEARN_DMA_H
#define C_LEARN_DMA_H

#endif //C_LEARN_DMA_H
#include<stdio.h>
#include<stdlib.h>
int dma() {
    int * p = (int *)malloc(sizeof(int));
    *p = 128;
    printf("%d", *p);

    free(p);   //使用free函数对内存空间进行释放，归还给系统，这样这段内存又可以被系统分配给别人用了
    p = NULL;   //指针也不能再指向那个地址了，因为它已经被释放了
}