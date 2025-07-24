//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 100
#define MAX_BUFFER_SIZE 10000
#define DELIMITERS ".,;:!? \n\t"

char inputBuffer[MAX_BUFFER_SIZE];
int wordCount = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *countWords(void *arg) {
    char *delimiter = (char*) arg;
    char *word = strtok(inputBuffer, delimiter);
    while (word != NULL) {
        pthread_mutex_lock(&mutex);
        wordCount++;
        pthread_mutex_unlock(&mutex);
        word = strtok(NULL, delimiter);
    }
    pthread_exit(NULL);
}

int main() {
    int numThreads;
    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a sentence or two: ");
    fgets(inputBuffer, MAX_BUFFER_SIZE, stdin);
    printf("Enter the number of threads to use: ");
    scanf("%d", &numThreads);

    // Split sentence by delimiters and count number of words
    pthread_t threads[MAX_THREADS];
    char *delimiter = strtok(DELIMITERS, "");
    while (delimiter != NULL) {
        pthread_create(&threads[numThreads], NULL, countWords, delimiter);
        delimiter = strtok(NULL, DELIMITERS);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Number of words: %d\n", wordCount);
    return 0;
}