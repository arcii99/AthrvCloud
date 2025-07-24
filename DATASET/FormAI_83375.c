//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
/* 
   Name: GeniusBucketSort.c
   Creator: [Your Name]
   Description: This program implements the Bucket Sort algorithm in a unique way. 
*/

#include <stdio.h>
#include <stdlib.h>

/* Function to print the array */
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to insert element in the bucket */
void insert(int *bucketArr, int element) {
    int i = element / 10; // Find the bucket index
    
    while(bucketArr[i] != -1) { // Loop until empty slot is found
        i++;
    }
    bucketArr[i] = element;//Insert element in selected bucket
}

/* Function to sort the elements in the bucket */
void sortBucket(int *bucketArr, int n) {
    int temp = 0;
    for(int i = 0; i < n; i++) { // Selection sorting for a bucket
        for(int j = i+1; j < n; j++) {
            if(bucketArr[i] > bucketArr[j]) {
                temp = bucketArr[i];
                bucketArr[i] = bucketArr[j];
                bucketArr[j] = temp;
            }
        }
    }
}

/* Function to perform Bucket Sort */
void bucketSort(int arr[], int n) {
    int maxVal = 100; // Assuming maximum element in the array is 100
    int bucketCount = (maxVal / 10) + 1; // Find the total number of buckets needed
    
    int bucketArr[bucketCount][n]; // Create the bucket array
    int bucketElementCount[bucketCount]; // Array to keep track of number of elements in each bucket
    
    for(int i =0; i < bucketCount; i++) {
        bucketElementCount[i] = 0; // Initialize number of elements in each bucket to 0
    }
    
    // Insert the elements of the array into their respective buckets
    for(int i = 0; i < n; i++) { 
        insert(bucketArr[arr[i]/10], arr[i]); 
        bucketElementCount[arr[i]/10]++;
    }
    
    // Sort the elements in each bucket 
    for(int i = 0; i < bucketCount; i++) { 
        sortBucket(bucketArr[i], bucketElementCount[i]); 
    }
    
    // Merge the elements from each bucket back into the array
    int index = 0;
    for(int i = 0; i < bucketCount; i++) { 
        for(int j = 0; j < bucketElementCount[i]; j++) {
            arr[index++] = bucketArr[i][j];
        }
    }
}

int main() {
    int arr[] = {23, 45, 12, 56, 89, 34, 78, 32, 57, 45, 100, 47}; // Sample array
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    printf("Original Array: ");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted Array: ");
    printArray(arr, n);
    
    return 0;
}