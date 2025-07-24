//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    char message[100];
} thread_args;

void* print_message(void* arg) {
    thread_args* args = (thread_args*) arg;
    printf("Thread %d says: %s\n", args->id, args->message);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    thread_args args[5];

    for (int i = 0; i < 5; i++) {
        args[i].id = i;
        sprintf(args[i].message, "Hello from thread %d!", i);

        int result = pthread_create(&threads[i], NULL, print_message, (void*) &args[i]);

        if (result != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 5; i++) {
        int result = pthread_join(threads[i], NULL);

        if (result != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("Main thread exiting.\n");

    return 0;
}