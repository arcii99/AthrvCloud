//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int arr[], int len) {
    int i, j, k;
    int min_val, max_val, bucket_count;
    int *bucket;
    min_val = max_val = arr[0];
    for (i = 1; i < len; i++) {
        min_val = (arr[i] < min_val) ? arr[i] : min_val;
        max_val = (arr[i] > max_val) ? arr[i] : max_val;
    }
    bucket_count = (max_val - min_val) / BUCKET_SIZE + 1;
    bucket = (int*) malloc(bucket_count * sizeof(int));
    for (i = 0; i < bucket_count; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < len; i++) {
        bucket[(arr[i] - min_val) / BUCKET_SIZE]++;
    }
    for (i = min_val, j = 0; i <= max_val; i += BUCKET_SIZE) {
        for (k = 0; k < bucket[(i - min_val) / BUCKET_SIZE]; k++) {
            arr[j++] = i;
        }
    }
    free(bucket);
}

int main() {
    int n, i;
    int arr[10] = {27, 45, 67, 98, 12, 2, 56, 78, 32, 44};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: \n");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    bucket_sort(arr, len);
    printf("\nArray after sorting: \n");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}