//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_CHARS 1000

int charCount = 0;
char word[MAX_CHARS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* countWords(void* arg) {
    FILE* fp = arg;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        pthread_mutex_lock(&mutex);
        if (c == ' ' || c == '\n') {
            charCount++;
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    FILE* fp;
    pthread_t threads[MAX_THREADS];
    int i, rc;

    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, countWords, (void*) fp);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close file
    fclose(fp);

    printf("Total number of words in file: %d\n", charCount);

    return 0;
}