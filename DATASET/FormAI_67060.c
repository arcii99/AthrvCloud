//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int id;
    int var1;
    char var2;
} thread_data;

void* thread_func(void* arg) {
    thread_data* data = (thread_data*) arg;
    printf("Thread ID: %d, Var1: %d, Var2: %c\n", data->id, data->var1, data->var2);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data* data[NUM_THREADS];

    // Initialize thread data
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i] = (thread_data*) malloc(sizeof(thread_data));
        data[i]->id = i;
        data[i]->var1 = i * 2;
        data[i]->var2 = 'A' + i;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, data[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
        free(data[i]);
    }

    return 0;
}