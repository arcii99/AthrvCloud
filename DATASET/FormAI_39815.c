//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void randomlyPopulateArray(int* arr, int size);
void selectionSort(int* arr, int size);

int main() {
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    randomlyPopulateArray(arr, ARRAY_SIZE);

    start = clock();
    selectionSort(arr, ARRAY_SIZE);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array in %f seconds.\n", cpu_time_used);
    return 0;
}

void randomlyPopulateArray(int* arr, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void selectionSort(int* arr, int size) {
    int i, j, minIndex, temp;

    for(i = 0; i < size-1; i++) {
        minIndex = i;
        for(j = i+1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}