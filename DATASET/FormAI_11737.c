//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isSorted(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

void mysteriousSort(int arr[], int size) {
    printf("The puzzle begins... \n");
    while(!isSorted(arr, size)) {
        for(int i=0; i<size-1; i++) {
            if(arr[i] > arr[i+1]) {
                printf("Swapping elements %d and %d \n", arr[i], arr[i+1]);
                swap(&arr[i], &arr[i+1]);
            }
        }
    }
    printf("The puzzle is complete! The final sorted array is: ");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {5, 1, 8, 7, 3, 2, 6, 4, 9, 10};
    mysteriousSort(arr, 10);
    return 0;
}