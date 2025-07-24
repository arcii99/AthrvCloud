//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

int main(int argc, char** argv) {
    int arr[] = {42, 5, 27, 10, 18, 43, 32, 12, 35, 24};
    int size = sizeof(arr) / sizeof(arr[0]);

    // print initial array
    printf("Unsorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap values
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}