//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
int counter = 0;

void *thread_function(void *args) {
    int thread_num = *((int*) args);
    printf("Thread %d started.\n", thread_num);
    
    for(int i=0; i<5; i++) {
        pthread_mutex_lock(&mutex);
        printf("Thread %d is incrementing the counter. Counter value: %d.\n", thread_num, ++counter);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    
    printf("Thread %d ended.\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    printf("Main thread started.\n");
    
    pthread_mutex_init(&mutex, NULL);
    
    int thread_num[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++) {
        thread_num[i] = i;
        if(pthread_create(&threads[i], NULL, thread_function, &thread_num[i])) {
            printf("Error: Creating thread %d failed.\n", i);
            exit(-1);
        }
    }
    
    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    
    printf("Main thread ended.\n");
    return 0;
}