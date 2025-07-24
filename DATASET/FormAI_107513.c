//FormAI DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swapping the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int size, *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    //Allocating memory dynamically
    arr = (int *) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: unable to allocate memory\n");
        return -1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    //Sorting the array
    bubbleSort(arr, size);

    printf("Sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Freeing the dynamically allocated memory
    free(arr);

    return 0;
}