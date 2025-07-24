//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// define a thread function
void* print_message(void* thread_arg) {
    char* message = (char*) thread_arg;
    printf("%s\n", message);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    char* messages[5] = {"Hello", "World", "From", "A", "Thread!"};

    int i;
    for (i = 0; i < 5; i++) {
        int thread_status = pthread_create(&threads[i], NULL, print_message, (void*) messages[i]);
        if (thread_status != 0) {
            printf("Error creating thread %d: %d\n", i, thread_status);
            exit(EXIT_FAILURE);
        }
    }

    // wait for all threads to finish
    for (i = 0; i < 5; i++) {
        int thread_status = pthread_join(threads[i], NULL);
        if (thread_status != 0) {
            printf("Error joining thread %d: %d\n", i, thread_status);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}