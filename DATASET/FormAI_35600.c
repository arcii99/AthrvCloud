//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>

void swap(int *xp, int *yp) { //helper function to swap two elements
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {23, 56, 12, 89, 43, 76, 11, 9, 67, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("-----Bubble Sort-----\n");
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}