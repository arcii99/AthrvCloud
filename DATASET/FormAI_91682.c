//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10

void *thread_func(void *thread_id)
{
    int id = *((int*)thread_id);
    printf("Thread %d is running\n", id);
    
    // Simulate an error occurring
    if (id == 3) {
        printf("An error has occurred in Thread %d\n", id);
        int *ptr = NULL;
        *ptr = 42; // This will cause a segmentation fault
    }
    
    printf("Thread %d is exiting\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    
    // Create the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, thread_func, (void*)&thread_ids[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
        }
    }
    
    // Join the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining thread %d\n", i);
        }
    }
    
    printf("All threads have exited successfully\n");
    return 0;
}