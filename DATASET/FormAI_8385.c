//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>

#define ARRAY_SIZE 10

void bucket_sort(int arr[], int n) {
    int i, j;
    int count[ARRAY_SIZE] = {0};

    for (i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    for (i = 0, j = 0; i < ARRAY_SIZE; ++i) {
        while (count[i]-- > 0) {
            arr[j++] = i;
        }
    }
}

int main() {
    int arr[] = {4, 7, 1, 0, 2, 9, 3, 5, 8, 6};
    int i;

    printf("Array before sorting: ");
    for (i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, ARRAY_SIZE);

    printf("\nArray after sorting: ");
    for (i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}