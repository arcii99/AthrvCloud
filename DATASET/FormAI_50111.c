//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n, int k) {
    int i, j;
    int* b[k];
    for (i = 0; i < k; i++) {
        b[i] = (int*)malloc(n * sizeof(int));
    }
    for (i = 0; i < k; i++) {
        int bi = (int)(k * arr[i] / n);
        b[bi][i] = arr[i];
    }
    for (i = 0; i < k; i++) {
        insertionSort(b[i], n);
    }
    int index = 0;
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            if (b[i][j] != -1) {
                arr[index++] = b[i][j];
            }
        }
    }
    for (i = 0; i < k; i++) {
        free(b[i]);
    }
}

int main() {
    int arr[] = {24, 5, 67, 89, 12, 3, 6, 79, 40, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n, k);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}