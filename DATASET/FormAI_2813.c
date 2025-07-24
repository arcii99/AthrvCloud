//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#define MAX 100

void bucketSort(int arr[], int n) {
    int bucket[MAX];
    for (int i = 0; i < MAX; ++i) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++bucket[arr[i]];
    }
    for (int i = 0, j = 0; i < MAX; ++i) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            --bucket[i];
        }
    }
}

int main() {
    int arr[MAX];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("After sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}