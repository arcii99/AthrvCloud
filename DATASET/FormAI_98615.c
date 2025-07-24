//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Define a struct to pass arguments to the thread functions
typedef struct {
    int thread_id; // ID of the thread
    int sleep_time; // Time to sleep for
} thread_args;

// Thread function 1 - prints "Hello World!"
void* thread_fcn_1(void* args) {
    thread_args* my_args = (thread_args*) args;
    printf("Thread %d says: Hello World!\n", my_args->thread_id);
    pthread_exit(NULL);
}

// Thread function 2 - prints "I am alive!" and sleeps for specified time
void* thread_fcn_2(void* args) {
    thread_args* my_args = (thread_args*) args;
    printf("Thread %d says: I am alive!\n", my_args->thread_id);
    sleep(my_args->sleep_time);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_args thread_args_arr[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args_arr[i].thread_id = i;
        thread_args_arr[i].sleep_time = i + 1;
        if (i % 2 == 0) {
            // Create thread using thread_fcn_1
            pthread_create(&threads[i], NULL, thread_fcn_1, (void*) &thread_args_arr[i]);
        } else {
            // Create thread using thread_fcn_2
            pthread_create(&threads[i], NULL, thread_fcn_2, (void*) &thread_args_arr[i]);
        }
    }

    // Wait for threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads have completed!\n");

    return 0;
}