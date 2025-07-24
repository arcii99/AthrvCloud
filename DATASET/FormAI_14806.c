//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_thread(void* thread_id) {
    int *id = (int*)thread_id;
    printf("Hello from thread %d!\n", *id);
    pthread_exit(NULL);
}

int main() {

    int num_threads = 5;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    printf("This program will create %d threads!\n", num_threads);

    for (int i = 0; i < num_threads; i++) {
        printf("Creating thread %d...\n", i);
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, print_thread, (void *)&thread_ids[i])) {
            printf("Error creating thread %d.\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d.\n", i);
            exit(-1);
        }
    }

    printf("All threads have completed successfully!\n");

    return 0;
}