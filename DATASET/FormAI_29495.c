//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void brave_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The sorted array in a brave manner: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n, i;
    int arr[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The unsorted array in a cowardly manner: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    brave_sort(arr, n);
    printf("\n");
    return 0;
}