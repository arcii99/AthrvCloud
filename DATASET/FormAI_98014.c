//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n, int max_num) {
    int i, j;
    int *count = (int*)calloc(max_num, sizeof(int));
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    for (i = 0, j = 0; i < max_num; i++)
        for (; count[i] > 0; (count[i])--)
            arr[j++] = i;
    free(count);
}

int main() {
    int arr[] = {23, 56, 89, 12, 45, 67, 90, 11, 34, 55};
    int n = 10;
    int max_num = 91; // maximum number in array + 1
    int i;
    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n, max_num);
    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}