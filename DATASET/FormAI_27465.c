//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>

void bucketSort(float arr[], int n) {

    // Initialize counter array (buckets) with 0
    int i, bucket[10]={0};

    // Step 1: Count the number of elements in each bucket
    for(i=0; i<n; i++) {
        bucket[(int)(arr[i]*10)]++;
    }

    // Step 2: Sort the values in each bucket using insertion sort
    int index=0, j;
    for(i=0; i<10; i++) {
        for(j=0; j<bucket[i]; j++) {
            arr[index++] = i/10.0; // Convert the index back to the actual value
        }
    }
}

void printArray(float arr[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.42,0.32,0.25,0.02,0.11,0.79,0.1,0.1,0.62,0.62};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Input Array: ");
    printArray(arr,n);
    bucketSort(arr,n);
    printf("Sorted Array: ");
    printArray(arr,n);
    return 0;
}