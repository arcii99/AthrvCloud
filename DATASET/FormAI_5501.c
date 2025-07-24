//FormAI DATASET v1.0 Category: System boot optimizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int optimize_boot() {
    // Simulate boot optimization process
    printf("[Thread %ld] Boot optimization started...\n", pthread_self());
    sleep(rand() % 5 + 1);
    printf("[Thread %ld] Boot optimization completed!\n", pthread_self());
    return 0;
}

void* worker_thread(void* arg) {
    int* id_ptr = (int*) arg;
    printf("[Thread %d] Worker thread started...\n", *id_ptr);
    optimize_boot();
    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    // Start worker threads for boot optimization
    printf("System boot optimization started...\n");
    for (int i = 0; i < num_threads; ++i) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, worker_thread, &thread_ids[i]);
    }

    // Wait for worker threads to complete
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
        printf("[Thread %d] Worker thread exited.\n", i+1);
    }

    printf("System boot optimization completed!\n");
    return 0;
}