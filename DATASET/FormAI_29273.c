//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
    long tid = (long) thread_id;
    printf("Hello World! This is thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    for (i = 0; i < NUM_THREADS; i++) {
        printf("In main: creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, print_hello, (void *) i);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    printf("In main: all threads created. Now joining...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Thread #%d joined.\n", i);
    }
    printf("Done!\n");
    pthread_exit(NULL);
}