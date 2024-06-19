#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity);

void swap(int *a, int *b);

void heapifyUp(MinHeap *heap, int index);

void insert(MinHeap *heap, int value);

int extractMin(MinHeap *heap);

void heapifyDown(MinHeap *heap, int index);

#endif // HEAP_H
