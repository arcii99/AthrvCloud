//FormAI DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *arr, int start, int end) {
    if(start >= end) {
        return;
    }
    int left = start;
    int right = end;
    int pivot_index = start + (end - start) / 2;
    int pivot = arr[pivot_index];
    while(left <= right) {
        while(arr[left] < pivot) {
            left++;
        }
        while(arr[right] > pivot) {
            right--;
        }
        if(left <= right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }
    quicksort(arr, start, right);
    quicksort(arr, left, end);
}

int main() {
    srand(time(NULL));
    int arr[100];
    for(int i=0; i<100; i++) {
        arr[i] = rand() % 1000;
    }
    printf("Unsorted array:\n");
    for(int i=0; i<100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quicksort(arr, 0, 99);
    printf("Sorted array:\n");
    for(int i=0; i<100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}