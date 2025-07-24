//FormAI DATASET v1.0 Category: Sorting ; Style: Linus Torvalds
#include <stdio.h>

int main(void) {
    int arr[] = {5, 0, 2, 7, 4, 1, 3, 9, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j, temp;

    printf("Before sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nSorting through bubble sort - because it's simple, like me!");

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nAfter sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}