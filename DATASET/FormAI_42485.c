//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main() {

    // seed random number generator
    srand(time(NULL));

    // create integer array
    int* arr = (int*)malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed.");
        exit(1);
    }

    // initialize array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // calculate sum of array
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    // print sum
    printf("Sum of array: %d\n", sum);

    // free memory
    free(arr);

    return 0;
}