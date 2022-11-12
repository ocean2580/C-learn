//
// Created by Administrator on 2022/11/12.
//

#ifndef C_LEARN_HW_H
#define C_LEARN_HW_H

#endif //C_LEARN_HW_H
#include<stdio.h>
#define SIZE 5

void hw() {
    char a[SIZE];
    int p = 0, q = SIZE - 1;
    int result = 1;
    gets(a);
    while (p<q) {
        if (a[p++] == a[q--]) continue;
        else result = -1;
    }
    if (result == -1) printf("No");
    else printf("Yes");

    printf("\n");

}