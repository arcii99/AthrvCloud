//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
 
// Bucket sort function
void bucketSort(int arr[], int n) {
    
    // Create n empty buckets
    int bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    
    // Increment the count of the elements in their respective bucket
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
 
    // Sort the elements of the buckets and copy them back to the original array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[k++] = i;
        }
    }
}
 
// Main function
int main() {
    int arr[] = {19, 32, 12, 55, 75, 22, 94, 41, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}