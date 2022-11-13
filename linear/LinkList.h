//
// Created by Administrator on 2022/11/13.
//

#ifndef C_LEARN_LINKLIST_H
#define C_LEARN_LINKLIST_H

#endif //C_LEARN_LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initList(Node node){
    node->next = NULL;
}

_Bool insertList(Node head, E element, int index){
    if(index < 1) return 0;
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }

    Node node = malloc(sizeof(struct ListNode));
    if(node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

_Bool deleteList(Node head, int index){
    if(index < 1) return 0;   //大体和上面是一样的
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    if(head->next == NULL) return 0;

    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

E * getList(Node head, int index){
    if(index < 1) return 0;
    do {
        head = head->next;
        if(head == NULL) return 0;
    } while (--index);
    return &head->element;
}

int findList(Node head, E element){
    head = head->next;
    int i = 1;
    while (head) {
        if(head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeList(Node head){
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}