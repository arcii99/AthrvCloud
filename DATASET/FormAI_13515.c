//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5

// Struct to pass multiple arguments to the thread function
struct ThreadData {
    int thread_id;
    char* message;
};

void* print_message(void* thread_data) {
    struct ThreadData* data = (struct ThreadData*) thread_data;
    printf("Thread %d says: %s\n", data->thread_id, data->message);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData thread_data[NUM_THREADS];

    char* messages[NUM_THREADS] = {
        "Hey there!",
        "Howdy!",
        "What's up?",
        "Hello, world!",
        "Greetings!"
    };

    int i;
    for (i=0; i<NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        thread_data[i].thread_id = i;
        thread_data[i].message = messages[i];
        int rc = pthread_create(&threads[i], NULL, print_message, (void*) &thread_data[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish before exiting main
    for (i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d has finished\n", i);
    }

    pthread_exit(NULL);
}