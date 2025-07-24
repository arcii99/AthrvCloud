//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate a random integer between min and max (inclusive)
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform quicksort partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform quicksort recursively
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Parallelize quicksort on left and right of pivot point
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quicksort(arr, low, pi - 1);
            }
            #pragma omp section
            {
                quicksort(arr, pi + 1, high);
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Seed random number generator
    srand(time(NULL));

    // Populate array with random integers between 0 and 99999
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = randomInt(0, 99999);
    }

    // Call quicksort on the array and time it
    clock_t start_time = clock();
    quicksort(arr, 0, ARRAY_SIZE - 1);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print execution time
    printf("Execution Time: %f seconds\n", elapsed_time);

    return 0;
}