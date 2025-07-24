//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
// Welcome to the World of Threads!
// This C Threading Library allows you to create and manage threads in a simple and efficient manner.
// Let's demonstrate how with an imaginative scenario:

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// A struct to hold our thread information
typedef struct {
    int thread_id;
    char* thread_name;
    int* thread_count;
} ThreadInfo;

// Our thread function
void* thread_coolness(void* arg) {
    ThreadInfo* info = (ThreadInfo*)arg;
    printf("Hello from thread %d, %s!\n", info->thread_id, info->thread_name);
    printf("I have been called %d times.\n", *info->thread_count);
    (*info->thread_count)++;
    printf("Goodbye from thread %d, %s!\n", info->thread_id, info->thread_name);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int counts[NUM_THREADS] = {0, 0, 0, 0, 0};
    
    // Let's create 5 threads with distinct names
    ThreadInfo thread_info[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_info[i].thread_id = i;
        thread_info[i].thread_name = (i == 0) ? "Spartacus" :
                                     (i == 1) ? "Gladiator" :
                                     (i == 2) ? "Maximus" :
                                     (i == 3) ? "Hercules" : "Achilles";
        thread_info[i].thread_count = &(counts[i]);
        
        printf("Creating thread %d, %s.\n", thread_info[i].thread_id, thread_info[i].thread_name);
        int rc = pthread_create(&(threads[i]), NULL, thread_coolness, (void*)&(thread_info[i]));
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d.\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for all threads to finish before exiting
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have finished.\n");
    return 0;
}