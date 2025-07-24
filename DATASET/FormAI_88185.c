//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time, end_time;
    double total_time;

    // Define a large array of integers for sorting
    int arr[1000000];

    // Populate the array with random values
    int i;
    srand(time(NULL));
    for (i = 0; i < 1000000; i++) {
        arr[i] = rand();
    }

    // Record the start time of the sorting operation
    start_time = clock();

    // Perform sorting on the array using bubble sort algorithm
    int j, temp;
    for (i = 0; i < 1000000 - 1; i++) {
        for (j = 0; j < 1000000 - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Record the end time of the sorting operation
    end_time = clock();

    // Calculate the total time taken for sorting
    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Display the sorted array and time taken for sorting
    printf("Sorted array:\n");
    for (i = 0; i < 1000000; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime taken for sorting: %f seconds\n", total_time);

    return 0;
}