#ifndef PQ_H
#define PQ_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int priority;
    int data;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity);

void swap(Node *a, Node *b);

void heapifyUp(PriorityQueue *pq, int index);

void insert(PriorityQueue *pq, int data, int priority);

Node extractMin(PriorityQueue *pq);

void heapifyDown(PriorityQueue *pq, int index);

#endif // PQ_H