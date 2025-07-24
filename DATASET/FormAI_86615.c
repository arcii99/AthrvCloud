//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5
#define WORK_ITEMS 10

int workQueue[WORK_ITEMS];
int queueIndex = -1;

pthread_mutex_t lock; // Used to protect updates to queueIndex

void* worker(void* threadId) {
    int id = *(int*) threadId;
    int workItem;

    while (1) {
        pthread_mutex_lock(&lock); // Acquire the lock before accessing shared variable
        if (queueIndex == -1) { // Queue is empty
            printf("Thread %d is waiting for tasks\n", id);
            pthread_mutex_unlock(&lock);
            continue;
        }
        workItem = workQueue[queueIndex];
        queueIndex--;
        pthread_mutex_unlock(&lock); // Release the lock after accessing shared variable
        printf("Thread %d is processing task %d\n", id, workItem);
        sleep(1);
    }
}

int main() {
    int i, j, ids[THREADS];
    pthread_t threads[THREADS];

    for (i = 0; i < WORK_ITEMS; i++) {
        workQueue[i] = i + 1; // Populate the work queue
    }
    queueIndex = WORK_ITEMS - 1;

    pthread_mutex_init(&lock, NULL); // Initialize the mutex lock

    for (i = 0; i < THREADS; i++) {
        ids[i] = i + 1; // Assign each thread a unique ID
        if (pthread_create(&threads[i], NULL, worker, (void*) &ids[i])) {
            perror("Error creating thread");
            exit(1);
        }
    }

    for (i = 0; i < THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("Error joining thread");
            exit(1);
        }
    }

    pthread_mutex_destroy(&lock); // Destroy the mutex lock

    return 0;
}