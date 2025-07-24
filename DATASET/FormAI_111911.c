//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#define N 10

void bucketSort(int arr[], int n) {
    int bucket[3][N] = {0};
    int i, j, k;
    for (i = 0; i < n; i++) {
        int bi = 3 * arr[i] / (n + 1); 
        for (j = 0; j < N; j++) {
            if (bucket[bi][j] == 0) {
                bucket[bi][j] = arr[i];
                break;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        printf("Bucket[%d]: ", i);
        for (j = 0; j < N; j++) {
            if (bucket[i][j] != 0) {
                printf("%d ", bucket[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 0; i < 3; i++) {
        int ct = 0;
        for (j = 0; j < N; j++) {
            if (bucket[i][j] != 0) {
                arr[ct++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int arr[] = {3, 9, 1, 6, 8, 2, 5, 4, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}