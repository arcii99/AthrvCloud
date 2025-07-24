//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 1000000;
    int* arr = (int*)malloc(size * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }

    clock_t t1, t2;
    t1 = clock();

    // perform sorting algorithm here
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    t2 = clock();
    float diff = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", diff);

    free(arr);
    return 0;
}