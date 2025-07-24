//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define THREADS 4 // Maximum number of threads
#define SIZE 100 // Size of the array

int arr[SIZE]; // Global array to search
int max[THREADS]; // Array to hold the maximum value found by each thread
int thread_id = 0; // Current thread ID

// Function for each thread to search for the maximum value in their portion of the array
void *find_max(void *arg) {
    int id = thread_id++;
    int start = id * (SIZE / THREADS);
    int end = (id == THREADS - 1) ? SIZE : (id + 1) * (SIZE / THREADS);
    int i, local_max = arr[start];
    for (i = start + 1; i < end; i++) {
        if (arr[i] > local_max) {
            local_max = arr[i];
        }
    }
    max[id] = local_max;
}

int main() {
    int i, result = 0;
    pthread_t threads[THREADS]; // Thread array
    srand(time(NULL)); // Seed the random generator
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000; // Fill the array with random values
    }
    for (i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, &find_max, NULL); // Create threads
    }
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL); // Wait for threads to finish
    }
    for (i = 0; i < THREADS; i++) {
        if (max[i] > result) {
            result = max[i]; // Find the maximum value from the local values found by each thread
        }
    }
    printf("The maximum value in the array is %d\n", result);
    return 0;
}