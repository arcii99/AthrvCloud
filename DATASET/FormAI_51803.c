//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 1024

char originalString[MAX_STRING_LENGTH] = "Hello World!";
char modifiedString[MAX_STRING_LENGTH] = "";

typedef struct {
    int start;
    int end;
} ThreadArgs;

void *reverseString(void *args) {
    ThreadArgs *targs = (ThreadArgs*) args;

    // Reverse the string
    int j = 0;
    for (int i = targs->end - 1; i >= targs->start; i--) {
        modifiedString[j++] = originalString[i];
    }

    pthread_exit(NULL);
}

int main() {
    int num_threads = 4;
    pthread_t threads[num_threads];

    // Divide the string into equal parts for each thread
    int part_size = MAX_STRING_LENGTH/num_threads;
    int remainder = MAX_STRING_LENGTH%num_threads;

    int start = 0, end = 0;
    ThreadArgs args[num_threads];

    // Create threads and assign tasks
    for (int i = 0; i < num_threads; i++) {
        if (remainder != 0) {
            end = start + part_size + 1;
            remainder--;
        } else {
            end = start + part_size;
        }
        args[i].start = start;
        args[i].end = end;

        pthread_create(&threads[i], NULL, reverseString, (void*) &args[i]);

        start = end;
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Original String: %s\n", originalString);
    printf("Modified String: %s\n", modifiedString);

    return 0;
}