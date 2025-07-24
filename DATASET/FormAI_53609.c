//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>

#define MAX_LENGTH 100

int main(void) {
    int arr[MAX_LENGTH];
    int n, i, j, temp;

    printf("Enter the length of the array (up to %d): ", MAX_LENGTH);
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort to sort the array in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap the two adjacent elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("The sorted array in descending order is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}