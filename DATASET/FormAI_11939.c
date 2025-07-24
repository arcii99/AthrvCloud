//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void quicksort(int *arr, int left, int right) {
    int i = left, j = right;
    int temp, pivot = arr[(left + right) / 2];
 
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
 
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main() {
    int i, j;
    int array[ARRAY_SIZE];
    clock_t start, end;

    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
        array[i] = rand();

    printf("Before sorting:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");

    start = clock();
    quicksort(array, 0, ARRAY_SIZE - 1);
    end = clock();

    printf("After sorting:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");

    printf("Time taken: %f seconds", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}