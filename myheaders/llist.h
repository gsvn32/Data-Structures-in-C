#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data);
void printList(Node *head);

#endif // LLIST_H
