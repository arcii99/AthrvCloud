//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_ITERATIONS 20

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int shared_resource = 0;

void *thread_func(void *id) {
    int thread_id = *(int*)id;
    srand(time(NULL));

    for (int i=0; i<MAX_ITERATIONS; i++) {
        
        int sleep_time = rand() % 3;
        sleep(sleep_time);
        
        pthread_mutex_lock(&mutex);
        
        shared_resource++;
        printf("Thread %d increased shared resource to %d.\n", thread_id, shared_resource);
        
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    int thread_ids[NUM_THREADS];
    
    for (int i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of the shared resource is %d.\n", shared_resource);

    return 0;
}