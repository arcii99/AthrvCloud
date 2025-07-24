//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>

void recursiveSort(int arr[], int n);

int main() {
    int arr[10] = {5, 3, 8, 9, 1, 7, 4, 6, 2, 0};
    printf("Unsorted Array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    recursiveSort(arr, 10);
    printf("Sorted Array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void recursiveSort(int arr[], int n) {
    if(n > 1) {
        int i, j, temp;
        for(i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        recursiveSort(arr, n - 1);
    }
}