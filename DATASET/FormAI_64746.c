//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg) {
    int *thread_num_ptr = (int *) arg;
    int my_thread_num = *thread_num_ptr;
    free(arg);

    printf("Hello from thread %d\n", my_thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i;
        int *arg = malloc(sizeof(int));
        *arg = i;

        if (pthread_create(&(threads[i]), NULL, thread_function, arg) != 0) {
            fprintf(stderr, "Failed to create thread %d", i);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Failed to join thread %d", i);
            return 1;
        }
    }

    printf("All threads joined successfully\n");

    pthread_exit(NULL);
    return 0;
}