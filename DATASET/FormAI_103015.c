//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
    int id;
    char* message;
} ThreadData;

void* thread_action(void* data) {
    ThreadData* thread_data = (ThreadData*) data;
    printf("Hello from thread #%d: %s\n", thread_data->id, thread_data->message);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data_arr[NUM_THREADS];
    int i;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        ThreadData* thread_data = &thread_data_arr[i];
        thread_data->id = i;
        if (i % 2 == 0) {
            // Even threads
            thread_data->message = "I'm feeling lucky today!";
        } else {
            // Odd threads
            thread_data->message = "I've got a good feeling about this.";
        }
        pthread_create(&threads[i], NULL, thread_action, (void*) thread_data);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished executing. Goodbye!\n");
    return 0;
}