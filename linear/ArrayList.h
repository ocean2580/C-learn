
// 顺序表底层是基于数组实现的，那么它肯定是支持随机访问的
#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct List {
    E * array;  // 底层数组
    int capacity;   // 容量
    int size;   // 当前数量
}*ArrayList;


_Bool initList(ArrayList list){
    list->array =  malloc(sizeof(E) * 10);
    if(list->array == NULL) return 0;   // 失败
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool insertList(ArrayList list, E element, int index){
    if(index < 1 || index > list->size + 1) return 0;   // 非法插入

    if(list->size == list->capacity) {  // 扩容
        int newCapacity = list->capacity + (list->capacity >> 1); // 1.5倍
        E * newArray = realloc(list->array, newCapacity * sizeof(E));   // 申请内存
        if(newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1; --i)
        list->array[i] = list->array[i - 1];    // 后移
    list->array[index - 1] = element;   // 插入
    list->size++;   // 数量
    return 1;
}

_Bool deleteList(ArrayList list, int index){
    if(index < 1 || index > list->size) return 0;   // 非法删除
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];    // 前移
    list->size--;   // 容量
    return 1;
}

int sizeList(ArrayList list){
    return list->size;
}

E * getList(ArrayList list, int index){
    if(index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

// 位序（ 1 开始）
int findList(ArrayList list, E element){
    for (int i = 0; i < list->size; ++i) {
        if(list->array[i] == element) return i + 1;
    }
    return -1;
}

void printList(ArrayList list){   //编写一个函数用于打印表当前的数据
    for (int i = 0; i < list->size; ++i)   //表里面每个元素都拿出来打印一次
        printf("%d ", list->array[i]);
    printf("\n");
}

void testArrayList() {
    ArrayList list;
    if (initList(list)) {
        for (int i = 0; i < sizeList(list); ++i) {
            insertList(list,i+1, i+1);
        }
    } else {
        printf("初始化失败!");
    }

    printf("insert:\n");
    printList(list);

    printf("delete:\n");
    deleteList(list,1);
    deleteList(list, 9);
    printList(list);

    printf("get:\n");
    E* e = getList(list, 2);
    printf("e = %d\n", *e);

    printf("find:\n");
    printf("index = %d\n", findList(list, 5));

}