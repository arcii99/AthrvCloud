//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Struct for holding the arguments passed to the threads
struct thread_args {
    int thread_id;
    int sleep_time;
};

// Function to be executed by each thread
void* thread_work(void* arg) {
    struct thread_args* args = (struct thread_args*)arg;
    printf("Thread %d sleeping for %d seconds...\n", args->thread_id, args->sleep_time);
    sleep(args->sleep_time);
    printf("Thread %d finished sleeping.\n", args->thread_id);
    return NULL;
}

int main(int argc, char** argv) {
    int num_threads = 5;
    pthread_t threads[num_threads];
    struct thread_args args[num_threads];

    // Create threads and pass arguments
    for (int i = 0; i < num_threads; i++) {
        args[i].thread_id = i;
        args[i].sleep_time = rand() % 5 + 1;
        printf("Creating thread %d with sleep time %d seconds...\n", args[i].thread_id, args[i].sleep_time);

        int thread_create_result = pthread_create(&threads[i], NULL, &thread_work, (void*)&args[i]);
        if (thread_create_result != 0) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        int thread_join_result = pthread_join(threads[i], NULL);
        if (thread_join_result != 0) {
            printf("Error joining thread %d\n", i);
            return 1;
        }
    }

    printf("All threads finished\n");
    return 0;
}