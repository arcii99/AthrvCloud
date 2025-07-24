//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Define constants
#define NUM_THREADS 4
#define BUFFER_SIZE 1024

// Declare global variables
double inputBuffer[NUM_THREADS][BUFFER_SIZE];
double outputBuffer[NUM_THREADS][BUFFER_SIZE];
double coefficients[] = {0.1, 0.2, 0.3, 0.2, 0.1};
int currentIndex = 0;

// Define thread argument struct
typedef struct {
    int tid;
    int start;
    int end;
} thread_arg;

// Define filter function
void filter(double* input, double* output) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        output[i] = 0;
        for (int j = 0; j < 5; j++) {
            int index = i - j;
            if (index < 0) {
                index = BUFFER_SIZE + index;
            }
            output[i] += coefficients[j] * input[index];
        }
    }
}

// Define thread function
void* thread_func(void* arg) {
    thread_arg* t = (thread_arg*) arg;
    int tid = t->tid;
    int start = t->start;
    int end = t->end;
    while (1) {
        if (currentIndex >= end) {
            break;
        }
        // Copy current buffer to local buffer
        double localInput[BUFFER_SIZE];
        for (int i = 0; i < BUFFER_SIZE; i++) {
            localInput[i] = inputBuffer[tid][i];
        }
        // Apply filter
        double localOutput[BUFFER_SIZE];
        filter(localInput, localOutput);
        // Copy local buffer to current output buffer
        for (int i = 0; i < BUFFER_SIZE; i++) {
            outputBuffer[tid][i] = localOutput[i];
        }
        // Move current index to next buffer
        currentIndex++;
        // Copy next buffer to current buffer
        if (currentIndex < end) {
            for (int i = 0; i < BUFFER_SIZE; i++) {
                inputBuffer[tid][i] = inputBuffer[tid + 1][i];
            }
        }
    }
    pthread_exit(NULL);
}

// Define main function
int main() {
    // Initialize input buffer
    for (int i = 0; i < NUM_THREADS; i++) {
        for (int j = 0; j < BUFFER_SIZE; j++) {
            inputBuffer[i][j] = (double) rand() / RAND_MAX;
        }
    }
    // Create threads
    pthread_t threads[NUM_THREADS];
    thread_arg args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].tid = i;
        args[i].start = i * (BUFFER_SIZE / NUM_THREADS);
        args[i].end = (i + 1) * (BUFFER_SIZE / NUM_THREADS);
        pthread_create(&threads[i], NULL, thread_func, (void*) &args[i]);
    }
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // Print output
    printf("Output buffer:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        for (int j = 0; j < BUFFER_SIZE; j++) {
            printf("%f ", outputBuffer[i][j]);
        }
        printf("\n");
    }
    return 0;
}