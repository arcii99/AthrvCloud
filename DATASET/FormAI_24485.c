//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numElements, i, j, tmp;

    printf("Enter number of elements to sort: ");
    scanf("%d", &numElements);

    int arr[numElements];

    // fill array with random values
    srand(time(NULL));
    for (i = 0; i < numElements; i++) {
        arr[i] = rand() % 10000;
    }

    printf("\nArray before sorting:\n");
    for (i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble Sort Algorithm
    clock_t begin = clock();
    for (i = 0; i < numElements - 1; i++) {
        for (j = 0; j < numElements - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    clock_t end = clock();

    printf("\n\nArray after sorting:\n");
    for (i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nBubble Sort Benchmark Results:\n");
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", numElements, time_spent);

    return 0;
}