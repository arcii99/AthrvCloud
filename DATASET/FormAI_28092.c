//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate random numbers between 1 to 100
int rand_num() {
    int num = (rand() % 100) + 1;
    return num;
}

// Function to perform Bubble Sort on an integer array
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int i, arr[ARRAY_SIZE];
    srand(time(0)); // Seed the random number generator

    // Generate random numbers for the array
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand_num();
    }

    // Call Bubble Sort function and measure time taken
    clock_t t;
    t = clock();
    bubble_sort(arr, ARRAY_SIZE);
    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    // Print sorted array and time taken to sort
    printf("Sorted Array:\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken to sort: %f seconds\n", time_taken);

    return 0;
}