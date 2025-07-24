//FormAI DATASET v1.0 Category: Sorting ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void customSort(int arr[], int size) {
    int temp, i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    srand(time(NULL));
    
    printf("Unsorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    printArray(arr, SIZE);
    
    printf("\nSorting array using custom sort algorithm...\n");
    customSort(arr, SIZE);
    
    printf("\nSorted array:\n");
    printArray(arr, SIZE);
    
    return 0;
}