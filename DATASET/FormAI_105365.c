//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements (0-99):\n");

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int bucket[10][size];
    int count[10];

    for (i = 0; i < 10; ++i) {
        count[i] = 0;
    }

    for (i = 0; i < size; ++i) {
        int bucketIndex = arr[i] / 10;
        bucket[bucketIndex][count[bucketIndex]] = arr[i];
        ++count[bucketIndex];
    }

    int k = 0;
    for (i = 0; i < 10; ++i) {
        int j;
        for (j = 0; j < count[i]; ++j) {
            arr[k] = bucket[i][j];
            ++k;
        }
    }

    printf("\nSorted array: ");
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}