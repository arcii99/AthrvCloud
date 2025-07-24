//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_STRING_LENGTH 100

pthread_t tid[MAX_THREADS];
char string[MAX_STRING_LENGTH] = "Hello, World!";

void *threadFunction(void *arg) {
    int threadNum = *(int *)arg;

    long length = strlen(string);
    long chunkSize = length / MAX_THREADS;
    long start = threadNum * chunkSize;
    long end = (threadNum == MAX_THREADS - 1) ? length : (threadNum + 1) * chunkSize;

    for (int i = start; i < end; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32; // Convert uppercase letters to lowercase
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32; // Convert lowercase letters to uppercase
        }
    }

    pthread_exit(NULL);
}

int main() {
    int threadArgs[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        threadArgs[i] = i;
        pthread_create(&tid[i], NULL, threadFunction, &threadArgs[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Result: %s\n", string);
    return 0;
}