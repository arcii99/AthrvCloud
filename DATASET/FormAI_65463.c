//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: minimalist
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
    int *thread_num = (int *)arg;
    sleep(1);
    printf("Thread %d is executing...\n", *thread_num);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    for(i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if(pthread_create(&threads[i], NULL, thread_func, (void *)&thread_args[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
    }
    
    for(i = 0; i < NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread\n");
            exit(1);
        }
    }

    printf("All threads have finished executing\n");
    return 0;
}