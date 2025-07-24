//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float arr[], int n) {
    // create n empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    // increment the count of elements in each bucket
    for (i = 0; i < n; i++) {
        int bucket = n * arr[i];
        count[bucket]++;
    }
 
    // sort the elements in each bucket using insertion sort
    for (i = 0; i < n; i++) {
        int bucket = n * arr[i];
        float temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
 
    // concatenate the sorted elements from each bucket
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = i / (float) n;
        }
    }
}

int main() {
    float arr[] = {0.9, 0.1, 0.5, 0.7, 0.3};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    bucket_sort(arr, n);
 
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.1f ", arr[i]);
    printf("\n");
 
    return 0;
}