//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>

void bucketSort(float arr[], int n) {
    // Create an array of buckets
    float bucket[n];
     
    // Initialize all buckets to 0.0
    for(int i=0; i < n; i++) {
        bucket[i] = 0.0;
    }
     
    // Fill the buckets with frequencies
    for(int i=0; i < n; i++) {
        int index = arr[i] * n;
        bucket[index]++;
    }
     
    // Sort individual buckets
    for(int i=0; i < n; i++) {
        int num = bucket[i];
        float temp[num];
        for(int j=0; j < num; j++) {
            temp[j] = i / (float) n;
        }
        printf("Bucket %d: ", i);
        for(int j=0; j < num; j++) {
            printf("%.2f ", temp[j]);
        }
        printf("\n");
    }
}
 
int main() {
    float arr[] = {0.23, 0.87, 0.98, 0.12, 0.44, 0.61, 0.23};
    int n = sizeof(arr)/sizeof(float);
     
    printf("Original Array: ");
    for(int i=0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
     
    bucketSort(arr, n);
     
    return 0;
}