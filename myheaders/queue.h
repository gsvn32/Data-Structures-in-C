#ifndef Q_H
#define Q_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);

#endif // Q_H
