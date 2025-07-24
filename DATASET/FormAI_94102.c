//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    int start;
    int end;
    char** words;
    int* count;
} CountArg;

void* countWords(void* arg) {
    CountArg* countArg = (CountArg*) arg;
    int start = countArg->start;
    int end = countArg->end;
    char** words = countArg->words;
    int* count = countArg->count;

    // initialize count
    for (int i = start; i < end; i++) {
        count[i] = 0;
    }

    // count words
    for (int i = start; i < end; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            if (words[j] == NULL) {
                break;
            }
            if (strcmp(words[i], words[j]) == 0) {
                count[i]++;
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    char input[MAX_WORDS*MAX_WORD_LENGTH];
    char* words[MAX_WORDS];
    int count[MAX_WORDS] = {0};

    // get input string
    printf("Enter string: ");
    fgets(input, MAX_WORDS*MAX_WORD_LENGTH, stdin);

    // split input string into words
    char* word = strtok(input, " \n");
    int i = 0;
    while (word != NULL) {
        words[i] = word;
        i++;
        word = strtok(NULL, " \n");
    }

    // count words using threads
    pthread_t threads[MAX_THREADS];
    CountArg countArgs[MAX_THREADS];
    int numThreads = (i + MAX_THREADS - 1) / MAX_THREADS; // round up
    for (int t = 0; t < numThreads; t++) {
        int start = t * (i / numThreads);
        int end = (t == numThreads - 1) ? i : (t + 1) * (i / numThreads);
        countArgs[t].start = start;
        countArgs[t].end = end;
        countArgs[t].words = words;
        countArgs[t].count = count + start;
        pthread_create(&threads[t], NULL, countWords, (void*) &countArgs[t]);
    }
    for (int t = 0; t < numThreads; t++) {
        pthread_join(threads[t], NULL);
    }

    // print counts
    for (int j = 0; j < i; j++) {
        if (count[j] > 0) {
            printf("%s: %d\n", words[j], count[j]);
        }
    }

    return 0;
}