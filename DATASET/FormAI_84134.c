//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start_t, end_t;
    double total_t;

    start_t = clock();
    int* ptr = (int*) malloc(500000 * sizeof(int)); // allocate memory for array

    // check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < 500000; i++) {
        ptr[i] = rand() % 1000;
    }

    // sort array in ascending order
    for (int i = 0; i < 499999; i++) {
        for (int j = i + 1; j < 500000; j++) {
            if (ptr[i] > ptr[j]) {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }

    // print sorted array
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    end_t = clock();
    total_t = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f seconds\n", total_t);

    free(ptr); // free memory allocated to array
    return 0;
}