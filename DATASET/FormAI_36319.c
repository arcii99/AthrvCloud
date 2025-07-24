//FormAI DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10000;
    int array1[size];
    int array2[size];
    int i, j;
    srand(time(NULL));
    // Fill arrays with random values
    for (i = 0; i < size; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }
    int sum = 0;
    clock_t start1 = clock();
    for (i = 0; i < size; i++) {
        sum += (array1[i] + array2[i]);
    }
    printf("Sum of corresponding elements of two arrays: %d\n", sum);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Time taken by first loop: %.8f\n", time1);

    int product = 1;
    clock_t start2 = clock();
    for (i = 0, j = size-1; i < size; i++, j--) {
        product *= (array1[i] * array2[j]);
    }
    printf("Product of corresponding elements of two arrays: %d\n", product);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("Time taken by second loop: %.8f\n", time2);
    return 0;
}