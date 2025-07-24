//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define TRIALS 1000

int main() {
    int arr[SIZE];
    time_t t;

    // initialize array with random values
    srand((unsigned) time(&t));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    // perform selection sort
    clock_t start, end;
    double time_taken = 0;
    for (int i = 0; i < TRIALS; i++) {
        start = clock();
        for (int j = 0; j < SIZE-1; j++) {
            int min_index = j;
            for (int k = j+1; k < SIZE; k++) {
                if (arr[k] < arr[min_index]) {
                    min_index = k;
                }
            }
            if (min_index != j) {
                int temp = arr[j];
                arr[j] = arr[min_index];
                arr[min_index] = temp;
            }
        }
        end = clock();
        time_taken += (double) (end - start);
    }

    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Execution time taken: %lf seconds\n", time_taken/TRIALS/CLOCKS_PER_SEC);

    return 0;
}