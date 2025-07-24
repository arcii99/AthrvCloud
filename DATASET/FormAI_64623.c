//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_hello(void* args) {
    printf("Hello, World!\n");
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    pthread_t thread;
    int status;

    status = pthread_create(&thread, NULL, print_hello, NULL);
    if (status != 0) {
        printf("Error creating thread.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);
    printf("Thread joined.\n");

    return EXIT_SUCCESS;
}