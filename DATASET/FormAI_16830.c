//FormAI DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>

int main() {
    int arr[] = {5, 8, 1, 3, 9, 2, 6, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}