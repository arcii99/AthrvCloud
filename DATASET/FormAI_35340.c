//FormAI DATASET v1.0 Category: Benchmarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n = 100000000;
    double *arr = (double *) malloc(n * sizeof(double));

    if (arr == NULL) {
        printf("Memory allocation error!");
        return 1;
    }

    // fill array with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = ((double) rand() / RAND_MAX) * 100.0;
    }

    printf("Starting benchmark...\n\n");

    // sequential search benchmark
    printf("Sequential search benchmark:\n");
    clock_t start = clock();

    double key = arr[n / 2];
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    clock_t end = clock();
    double time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    if (index == -1) {
        printf("Key not found in array!");
    }
    else {
        printf("Key found at index %d.\n", index);
    }
    printf("Operation took %f seconds.\n\n", time_spent);

    // insertion sort benchmark
    printf("Insertion sort benchmark:\n");

    start = clock();

    for (int i = 1; i < n; i++) {
        double temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    end = clock();
    time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Array sorted in ascending order.\n");
    printf("Operation took %f seconds.\n\n", time_spent);

    // matrix multiplication benchmark
    printf("Matrix multiplication benchmark:\n");

    int size = sqrt(n);
    double **mat1 = (double **) malloc(size * sizeof(double *));
    double **mat2 = (double **) malloc(size * sizeof(double *));
    double **result = (double **) malloc(size * sizeof(double *));

    for (int i = 0; i < size; i++) {
        mat1[i] = (double *) malloc(size * sizeof(double));
        mat2[i] = (double *) malloc(size * sizeof(double));
        result[i] = (double *) malloc(size * sizeof(double));
    }

    // fill matrices with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat1[i][j] = ((double) rand() / RAND_MAX) * 10.0;
            mat2[i][j] = ((double) rand() / RAND_MAX) * 10.0;
            result[i][j] = 0.0;
        }
    }

    start = clock();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    end = clock();
    time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Matrix multiplication complete.\n");
    printf("Operation took %f seconds.\n\n", time_spent);

    // free memory
    for (int i = 0; i < size; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(result[i]);
    }
    free(mat1);
    free(mat2);
    free(result);

    free(arr);
    return 0;
}