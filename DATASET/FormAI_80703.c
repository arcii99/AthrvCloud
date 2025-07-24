//FormAI DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1, 3, 5, 9, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j, temp;

    printf("Unsorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}