#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* threadFunc(void* arg) {
    pthread_mutex_lock(&lock);
    printf("Thread %d has entered the critical section.\n", *(int*)arg);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    
    pthread_mutex_init(&lock, NULL);
    
    pthread_create(&t1, NULL, threadFunc, &id1);
    pthread_create(&t2, NULL, threadFunc, &id2);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    pthread_mutex_destroy(&lock);
    return 0;
}
