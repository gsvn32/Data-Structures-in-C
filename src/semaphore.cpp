#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5

sem_t semaphore;

void* threadFunc(void* arg) {
    sem_wait(&semaphore);
    printf("Thread %d has entered the critical section.\n", *(int*)arg);
    sleep(1); // Simulate work
    printf("Thread %d is leaving the critical section.\n", *(int*)arg);
    sem_post(&semaphore);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    
    sem_init(&semaphore, 0, 1);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunc, &ids[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore);
    return 0;
}
