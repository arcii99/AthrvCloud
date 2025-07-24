//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int arr[10], i, j, temp;

    printf("Enter 10 integers: \n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted Array: \n");

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n\nSorted Array: \n");

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}