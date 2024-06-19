#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_barrier_t barrier;

void* threadFunc(void* arg) {
    printf("Thread %d waiting at the barrier.\n", *(int*)arg);
    pthread_barrier_wait(&barrier);
    printf("Thread %d passed the barrier.\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    
    pthread_barrier_init(&barrier, NULL, NUM_THREADS);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunc, &ids[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_barrier_destroy(&barrier);
    return 0;
}
