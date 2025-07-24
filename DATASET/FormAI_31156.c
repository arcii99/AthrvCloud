//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SEQ_LENGTH 1000
#define NUM_THREADS 2

char nucleotides[] = {'A', 'C', 'G', 'T'};

char sequence[MAX_SEQ_LENGTH];
int threadComplete[NUM_THREADS] = {0};

void *geneticSequence(void *threadId) {
    int tid = *((int *) threadId);
    int start = MAX_SEQ_LENGTH / NUM_THREADS * tid;
    int end = MAX_SEQ_LENGTH / NUM_THREADS * (tid + 1);
    int i;
    for (i = start; i < end; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    threadComplete[tid] = 1;
    pthread_exit(NULL);
}

void printSequence() {
    int i;
    for (i = 0; i < MAX_SEQ_LENGTH; i++) {
        printf("%c", sequence[i]);
        if ((i+1) % 80 == 0) printf("\n"); // New line after every 80 characters
    }
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    srand((unsigned) time(NULL));

    printf("Generating genetic sequence...\n");

    for (i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, geneticSequence, (void *) &threadIds[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        while (!threadComplete[i]) { // Wait for all threads to complete
            // Do nothing
        }
        pthread_join(threads[i], NULL); // Clean up resources
    }

    printf("\nGenetic sequence generated:\n");
    printSequence();

    return 0;
}