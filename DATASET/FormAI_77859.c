//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBERS 100
#define MAX_THREADS 4

int numbers[MAX_NUMBERS];

// Merge two sorted arrays
void merge(int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = numbers[start + i];
    for (j = 0; j < n2; j++)
        right[j] = numbers[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            numbers[k] = left[i];
            i++;
        }
        else {
            numbers[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numbers[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        numbers[k] = right[j];
        j++;
        k++;
    }
}

// Sort a sub-array recursively
void* sort(void* arg) {
    int* args = (int*) arg;
    int start = args[0];
    int end = args[1];

    if (start < end) {
        int mid = (start + end) / 2;

        // Sort left sub-array recursively
        int leftArgs[2] = { start, mid };
        sort(leftArgs);

        // Sort right sub-array recursively
        int rightArgs[2] = { mid + 1, end };
        sort(rightArgs);

        // Merge left and right sub-arrays
        merge(start, mid, end);
    }

    pthread_exit(NULL);
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];

    // Generate random numbers to sort
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 100;
    }

    // Create threads to sort sub-arrays
    int batchSize = MAX_NUMBERS / MAX_THREADS;
    for (i = 0; i < MAX_THREADS; i++) {
        int start = i * batchSize;
        int end = (i + 1) * batchSize - 1;
        int args[2] = { start, end };

        pthread_create(&threads[i], NULL, sort, (void*) args);
    }

    // Wait for threads to complete
    for (j = 0; j < MAX_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }

    // Merge final sub-arrays
    for (i = 1; i < MAX_THREADS; i++) {
        merge(0, i * batchSize - 1, (i + 1) * batchSize - 1);
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}