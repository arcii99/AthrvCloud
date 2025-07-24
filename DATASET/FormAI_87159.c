//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>

int main()
{
    int arr[10] = {4, 3, 6, 1, 8, 9, 2, 5, 7, 10};
    int temp;

    printf("Unsorted Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble Sort algorithm
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n\nSorted Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}