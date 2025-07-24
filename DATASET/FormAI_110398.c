//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n) {
    int i, j;
    int *count = calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        count[array[i]]++;
    }
    for (i = 0, j = 0; i < n; i++) {
        while (count[i]-- > 0) {
            array[j++] = i;
        }
    }
    free(count);
}

int main() {
    int array[] = {4, 2, 1, 3, 5};
    int n = sizeof(array) / sizeof(array[0]);
    bucketSort(array, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}