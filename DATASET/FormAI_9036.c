//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_THREADS 10
#define MAX_ALLOCATION 1000
#define MIN_ALLOCATION 1

void *thread_function(void *arg);

pthread_mutex_t lock;

int allocations[MAX_THREADS];
int num_threads = 0;

int main()
{
    pthread_t thread_id[MAX_THREADS];
    int i, status;

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, (void *)i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread_id[i], (void **)&status);
    }

    printf("Thread allocation complete. Total allocations by all threads: %d\n", num_threads);

    pthread_mutex_destroy(&lock);

    return 0;
}

void *thread_function(void *arg)
{
    int my_number = (int)arg;
    int allocation_size, i;

    for (i = 0; i < 10; i++) {
        allocation_size = (rand() % MAX_ALLOCATION) + MIN_ALLOCATION;
        pthread_mutex_lock(&lock);
        allocations[my_number] += allocation_size;
        num_threads++;
        pthread_mutex_unlock(&lock);
        printf("Thread %d allocated %d bytes of memory\n", my_number, allocation_size);
    }

    pthread_exit(NULL);
}