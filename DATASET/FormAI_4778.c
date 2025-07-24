//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100000

int main() {
    int i, j, k;
    double start_time, elapsed_time, total_time = 0;
    int arr[MAX_NUM];

    srand(time(NULL));

    printf("Mathematical-Style Benchmarking Program\n");
    printf("Generating %d random numbers...\n\n", MAX_NUM);

    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    printf("Sorting the array using bubble sort algorithm...\n");

    for (i = 0; i < MAX_NUM; i++) {
        start_time = (double) clock() / CLOCKS_PER_SEC;

        for (j = 0; j < MAX_NUM - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }

        elapsed_time = ((double) clock() / CLOCKS_PER_SEC) - start_time;
        total_time += elapsed_time;

        printf("Iteration %d: %.8f seconds\n", i+1, elapsed_time);
    }

    printf("\nTotal time taken for sorting %d numbers using bubble sort algorithm: %.8f seconds\n", MAX_NUM, total_time);

    return 0;
}