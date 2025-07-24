//FormAI DATASET v1.0 Category: Computer Biology ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define SIZE 100

int matrix[SIZE][SIZE];
int vector[SIZE];
int result[SIZE];
pthread_mutex_t lock;

void *vectorMult(void *arg) {
    int i, j, start, end, temp;
    long thread_id = (long)arg;
    int chunk_size = SIZE / NUM_THREADS;
    start = thread_id * chunk_size;
    if (thread_id == NUM_THREADS-1) {
        end = SIZE;
    } else {
        end = (thread_id+1) * chunk_size;
    }

    for (i = start; i < end; i++) {
        temp = 0;
        for (j = 0; j < SIZE; j++) {
            temp += matrix[i][j] * vector[j];
        }
        pthread_mutex_lock(&lock);
        result[i] = temp;
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(NULL);
}

int main() {
    int i, j;
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    // initialize matrices
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
        vector[i] = rand() % 10;
    }

    // create threads
    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_create(&threads[t], NULL, vectorMult, (void *)t);
    }

    // wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print result
    printf("Result vector:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);

    return 0;
}