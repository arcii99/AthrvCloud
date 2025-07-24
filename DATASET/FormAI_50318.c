//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 3
#define MAX_COUNT 10

sem_t sem_lock; // binary semaphore to lock critical section
int count = 0; // global variable to be incremented/decremented

void *increment_count(void *thread_id) {
    int id = *((int *)thread_id);
    while (1) {
        sem_wait(&sem_lock); // lock critical section
        if (count == MAX_COUNT) {
            sem_post(&sem_lock); // unlock critical section
            break; // exit loop
        }
        count++;
        printf("Thread %d incremented count to %d\n", id, count);
        sem_post(&sem_lock); // unlock critical section
    }
    pthread_exit(NULL);
}

void *decrement_count(void *thread_id) {
    int id = *((int *)thread_id);
    while (1) {
        sem_wait(&sem_lock); // lock critical section
        if (count == 0) {
            sem_post(&sem_lock); // unlock critical section
            break; // exit loop
        }
        count--;
        printf("Thread %d decremented count to %d\n", id, count);
        sem_post(&sem_lock); // unlock critical section
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {1, 2, 3};

    sem_init(&sem_lock, 0, 1); // initialize the binary semaphore to 1

    for (int i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, increment_count, (void *)&thread_ids[i]);
        } else {
            pthread_create(&threads[i], NULL, decrement_count, (void *)&thread_ids[i]);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_lock); // destroy the semaphore

    printf("Final count value is %d\n", count);

    return 0;
}