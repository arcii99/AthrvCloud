//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 255

typedef struct {
    char* source;
    char* destination;
    int length;
    int done;
} CopyTask;

void* copyAsync(void* arg) {
    CopyTask* task = (CopyTask*) arg;
    int i;
    for (i = 0; i < task->length; i++) {
        task->destination[i] = task->source[i];
        usleep(10000);
    }
    task->done = 1;
    return NULL;
}

int main() {
    char source[BUFFER_SIZE];
    char destination[BUFFER_SIZE];
    int length;

    printf("Enter a string (max %d characters): ", BUFFER_SIZE);
    fgets(source, BUFFER_SIZE, stdin);
    length = strlen(source);
    if (length > 0 && source[length - 1] == '\n') {
        source[length - 1] = '\0';
        length--;
    }

    CopyTask task = {
        .source = source,
        .destination = destination,
        .length = length,
        .done = 0
    };

    pthread_t thread;
    if (pthread_create(&thread, NULL, copyAsync, &task) != 0) {
        printf("Failed to create thread\n");
        return EXIT_FAILURE;
    }

    while (!task.done) {
        printf("Copying...\n");
        usleep(500000);
    }
    printf("Copy done: %s\n", destination);

    return EXIT_SUCCESS;
}