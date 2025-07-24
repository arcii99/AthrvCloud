//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread argument structure
typedef struct {
    int thread_id;
    char *filename;
} ThreadArgs;

// Function to handle errors
void handle_error(char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

// Function to be executed by the threads
void *thread_function(void *arg) {
    ThreadArgs *args = (ThreadArgs *) arg;
    int thread_id = args->thread_id;
    char *filename = args->filename;

    FILE *file = fopen(filename, "r");
    if (!file) {
        char error_message[64];
        sprintf(error_message, "Thread %d: Could not open file %s", thread_id, filename);
        handle_error(error_message);
    }

    char line[128];
    while (fgets(line, 128, file)) {
        printf("Thread %d: %s", thread_id, line);
    }

    fclose(file);

    pthread_exit(NULL);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        handle_error("No filenames provided");
    }

    pthread_t threads[argc - 1];
    ThreadArgs thread_args[argc - 1];

    for (int i = 1; i < argc; i++) {
        thread_args[i-1].thread_id = i;
        thread_args[i-1].filename = argv[i];

        int result = pthread_create(&threads[i-1], NULL, thread_function, (void *) &thread_args[i-1]);
        if (result != 0) {
            char error_message[64];
            sprintf(error_message, "Could not create thread %d", i);
            handle_error(error_message);
        }
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}