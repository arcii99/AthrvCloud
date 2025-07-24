//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREADCOUNT 5

void *thread_function(void *thread_arg) {
    int thread_no = *((int *) thread_arg);
    printf("Thread %d starting...\n", thread_no);
    sleep(2);
    printf("Thread %d ending.\n", thread_no);
    return NULL;
}

int main() {
    pthread_t threads[THREADCOUNT];
    printf("Creating threads...\n");
    int i;
    for (i = 0; i < THREADCOUNT; i++) {
        int *thread_no = (int *) malloc(sizeof(int));
        *thread_no = i;
        if (pthread_create(&threads[i], NULL, thread_function, thread_no)) {
            printf("Error creating thread %d.\n", i);
            abort();
        }
    }
    printf("All threads created.\n");

    for (i = 0; i < THREADCOUNT; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d.\n", i);
            abort();
        }
    }
    printf("All threads joined.\n");

    return 0;
}