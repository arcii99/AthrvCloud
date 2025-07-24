//FormAI DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>

#define MAXSIZE 100

void selectionSort(int arr[], int n);

int main() {
    int arr[MAXSIZE], n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers: \n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The unsorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nThe sorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}