//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* allocate_memory(void* arg) {
    int* ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Error: could not allocate memory\n");
        pthread_exit(NULL);
    }
    printf("Memory allocated successfully\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int status;

    // Create a thread to allocate memory
    status = pthread_create(&thread, NULL, allocate_memory, NULL);
    if (status != 0) {
        printf("Error: pthread_create returned error code %d\n", status);
        exit(1);
    }

    // Wait for the thread to finish
    status = pthread_join(thread, NULL);
    if (status != 0) {
        printf("Error: pthread_join returned error code %d\n", status);
        exit(1);
    }
    
    printf("Thread finished successfully\n");
    return 0;
}