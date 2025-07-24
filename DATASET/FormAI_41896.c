//FormAI DATASET v1.0 Category: Benchmarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define MAX_RAND_NUM 10000

void generateArray(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_RAND_NUM;
    }
}

void printArray(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[ARRAY_SIZE];
    generateArray(arr);

    printf("----------Unsorted Array----------\n");
    printArray(arr);

    // CPU time benchmarking
    clock_t start = clock();
    qsort(arr, ARRAY_SIZE, sizeof(int), compare);
    clock_t end = clock();

    printf("----------Sorted Array----------\n");
    printArray(arr);
    printf("Time taken to sort the array: %f seconds.\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}