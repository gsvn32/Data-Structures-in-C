#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data);

void insert(Node **root, int data);

void inorderTraversal(Node *root);

#endif // BTREE_H

