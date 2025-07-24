//FormAI DATASET v1.0 Category: Sorting ; Style: Alan Touring
#include <stdio.h>

void sort_int_array(int arr[], int size) {
    int i, j, temp;

    // Bubble sort algorithm
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap adjacent elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[10] = {5, 3, 8, 2, 9, 1, 7, 4, 6, 0};
    int i;

    printf("Original array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    sort_int_array(arr, 10);

    printf("\nSorted array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}