//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h> 
#include <stdlib.h> 

void bucketSort(float arr[], int n) { 
    // Create n buckets, initialize all buckets to empty 
    int i, j; 
    int count = 0;
    int maxBucketSize = 10; // Set maximum bucket size to be 10
  
    // Initialize all buckets
    float* buckets = (float*)calloc(n, sizeof(float)); 
  
    // Fill the buckets with the input array values
    for (i = 0; i < n; i++) {
        int bucketIndex = (int)arr[i] / maxBucketSize; // Find what bucket the current value belongs to
        buckets[bucketIndex] = arr[i];
    } 
  
    // Sort each bucket using insertion sort
    for (i = 0; i < n; i++) { 
        insertSort(buckets, i);
    } 
  
    // Combine all the sorted buckets into one sorted array
    for (i = 0; i < n; i++) { 
        if (buckets[i] != 0) {
            arr[count++] = buckets[i];
        }
    } 
} 
  
// Insertion Sort to sort the elements in the bucket
void insertSort(float arr[], int n) { 
    float temp = arr[n]; 
    int j = n - 1; 
  
    while (j >= 0 && arr[j] > temp) { 
        arr[j + 1] = arr[j]; 
        j--; 
    } 
    arr[j + 1] = temp; 
} 
  
// Test the implementation 
int main() { 
    float arr[] = { 0.42, 0.32, 0.23, 0.52, 0.25, 0.88, 0.16, 0.75 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int i; 
  
    printf("Input array: "); 
    for (i = 0; i < n; i++) {
        printf("%f ", arr[i]); 
    }
  
    bucketSort(arr, n); 
  
    printf("\n\nSorted array: "); 
    for (i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
  
    return 0; 
}