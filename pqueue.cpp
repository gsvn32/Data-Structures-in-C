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

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->nodes = (Node*)malloc(capacity * sizeof(Node));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    while (index != 0 && pq->nodes[index].priority < pq->nodes[(index - 1) / 2].priority) {
        swap(&pq->nodes[index], &pq->nodes[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void insert(PriorityQueue *pq, int data, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority queue overflow\n");
        return;
    }
    Node newNode = {priority, data};
    pq->nodes[pq->size] = newNode;
    heapifyUp(pq, pq->size);
    pq->size++;
}

Node extractMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority queue underflow\n");
        Node emptyNode = {0, 0};
        return emptyNode;
    }
    Node minNode = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return minNode;
}

void heapifyDown(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < pq->size && pq->nodes[left].priority < pq->nodes[smallest].priority)
        smallest = left;
    if (right < pq->size && pq->nodes[right].priority < pq->nodes[smallest].priority)
        smallest = right;
    if (smallest != index) {
        swap(&pq->nodes[index], &pq->nodes[smallest]);
        heapifyDown(pq, smallest);
    }
}

int main() {
    PriorityQueue *pq = createPriorityQueue(100);
    insert(pq, 10, 2);
    insert(pq, 20, 1);
    Node min = extractMin(pq);
    printf("Extracted min value: %d with priority: %d\n", min.data, min.priority);
    return 0;
}
