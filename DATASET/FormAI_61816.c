//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct that will hold information for a thread
typedef struct {
    int id;
    char *message;
} thread_info;

// Define the function that each thread will run
void *print_message(void *args) {
    thread_info *info = (thread_info *) args;
    printf("Thread %d says: %s\n", info->id, info->message);
    pthread_exit(NULL);
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    thread_info thread_info_arr[num_threads];

    // Create and run the threads
    for (int i = 0; i < num_threads; i++) {
        thread_info_arr[i].id = i;
        thread_info_arr[i].message = "Hello, world!";
        pthread_create(&threads[i], NULL, print_message, (void *) &thread_info_arr[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}