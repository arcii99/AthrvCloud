//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *print_hello(void *thread_id) {
    long tid;
    tid = (long) thread_id;
    printf("Thread %ld: Hello World!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ret, i;
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        ret = pthread_create(&threads[i], NULL, print_hello, (void *) i);
        if (ret) {
            printf("Error: pthread_create() returned %d\n", ret);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}