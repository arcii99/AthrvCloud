//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 5

void *print(void *x) {
    int id = *((int*) x);
    printf("Thread %d is printing.\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NTHREADS];
    int ids[NTHREADS];

    for (int i = 0; i < NTHREADS; i++) {
        ids[i] = i+1;
        if (pthread_create(&threads[i], NULL, &print, &ids[i])) {
            printf("Error creating thread %d.\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NTHREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d.\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have finished!\n");
    return 0;
}