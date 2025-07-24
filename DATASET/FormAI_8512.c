//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define THRESHOLD 50000

int main() {
    int data[SIZE];
    int output[SIZE];
    int i, j, temp;
    clock_t start, end;
    double time_taken;

    // Populate the data array with random integers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        data[i] = rand();
    }

    // Start the timer
    start = clock();

    // Perform an insertion sort on the data array
    for (i = 1; i < SIZE; i++) {
        j = i;
        while (j > 0 && data[j] < data[j - 1]) {
            // Swap elements
            temp = data[j];
            data[j] = data[j - 1];
            data[j - 1] = temp;
            j--;
        }
    }

    // End the timer
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print out the sorted data
    printf("Sorted Data:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Check if the program ran faster than the threshold
    if (time_taken < THRESHOLD) {
        printf("Success: The program ran faster than the threshold time of %d seconds.\n", THRESHOLD);
    } else {
        printf("Error: The program did not run faster than the threshold time of %d seconds.\n", THRESHOLD);
    }

    return 0;
}