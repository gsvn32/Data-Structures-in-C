#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cond;
int ready = 0;

void* threadFunc(void* arg) {
    pthread_mutex_lock(&lock);
    while (!ready) {
        pthread_cond_wait(&cond, &lock);
    }
    printf("Thread %d proceeding after condition met.\n", *(int*)arg);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
    
    pthread_create(&t1, NULL, threadFunc, &id1);
    pthread_create(&t2, NULL, threadFunc, &id2);
    
    sleep(1); // Simulate work
    pthread_mutex_lock(&lock);
    ready = 1;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&lock);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}
