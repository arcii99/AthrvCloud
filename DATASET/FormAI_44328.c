//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMER 2000 // Time in ms to execute the benchmarking loop

int main() {
    int i, j, k;
    clock_t start, end;
    double cpu_time_used;

    int arr1[1000000], arr2[1000000], arr3[1000000];

    // Generate random integers for the arrays
    srand(time(NULL));
    for (i=0; i<1000000; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    // Benchmarking loop for array addition
    printf("\nBenchmarking array addition...\n");
    start = clock();
    for (i=0; i<1000000; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    // Benchmarking loop for bubble sort
    printf("\nBenchmarking bubble sort...\n");
    start = clock();
    for (i=0; i<1000000; i++) {
        for (j=0; j<1000000-i-1; j++) {
            if (arr3[j] > arr3[j+1]) {
                k = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = k;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    // Benchmarking loop for matrix multiplication
    printf("\nBenchmarking matrix multiplication...\n");
    int mat1[100][100], mat2[100][100], res[100][100];

    // Generate random integers for the matrices
    srand(time(NULL));
    for (i=0; i<100; i++) {
        for (j=0; j<100; j++) {
            mat1[i][j] = rand() % 100;
            mat2[i][j] = rand() % 100;
        }
    }

    start = clock();
    for (i=0; i<100; i++) {
        for (j=0; j<100; j++) {
            res[i][j] = 0;
            for (k=0; k<100; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}