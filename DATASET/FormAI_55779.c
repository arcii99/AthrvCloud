//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: curious
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to be called by threading
void* say_hello(void* arg) {
    int count;
    for (count = 0; count < 10; count++) {
        printf("Hello from thread %d \n", *(int*)arg);
        sleep(1); // Sleep for 1 second
    }
}

int main() {
    pthread_t* threads;
    int num_threads = 5;
    int* thread_nums = malloc(sizeof(int) * num_threads);

    for (int i = 0; i < num_threads; i++) {
        thread_nums[i] = i; // Assign a unique thread number
        pthread_create(&threads[i], NULL, say_hello, &thread_nums[i]); // Create a new thread
    }

    // Join all threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(thread_nums);

    return 0;
}