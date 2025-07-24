//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

void selectionSort(int arr[], int n);

int main() {
    int arr[5] = {5, 2, 4, 6, 1};
    selectionSort(arr, 5);

    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}