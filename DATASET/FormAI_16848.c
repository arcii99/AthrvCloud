//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
    int tid = *((int*)thread_id);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        printf("Creating thread %d\n", i);
        int rc = pthread_create(&threads[i], NULL, print_hello, &thread_args[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have completed\n");
    pthread_exit(NULL);
}