//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h> 
#include <stdlib.h> 

/* Define the C bucket sort function */
void bucketSort(int arr[], int n, int bucketSize) 
{ 
    int i, j; 
    int minVal = arr[0]; 
    int maxVal = arr[0]; 
    int bucketCount; 
    int **buckets; 
    
  // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) { 
        if (arr[i] < minVal) minVal = arr[i]; 
        else if (arr[i] > maxVal) maxVal = arr[i]; 
    } 

   // Calculate the number of buckets needed
    bucketCount = (maxVal - minVal) / bucketSize + 1;

   // Allocate memory for the buckets
    buckets = (int**)malloc(bucketCount * sizeof(int*)); 
    for (i = 0; i < bucketCount; i++) { 
        buckets[i] = (int*)malloc(bucketSize * sizeof(int)); 
    } 

  // Initialize each bucket to zero
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSize; j++) {
            buckets[i][j] = 0; 
        }
    }

   // Fill the buckets with the corresponding elements of the array
    for (i = 0; i < n; i++) { 
        int bucketIndex = (arr[i] - minVal) / bucketSize; 
        for (j = 0; j < bucketSize; j++) {
            if (buckets[bucketIndex][j] == 0) { 
                buckets[bucketIndex][j] = arr[i]; 
                break; 
            } 
        } 
    } 

   // Sort each bucket and merge them into the final sorted array
    int k = 0; 
    for (i = 0; i < bucketCount; i++) { 
        for (j = 0; j < bucketSize; j++) { 
            if (buckets[i][j] != 0) { 
                arr[k++] = buckets[i][j]; 
            } 
        } 
    } 

   // Free the memory used for the buckets
    for (i = 0; i < bucketCount; i++) { 
        free(buckets[i]); 
    } 
    free(buckets); 
} 

/* The main function to test the bucket sort */
int main() 
{ 
    int arr[] = { 23, 56, 97, 13, 34, 67, 20, 45, 87, 50 }; 
    int n = sizeof(arr) / sizeof(int); 
    int bucketSize = 10; 

  // Print the unsorted array
    printf("Unsorted array is: \n"); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }

  // Perform the bucket sort
    bucketSort(arr, n, bucketSize); 

    // Print the sorted array
    printf("\nSorted array is: \n"); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    return 0; 
}