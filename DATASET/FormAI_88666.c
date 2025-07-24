//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024
#define NUM_THREADS 4

char buffer[MAX_BUFFER_SIZE];
int word_count = 0;

pthread_mutex_t lock;

void* count_words(void* rank) {
    long my_rank = (long) rank;
    int len = strlen(buffer);
    int start = my_rank * len / NUM_THREADS;
    int end = (my_rank + 1) * len / NUM_THREADS;

    while (start < end) {
        int count = 0;
        while (start < end && buffer[start] != ' ') {
            count++;
            start++;
        }

        if (count > 0) {
            pthread_mutex_lock(&lock);
            word_count++;
            pthread_mutex_unlock(&lock);
        }
        start++;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    printf("Enter a string: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    pthread_mutex_init(&lock, NULL);
    
    for (long thread = 0; thread < NUM_THREADS; thread++) {
        pthread_create(&threads[thread], NULL, count_words, (void*) thread);
    }
    
    for (long thread = 0; thread < NUM_THREADS; thread++) {
        pthread_join(threads[thread], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Word Count: %d", word_count);

    return 0;
}