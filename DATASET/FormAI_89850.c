//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 1000000

int main()
{
    int array[NUM_ELEMENTS];

    // Populate array with random values between 1 and 100
    srand(time(NULL));
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        array[i] = rand() % 100 + 1;
    }

    // Bubble sort the array and measure time taken
    clock_t t1 = clock();
    for (int i = 0; i < NUM_ELEMENTS - 1; i++) {
        for (int j = 0; j < NUM_ELEMENTS - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    clock_t t2 = clock();

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print time taken to sort array
    printf("Bubble sort time taken: %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}