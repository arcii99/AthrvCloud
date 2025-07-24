//FormAI DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>

/* This program sorts an array of integers in ascending order using the bubble sort algorithm */

void bubble_sort(int arr[], int n) {
    int i, j, tmp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {8, 2, 1, 9, 5};
    int n = sizeof(arr) / sizeof(int);
    int i;
    
    printf("Unsorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    bubble_sort(arr, n);
    
    printf("\nSorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}